#include <Arduino_APDS9960.h>
#include <Arduino_HTS221.h>
#include <Arduino_LSM9DS1.h>
#include <LPS35HW.h>

#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#define DEBUG 1

#if DEBUG == 1
#define debuglog(x) Serial.print(x)
#define debuglogln(x) Serial.println(x)
#else
#define debuglog(x)
#define debuglogln(x)
#endif

/*
gesture data from the on-board APDS9960 sensor
*/
class sensorSetup
{
public:
    static int setupIMU();
    static int setupAirGesture();
    static int setupHumidityTemperature();
    static int setupPressure();
    static int setupSerialEcho();
    static int setupAnalogMQ();
};

class sensorLoop
{
    static void resetFlag();
public:
    static unsigned int accelStateChangeFlag, gyroStateChangeFlag, accelMaxOptions, gyroMaxOptions, MQ_Pin, LED_BAR, LED_BAR_STATE;
    sensorLoop() {}
    static int loopSel();
    static int loopIMU_accel();
    static int loopIMU_gyro();
    static int loopAirGesture();
    static int loopHumidityTemperature();
    static int loopPressure();
    static int loopAnalogMQ();
    static int loopSerialEcho();
    ~sensorLoop() {}
};