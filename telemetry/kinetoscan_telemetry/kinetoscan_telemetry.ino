#include "config.h"
#include "gps.h"
#include "imu.h"
#include <SimpleTimer.h>

KinetoIMU imu;

uint32_t timer = millis();

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
    imu.update();
    imu.print();

    gps_update();

  // print GPS status every 2000ms
  if (timer > millis())  timer = millis();

  if (millis() - timer > 2000) { 
    timer = millis();
    gps_print_latlon();
  }

//  if (millis() - timer > 4000) { 
//    timer = millis();
//    gps_print_quality();
//  }

}
