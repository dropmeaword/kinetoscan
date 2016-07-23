#include "imu.h"

KinetoIMU::KinetoIMU() {
}

KinetoIMU::~KinetoIMU() {
}

void KinetoIMU::init() {
      //Wire.begin();
      my3IMU.init(); // the parameter enable or disable fast mode
      delay(5);
}

void serialFloatArray(float * arr, int length) {
  for(int i=0; i<length; i++) {
    //printHexFloat(arr[i]);
    Serial.print(arr[i]);
    Serial.print(",");
  }
}


void printHexFloat(float f) {
  byte * b = (byte *) &f;
  for(int i=0; i<4; i++) {
    
    byte b1 = (b[i] >> 4) & 0x0f;
    byte b2 = (b[i] & 0x0f);
    
    char c1 = (b1 < 10) ? ('0' + b1) : 'A' + b1 - 10;
    char c2 = (b2 < 10) ? ('0' + b2) : 'A' + b2 - 10;
    
    Serial.print(c1);
    Serial.print(c2);
  }
}

void KinetoIMU::update() {
  my3IMU.getQ(q);
  Serial.print("IMU,");
  serialFloatArray(q, 4);
  Serial.println("");
  /*
  my3IMU.getYawPitchRoll(ypr);
  Serial.print("IMU,");
  Serial.print(ypr[0]);
  Serial.print(",");
  Serial.print(ypr[1]);
  Serial.print(",");
  Serial.print(ypr[2]);
  Serial.print("\r\n");
  //Serial.println("");
  //Serial.flush();
  */
}

void KinetoIMU::print() {
}

