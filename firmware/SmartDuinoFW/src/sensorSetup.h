#include <Arduino_APDS9960.h>
#include <Arduino_HTS221.h>
#include <Arduino_LSM9DS1.h>

#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif


/*
gesture data from the on-board APDS9960 sensor
*/
int setupAPDS9960();
int setupHTS221();
int setupSerialEcho();