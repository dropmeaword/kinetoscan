import paho.mqtt.client as mqtt
import logging
import os, sys

class MQTT:
    def __init__(self, uid):
        self.mqttc = None
        self.uid   = uid

    def on_connect(self, mosq, obj, rc):
        pass
        #logging.info("rc: "+str(rc))

    def on_message(self, mosq, obj, msg):
        pass
        #sticks[0].set_color(hex="#"+str(msg.payload))
        #logging.info(msg.topic+" "+str(msg.payload))

    def on_publish(self, mosq, obj, mid):
        pass
        #logging.info("mid: "+str(mid))

    def on_subscribe(self, mosq, obj, mid, granted_qos):
        pass
        #logging.info("Subscribed: "+str(mid)+" "+str(granted_qos))

    def on_log(self, mosq, obj, level, string):
        pass
        #logging.info(string)

    def connect(self, mqtthost, mqttport):
        if not self.uid:
            # generate a unique ID for this client
            thispid = os.getpid()
            self.uid = "kinetoscan_beta_"+str(thispid)

        logging.info("Mosquitto ID {0}".format(self.uid))
        self.mqttc = mqtt.Client( self.uid )
        self.mqttc.on_message = self.on_message
        self.mqttc.on_connect = self.on_connect
        self.mqttc.on_publish = self.on_publish
        self.mqttc.on_subscribe = self.on_subscribe
        logging.info("Connecting to mosquitto {0}:{1}".format(mqtthost, mqttport))
        self.mqttc.connect(mqtthost, mqttport, 60)
        #self.mqttc.subscribe(MQTT_TOPIC, 0)
