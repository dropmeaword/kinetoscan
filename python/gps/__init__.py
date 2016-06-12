import pynmea2 as nmea
import logging
import serial
import time
import sys, os
import json

class GPS:
    def __init__(self, port, baudrate):
        logging.info("Opening GPS reader on {0} with data rate {1}".format(port, baudrate))

        try:
            self.device = serial.Serial(port, baudrate, timeout = 0)
            time.sleep(0.2)
            self.device.flush()
        except serial.SerialException:
            logging.error("(!!!) Couldn't open serial port, check that I have read access to {0}".format(port))
            sys.exit(1)

        # by default we do not create a GPX file
        self.nmealog = False

    def nmea_log(self, fn):
        self.nmealog = True
        self.nmeafilename = fn

    def nmea_to_dict(self, msg):
        retval = {
            'timestamp' : msg.timestamp.isoformat(),
            'lat' : msg.lat,
            'lat_dir' : msg.lat_dir,
            'lon' : msg.lon,
            'lon_dir' : msg.lon_dir,
            'gps_qual' : msg.gps_qual,
            'num_sats' : msg.num_sats,
            'horizontal_dil' : msg.horizontal_dil,
            'altitude' : msg.altitude,
            'altitude_units' : msg.altitude_units,
            'geo_sep' : msg.geo_sep,
            'geo_sep_units' : msg.geo_sep_units,
            'age_gps_data' : msg.age_gps_data,
            'ref_station_id' : msg.ref_station_id
        }
        return retval #json.dumps(retval)

    def close(self):
        if self.mqttc:
            self.mqttc.disconnect()

    def update(self):
        gpsmsg = None
        try:
            line = self.device.readline()
            #line = "$GPGGA,001933.799,,,,,0,0,,,M,,M,,*47"
            gpsmsg = nmea.parse( line ) # parse using library
            logging.debug("parsed entry {0}".format(line) )
            logging.debug("-> as: {0}".format(gpsmsg) )
        except nmea.ParseError:
            logging.warning("Failed to parse NMEA line: {0}".format(line))

        # from pprint import pprint
        # pprint( json.dumps(gpsmsg) )



        # broadcast parsed message on mqtt
        # if self.mqttc and gpsmsg:
        #     js = self.nmea_to_json(gpsmsg)
        #     self.mqttc.publish(MQTT_TOPIC, js)

        # save parsed line onto nmea file
        if self.nmealog:
            logging.debug("Writing GPS line to NMEA log {0}".format(self.nmeafilename))
            with open(self.nmeafilename, 'a+') as f:
                f.write(line)

        return self.nmea_to_dict( gpsmsg )
