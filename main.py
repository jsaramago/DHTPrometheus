#!/usr/bin/python

import os
import Adafruit_DHT
import time
from prometheus_client import start_http_server, Gauge, CollectorRegistry, push_to_gateway, REGISTRY


def get_sensor(sensor_string):
    if sensor_string == "DHT11":
        return Adafruit_DHT.DHT11
    elif sensor_string == "DHT22":
        return Adafruit_DHT.DHT22
    elif sensor_string == "AM2302":
        return Adafruit_DHT.AM2302
    else:
        raise Exception("Invalid sensor type (%s)" % sensor_string)


pushGatewayServer = os.environ.get('PUSH_GATEWAY_SERVER')
sensor = get_sensor(os.environ.get('SENSOR_TYPE'))
pin = int(os.environ.get('SENSOR_PIN', '4'))
httpPort = int(os.environ.get('HTTP_PORT', '8000'))
location = os.environ.get('LOCATION', '')

registry = REGISTRY
temperature_gauge = Gauge('temperature', 'Temperature', ['location'], registry=registry)
humidity_gauge = Gauge('humidity', 'Humidity', ['location'], registry=registry)

if __name__ == '__main__':
    # Start up the server to expose the metrics.
    start_http_server(httpPort)
    while True:
        time.sleep(2)
        humidity, temperature = Adafruit_DHT.read_retry(sensor, pin)

        temperature_gauge.labels(location).set(temperature)
        humidity_gauge.labels(location).set(humidity)

        if pushGatewayServer:
            push_to_gateway(pushGatewayServer, job='DTHPrometheus', registry=registry)



