#!/usr/bin/python


import Adafruit_DHT
import time
from prometheus_client import start_http_server, Gauge

sensor = Adafruit_DHT.AM2302
pin = 4


temperature_gauge = Gauge('temperature', 'Temperature')
humidity_gauge = Gauge('humidity', 'Humidity')




if __name__ == '__main__':
    # Start up the server to expose the metrics.
    start_http_server(8000)
    # Generate some requests.
    while True:
        time.sleep(2)
        humidity, temperature = Adafruit_DHT.read_retry(sensor, pin)
        temperature_gauge.set(temperature)
        humidity_gauge.set(humidity)
