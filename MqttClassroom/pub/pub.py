import paho.mqtt.client as mqtt_client
import random
import time
import serial

broker = "broker.emqx.io"

client = mqtt_client.Client(f"lab_{random.randint(10000, 99999)}")
client.connect(broker)
# port
ser = serial.Serial("/dev/ttyACM0", timeout=1)
while True:
  data_bytes = ser.read(1)
  data = data_bytes.decode()
  client.publish("lab/dungeon/cv9t", data)
client.disconnect()