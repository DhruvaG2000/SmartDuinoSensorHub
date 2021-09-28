// Define ONLY one of these:
#define DHT 1
#define MOTION 0
#define SERIAL_ECHO 0
#define IMU_MOTION_ACCEL 0
#define IMU_MOTION_GYRO 0

#if MOTION == 1
/*
  APDS9960 - Gesture Sensor

  This example reads gesture data from the on-board APDS9960 sensor of the
  Nano 33 BLE Sense and prints any detected gestures to the Serial Monitor.

  The circuit:
  - Arduino Nano 33 BLE Sense

  This example code is in the public domain.
*/

#include <Arduino_APDS9960.h>

#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

/*
  U8g2lib Example Overview:
    Frame Buffer Examples: clearBuffer/sendBuffer. Fast, but may not work with all Arduino boards because of RAM consumption
    Page Buffer Examples: firstPage/nextPage. Less RAM usage, should work with all Arduino boards.
    U8x8 Text Only Example: No RAM usage, direct communication with display controller. No graphics, 8x8 Text only.

  This is a page buffer example.
*/
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);

void setup()
{
  u8g2.begin();
  Serial.begin(9600);

  // while (!Serial);

  if (!APDS.begin())
  {
    Serial.println("Error initializing APDS9960 sensor!");
  }

  // for setGestureSensitivity(..) a value between 1 and 100 is required.
  // Higher values makes the gesture recognition more sensible but less accurate
  // (a wrong gesture may be detected). Lower values makes the gesture recognition
  // more accurate but less sensible (some gestures may be missed).
  // Default is 80
  //APDS.setGestureSensitivity(80);

  Serial.println("Detecting gestures ...");

  do
  {
    u8g2.setFont(u8g2_font_ncenB14_tr);
    u8g2.drawStr(0, 24, "Detecting ");
    u8g2.drawStr(0, 48, "gestures ...");
  } while (u8g2.nextPage());
}

int volume = 5, max_volume = 10;
int song_num = 1;
char song_char[100], volume_char[100];
int max_song = 5;

void loop()
{

  u8g2.firstPage();
  if (APDS.gestureAvailable())
  {
    // a gesture was detected, read and print to serial monitor
    int gesture = APDS.readGesture();

    switch (gesture)
    {
    case GESTURE_UP:
      Serial.println("Detected UP gesture");
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

      Serial.println("Detected DOWN gesture");
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
      Serial.println("Detected LEFT gesture");
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
      Serial.println("Detected RIGHT gesture");
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
      Serial.println("Detected NO gesture");
      // ignore
      break;
    }
  }
}
#endif

#if DHT == 1
/*
  HTS221 - Read Sensors

  This example reads data from the on-board HTS221 sensor of the
  Nano 33 BLE Sense and prints the temperature and humidity sensor
  values to the Serial Monitor once a second.

  The circuit:
  - Arduino Nano 33 BLE Sense

  This example code is in the public domain.
*/

#include <Arduino_HTS221.h>

#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

/*
  U8g2lib Example Overview:
    Frame Buffer Examples: clearBuffer/sendBuffer. Fast, but may not work with all Arduino boards because of RAM consumption
    Page Buffer Examples: firstPage/nextPage. Less RAM usage, should work with all Arduino boards.
    U8x8 Text Only Example: No RAM usage, direct communication with display controller. No graphics, 8x8 Text only.

  This is a page buffer example.
*/
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);

void setup()
{
  u8g2.begin();
  Serial.begin(9600);
  if (!HTS.begin())
  {
    Serial.println("Failed to initialize humidity temperature sensor!");
    while (1)
      ;
  }
}

void loop()
{
  // read all the sensor values
  float tempOffset = 6.00;
  float temperature = HTS.readTemperature() - tempOffset;
  float humidity = HTS.readHumidity();
  u8g2.firstPage();

  // print each of the sensor values
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" °C");
  char result_int, result_float[8]; // Buffer big enough for 7-character float
  //dtostrf(temperature, 6, 2, result); // Leave room for too large numbers!
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

  Serial.print("Humidity    = ");
  Serial.print(humidity);
  Serial.println(" %");
  // char result[8]; // Buffer big enough for 7-character float
  //dtostrf(humidity, 6, 2, result); // Leave room for too large numbers!
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
  Serial.println();

  // wait 1 second to print again
  delay(1000);
}

#endif

/*

  Serial.ino

  Read from Serial, output to display.

  Universal 8bit Graphics Library (https://github.com/olikraus/u8g2/)

  Copyright (c) 2018, olikraus@gmail.com
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification, 
  are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this list 
    of conditions and the following disclaimer.
    
  * Redistributions in binary form must reproduce the above copyright notice, this 
    list of conditions and the following disclaimer in the documentation and/or other 
    materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND 
  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  

*/
#if SERIAL_ECHO == 1
{
#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

  /*
  U8g2lib Example Overview:
    Frame Buffer Examples: clearBuffer/sendBuffer. Fast, but may not work with all Arduino boards because of RAM consumption
    Page Buffer Examples: firstPage/nextPage. Less RAM usage, should work with all Arduino boards.
    U8x8 Text Only Example: No RAM usage, direct communication with display controller. No graphics, 8x8 Text only.
    
  This is a page buffer example.    
*/

  U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);

  // End of constructor list

  // setup the terminal (U8G2LOG) and connect to u8g2 for automatic refresh of the display
  // The size (width * height) depends on the selected font and the display

#define U8LOG_WIDTH 20
#define U8LOG_HEIGHT 8
  uint8_t u8log_buffer[U8LOG_WIDTH * U8LOG_HEIGHT];
  U8G2LOG u8g2log;

  void setup(void)
  {

    Serial1.begin(115200); // Start reading from Serial communication interface

    u8g2.begin();
    u8g2.setFont(u8g2_font_5x7_tr); // set the font for the terminal window
    u8g2log.begin(u8g2, U8LOG_WIDTH, U8LOG_HEIGHT, u8log_buffer);
    u8g2log.setLineHeightOffset(0); // set extra space between lines in pixel, this can be negative
    u8g2log.setRedrawMode(1);       // 0: Update screen with newline, 1: Update screen for every char
  }

  void loop(void)
  {
    char c;
    while (Serial1.available() > 0)
    {
      c = Serial1.read(); // read from Serial Monitor
      u8g2log.print(c);   // print to display
      Serial1.print(c);   // and print back to monitor
    }
  }
}
#endif

#if IMU_MOTION_ACCEL == 1

#include <Arduino_LSM9DS1.h>

void setup()
{
  Serial.begin(9600);
  while (!Serial)
    ;
  Serial.println("Started");

  if (!IMU.begin())
  {
    Serial.println("Failed to initialize IMU!");
    while (1)
      ;
  }

  Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Acceleration in g's");
  Serial.println("X\tY\tZ");
}

void loop()
{
  float x, y, z, delta = 0.05;

  if (IMU.accelerationAvailable())
  {
    IMU.readAcceleration(x, y, z);
    if (y <= delta && y >= -delta)
      Serial.println("flat");
    else if (y > delta && y < 1 - delta)
      Serial.println("tilted to the left");
    else if (y >= 1 - delta)
      Serial.println("left");
    else if (y < -delta && y > delta - 1)
      Serial.println("tilted to the right");
    else
      Serial.println("right");
  }
}

#endif // IMU_MOTION_ACCEL

#if IMU_MOTION_GYRO == 1

#include <Arduino_LSM9DS1.h>

void setup()
{
  Serial.begin(9600);
  while (!Serial)
    ;
  Serial.println("Started");

  if (!IMU.begin())
  {
    Serial.println("Failed to initialize IMU!");
    while (1)
      ;
  }
  Serial.print("Gyroscope sample rate = ");
  Serial.print(IMU.gyroscopeSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Gyroscope in degrees/second");
  Serial.println("X\tY\tZ");
}

void loop()
{
  float x, y, z;

  if (IMU.gyroscopeAvailable())
  {
    IMU.readGyroscope(x, y, z);

    Serial.print(x);
    Serial.print('\t');
    Serial.print(y);
    Serial.print('\t');
    Serial.println(z);
  }
}
#endif // IMU_MOTION_GYRO