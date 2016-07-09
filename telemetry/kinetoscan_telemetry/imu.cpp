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

void KinetoIMU::update() {
      my3IMU.getYawPitchRoll(ypr);
}

void KinetoIMU::print() {
  Serial.print("IMU,");
  Serial.print(ypr[0]);
  Serial.print(",");
  Serial.print(ypr[1]);
  Serial.print(",");
  Serial.print(ypr[2]);
  Serial.println("");
}

