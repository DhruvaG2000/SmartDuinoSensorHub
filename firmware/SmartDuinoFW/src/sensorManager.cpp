#include "sensorManager.h"

// OLED Display configuration
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);

int sensorSetup::setupIMU()
{
  if (!IMU.begin())
  {
    debuglogln("Failed to initialize IMU!");
    while (1)
      ;
  }
  debuglog("Accelerometer sample rate = ");
  debuglog(IMU.accelerationSampleRate());
  debuglogln(" Hz");
  debuglogln();
  debuglogln("Acceleration in g's");
  debuglogln("X\tY\tZ");
  debuglog("Gyroscope sample rate = ");
  debuglog(IMU.gyroscopeSampleRate());
  debuglogln(" Hz");
  debuglogln();
  debuglogln("Gyroscope in degrees/second");
  debuglogln("X\tY\tZ");
  return 0;
}

int sensorSetup::setupAirGesture()
{

  if (!IMU.begin())
  {
    debuglogln("Failed to initialize IMU!");
    while (1)
      ;
  }

  debuglog("Accelerometer sample rate = ");
  debuglog(IMU.accelerationSampleRate());
  debuglogln(" Hz");
  debuglogln();
  debuglogln("Acceleration in g's");
  debuglogln("X\tY\tZ");

  debuglogln("Started gyro");

  debuglog("Gyroscope sample rate = ");
  debuglog(IMU.gyroscopeSampleRate());
  debuglogln(" Hz");
  debuglogln();
  debuglogln("Gyroscope in degrees/second");
  debuglogln("X\tY\tZ");

  return 0;
}

int sensorSetup::setupHumidityTemperature()
{
  if (!HTS.begin())
  {
    debuglogln("Failed to initialize humidity temperature sensor!");
    while (1)
      ;
  }
  return 0;
}

#define U8LOG_WIDTH 20
#define U8LOG_HEIGHT 8
uint8_t u8log_buffer[U8LOG_WIDTH * U8LOG_HEIGHT];
U8G2LOG u8g2log;

int sensorSetup::setupSerialEcho()
{
  u8g2.begin();
  u8g2.setFont(u8g2_font_5x7_tr); // set the font for the terminal window
  u8g2log.begin(u8g2, U8LOG_WIDTH, U8LOG_HEIGHT, u8log_buffer);
  u8g2log.setLineHeightOffset(0); // set extra space between lines in pixel, this can be negative
  u8g2log.setRedrawMode(1);       // 0: Update screen with newline, 1: Update screen for every char
  return 0;
}

unsigned int sensorLoop::accelStateChangeFlag = 1;
unsigned int sensorLoop::gyroStateChangeFlag = 1;
unsigned int sensorLoop::accelMaxOptions = 4;
unsigned int sensorLoop::gyroMaxOptions = 2;

void sensorLoop::resetFlag()
{
  if (sensorLoop::gyroStateChangeFlag > sensorLoop::gyroMaxOptions)
    sensorLoop::gyroStateChangeFlag = 1;
  else if ((sensorLoop::gyroStateChangeFlag <= 0))
  {
    sensorLoop::gyroStateChangeFlag = gyroMaxOptions;
  }

  if (sensorLoop::accelStateChangeFlag > sensorLoop::accelMaxOptions)
    sensorLoop::accelStateChangeFlag = 1;
  else if (sensorLoop::accelStateChangeFlag <= 0)
  {
    sensorLoop::accelStateChangeFlag = sensorLoop::accelMaxOptions;
  }
}

int sensorLoop::loopSel()
{
  switch (sensorLoop::gyroStateChangeFlag)
  {
  case 1:
    debuglogln("\nMusic Player");
    sensorLoop::loopHumidityTemperature();
    /* code */
    break;
  case 2:
    debuglogln("\nHumidity n Temp");
    sensorLoop::loopHumidityTemperature();
    break;
  default:
    debuglogln("\n\n\nTO-DO\n\n\n");
    break;
  }
  return 0;
}

int sensorLoop::loopIMU_accel()
{
  float x, y, z, delta = 0.05;

  if (IMU.accelerationAvailable())
  {
    IMU.readAcceleration(x, y, z);
    if (y >= 1 - delta){
      debuglogln("left");
      sensorLoop::accelStateChangeFlag++;
      debuglogln("\naccFlag");
      debuglog(sensorLoop::accelStateChangeFlag);
      resetFlag();
      delay(1500);
    }
    else if (y <= delta - 1)
    {
      debuglogln("right");
      sensorLoop::accelStateChangeFlag--;
      debuglogln("\naccFlag");
      debuglog(sensorLoop::accelStateChangeFlag);
      resetFlag();
      delay(1500);
    }
  }
  delay(5);
  return 0;
}

int sensorLoop::loopIMU_gyro()
{
  float x, y, z, delta = 400;

  if (IMU.gyroscopeAvailable())
  {
    IMU.readGyroscope(x, y, z);

    if (y < -delta)
    {
      debuglogln("Flicked down");
      sensorLoop::gyroStateChangeFlag--;
      delay(1500);
    }
    else if (y > delta)
    {
      debuglogln("Flicked up");
      sensorLoop::gyroStateChangeFlag++;
      delay(1500);
    }
    debuglogln("\ngyroFlag");
    debuglog(sensorLoop::gyroStateChangeFlag);
    resetFlag();
  }
  delay(2);
  return 0;
}

int sensorLoop::loopAirGesture()
{
  return 0;
}

int sensorLoop::loopHumidityTemperature()
{
  return 0;
}

int sensorLoop::loopSerialEcho()
{
  return 0;
}