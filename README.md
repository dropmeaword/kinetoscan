## Portable kinetoscan

![scan](https://raw.githubusercontent.com/dropmeaword/kinetoscan/master/docs/motion-capture-1-960x540.jpg)

Image from [Asphyxia](http://weburbanist.com/2015/04/13/mesmerizing-motion-capture-dance-as-point-cloud-data/)


FreeIMU_serial (Arduino)  ==> FreeIMU_cube (P5)
// quaternion is passed
my3IMU.getQ(q);
serialPrintFloatArr(q, 4);
