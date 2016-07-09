#include <ADXL345.h>
#include <bma180.h>
#include <HMC58X3.h>
#include <ITG3200.h>
#include <MS561101BA.h>
#include <I2Cdev.h>
#include <MPU60X0.h>
#include <EEPROM.h>

//#define DEBUG
#include "DebugUtils.h"
#include "CommunicationUtils.h"
#include "FreeIMU.h"
#include <Wire.h>
#include <SPI.h>

class KinetoIMU {
  public:
    int raw_values[9];
    //char str[512];
    float ypr[3]; // yaw pitch roll
    float val[9];
    
    // Set the FreeIMU object
    FreeIMU my3IMU = FreeIMU();

    KinetoIMU();
    ~KinetoIMU();
    
    void init();
    void update();
};

