## GPS toolkit

Assorted scripts to work with gps coordinates coming from the Grove GPS sensor.

#### Dependencies

These scripts need a bunch of dependencies that you can install by just
typing `pip install -r requirements.txt`.

#### Testing Mosquitto

You can test the mosquitto related functionality by using the test server provided by mosquitto here `test.mosquitto.org` on port `1883`, eventually the server will be running on the Rpi itself.

With the package `mosquitto-clients` installed you should be able to see any broadcast data by using the client like so `mosquitto_sub -h test.mosquitto.org -t "kinetoscan/#" -v`

 To run the GPS broadcast do ``./bcastgps --mqtt-host=test.mosquitto.org --mqtt-port=1883`
