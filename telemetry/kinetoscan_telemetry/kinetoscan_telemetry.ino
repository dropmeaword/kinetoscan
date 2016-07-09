#include "config.h"
#include "gps.h"
#include "imu.h"

KinetoIMU imu;

uint32_t timer = millis();

void setup() {
  // external serial
  Serial.begin(EXT_BAUDRATE);
  
  // join I2C bus (I2Cdev library doesn't do this automatically)
  Wire.begin();
  delay(5);

  gps_init();
  gps_print_firmware();
  imu.init();
}

void loop() {
  imu.update();
  imu.print();
    
  delay(5);

  gps_update();

  // print GPS status every 2000ms
  if (timer > millis())  timer = millis();

  if (millis() - timer > 2000) { 
    timer = millis();
    gps_print();
  }
  
}
