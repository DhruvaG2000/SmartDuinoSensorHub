#include "sensorManager.h"

// OLED Display configuration
// U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);
#define U8LOG_WIDTH 20
#define U8LOG_HEIGHT 8
uint8_t u8log_buffer[U8LOG_WIDTH * U8LOG_HEIGHT];
U8G2LOG u8g2log;

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
  u8g2.begin();
  Serial.begin(9600);

  // while (!Serial);

  if (!APDS.begin())
  {
    debuglogln("Error initializing APDS9960 sensor!");
  }

  // for setGestureSensitivity(..) a value between 1 and 100 is required.
  // Higher values makes the gesture recognition more sensible but less accurate
  // (a wrong gesture may be detected). Lower values makes the gesture recognition
  // more accurate but less sensible (some gestures may be missed).
  // Default is 80
  //APDS.setGestureSensitivity(80);

  debuglogln("Detecting gestures ...");

  do
  {
    u8g2.setFont(u8g2_font_ncenB14_tr);
    u8g2.drawStr(0, 24, "Detecting ");
    u8g2.drawStr(0, 48, "gestures ...");
  } while (u8g2.nextPage());

  return 0;
}

int sensorSetup::setupHumidityTemperature()
{
  u8g2.begin();
  Serial.begin(9600);
  debuglogln("DHT Serial Started");
  if (!HTS.begin())
  {
    debuglogln("Failed to initialize humidity temperature sensor!");
    while (1)
      ;
  }
  return 0;
}

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
unsigned int sensorLoop::accelMaxOptions = 2;
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
  loopIMU_accel();
  switch (accelStateChangeFlag)
  {
  case 1:
    debuglogln("\nMusic Player");
    loopAirGesture();
    /* code */
    break;
  case 2:
    debuglogln("\nHumidity n Temp");
    loopHumidityTemperature();
    break;
  default:
    debuglogln("\n\n\nTO-DO\n\n\n");
    loopAirGesture();
    break;
  }
  return 0;
}

int sensorLoop::loopIMU_accel()
{
  float x, y, z, delta = 0.05;
  debuglogln("\nIMU_Accel loop\n");
  if (IMU.accelerationAvailable())
  {
    IMU.readAcceleration(x, y, z);
    if (y >= 1 - delta){
      debuglogln("left");
      sensorLoop::accelStateChangeFlag++;
      debuglogln("\naccFlag");
      debuglog(sensorLoop::accelStateChangeFlag);
      resetFlag();
      digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
      delay(1100);
      digitalWrite(LED_BUILTIN, LOW);  // turn the LED off by making the voltage LOW
      delay(400);
    }
    else if (y <= delta - 1)
    {
      debuglogln("right");
      sensorLoop::accelStateChangeFlag--;
      debuglogln("\naccFlag");
      debuglog(sensorLoop::accelStateChangeFlag);
      resetFlag();
      digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
      delay(1100);
      digitalWrite(LED_BUILTIN, LOW);  // turn the LED off by making the voltage LOW
      delay(400);
    }
  }
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
  static int volume = 5, max_volume = 10;
  static int song_num = 1;
  static char song_char[100], volume_char[100];
  static int max_song = 5;
  u8g2.firstPage();
  if (APDS.gestureAvailable())
  {
    // a gesture was detected, read and print to serial monitor
    int gesture = APDS.readGesture();

    switch (gesture)
    {
    case GESTURE_UP:
      debuglogln("Detected UP gesture");
      if (song_num < max_song)
        song_num++;
      else
        song_num = 1;
      itoa(song_num, song_char, 10);
      do
      {
        u8g2.setFont(u8g2_font_ncenB14_tr);
        u8g2.drawStr(0, 24, "Playing Next");
        u8g2.drawStr(0, 48, "Song:");
        u8g2.drawStr(60, 48, song_char);
      } while (u8g2.nextPage());
      break;

    case GESTURE_DOWN:

      debuglogln("Detected DOWN gesture");
      if (song_num > 0)
        song_num--;
      else
        song_num = max_song;
      itoa(song_num, song_char, 10);
      do
      {
        u8g2.setFont(u8g2_font_ncenB14_tr);
        u8g2.drawStr(0, 24, "Playing Prev.");
        u8g2.drawStr(0, 48, "Song:");
        u8g2.drawStr(60, 48, song_char);
      } while (u8g2.nextPage());
      break;

    case GESTURE_LEFT:
      debuglogln("Detected LEFT gesture");
      if (volume < max_volume)
        volume++;
      itoa(volume, volume_char, 10);
      do
      {
        u8g2.setFont(u8g2_font_ncenB14_tr);
        u8g2.drawStr(0, 24, "Volume");
        u8g2.drawStr(0, 48, "Up:");
        u8g2.drawStr(55, 48, volume_char);
      } while (u8g2.nextPage());
      break;

    case GESTURE_RIGHT:
      debuglogln("Detected RIGHT gesture");
      if (volume > 0)
        volume--;
      itoa(volume, volume_char, 10);
      do
      {
        u8g2.setFont(u8g2_font_ncenB14_tr);
        u8g2.drawStr(0, 24, "Volume");
        u8g2.drawStr(0, 48, "Down:");
        u8g2.drawStr(65, 48, volume_char);
      } while (u8g2.nextPage());
      break;

    default:
      debuglogln("Detected NO gesture");
      // ignore
      break;
    }
  }

  return 0;
}

int sensorLoop::loopHumidityTemperature()
{
  const float tempOffset = -4.50, humiOffset = 6.00;
  static float temperature = HTS.readTemperature() + tempOffset;
  static float humidity = HTS.readHumidity() + humiOffset;
  u8g2.firstPage();

  // print each of the sensor values
  debuglog("Temperature = ");
  debuglog(temperature);
  debuglogln(" °C");
  char result_int, result_float[8]; // Buffer big enough for 7-character float
  // dtostrf(temperature, 6, 2, result); // Leave room for too large numbers!
  result_int = (int)temperature;
  float val_float = (abs(temperature) - abs(result_int)) * 100;
  int val_fra = (int)val_float;
  sprintf(result_float, "%d.%d", result_int, val_fra); //

  do
  {
    u8g2.setFont(u8g2_font_ncenB14_tr);
    u8g2.drawStr(0, 24, "Temperature in");
    u8g2.drawStr(0, 48, "deg C:");
    u8g2.drawStr(65, 48, result_float);
  } while (u8g2.nextPage());
  delay(1500);

  debuglog("Humidity    = ");
  debuglog(humidity);
  debuglogln(" %");
  // char result[8]; // Buffer big enough for 7-character float
  // dtostrf(humidity, 6, 2, result); // Leave room for too large numbers!
  result_int = (int)humidity;
  val_float = (abs(humidity) - abs(result_int)) * 100;
  val_fra = (int)val_float;
  sprintf(result_float, "%d.%d", result_int, val_fra); //

  u8g2.firstPage();
  do
  {
    u8g2.setFont(u8g2_font_ncenB14_tr);
    u8g2.drawStr(0, 24, "Humidity");
    u8g2.drawStr(0, 48, "% = ");
    u8g2.drawStr(55, 48, result_float);
  } while (u8g2.nextPage());
  // print an empty line
  debuglogln();

  // wait 1 second to print again
  delay(1500);
  return 0;
}

int sensorLoop::loopSerialEcho()
{
  return 0;
}