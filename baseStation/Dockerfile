FROM python:3-stretch

RUN apt update
RUN apt install -y build-essential && pip3 install Adafruit_Python_DHT prometheus_client
RUN apt upgrade -y

COPY main.py /root/main.py

EXPOSE 8000

ENTRYPOINT python /root/main.py


