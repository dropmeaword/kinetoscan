#include "config.h"
#include "gps.h"
#include "imu.h"
#include "SimpleTimer.h"

KinetoIMU imu;
char cmd;
SimpleTimer t1, t2;

//uint32_t timer = millis();

void setup() {
  // external serial
  Serial.begin(EXT_BAUDRATE);
  
  // join I2C bus (I2Cdev library doesn't do this automatically)
  Wire.begin();
  delay(5);

  gps_init();
  //gps_print_firmware();
  delay(5);
  imu.init();
  delay(5);

  t1.setInterval(2000, gps_print_latlon);
  t2.setInterval(4000, gps_print_quality);
}

// why does the imu read nan?
//
// set GPSECHO to false (doesnt work)
// not printing gps status (doesn't work)
// update gps before imu (doesnt work)
// not updating gps at all (imu works fine)
// updating and printing imu at bottom of the loop after delay
// flush serial before reading imu (not)
// commenting out gps_print (!works)
// serial.flush on gps_print (no)
//
// seems that pumping too much data through serial on gps 
// output is too slow and interferes with the reading of the imu
// seems like it could be a memory corruption from the interrrupt?
void loop() {
//    imu.update();
//    imu.print();

    serialPump();

    gps_update();

    t1.run();
    t2.run();
}

char serial_busy_wait() {
  while(!Serial.available()) {
    ; // do nothing until ready
  }
  return Serial.read();
}

void serialPump() {
    if(Serial.available()) {
    cmd = Serial.read();
      if(cmd == 'q') {
        uint8_t count = serial_busy_wait();
        for(uint8_t i=0; i<count; i++) {
          imu.update();
          imu.print();
        }
      } // if
    } //if
} // serialPump

