/*
  APDS9960 - Gesture Sensor

  This example reads gesture data from the on-board APDS9960 sensor of the
  Nano 33 BLE Sense and prints any detected gestures to the Serial Monitor.

  Gesture directions are as follows:
  - UP:    from USB connector towards antenna
  - DOWN:  from antenna towards USB connector
  - LEFT:  from analog pins side towards digital pins side
  - RIGHT: from digital pins side towards analog pins side

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
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);


void setup() {
  u8g2.begin();
  Serial.begin(9600);

  // while (!Serial);

  if (!APDS.begin()) {
    Serial.println("Error initializing APDS9960 sensor!");
  }

  // for setGestureSensitivity(..) a value between 1 and 100 is required.
  // Higher values makes the gesture recognition more sensible but less accurate
  // (a wrong gesture may be detected). Lower values makes the gesture recognition
  // more accurate but less sensible (some gestures may be missed).
  // Default is 80
  //APDS.setGestureSensitivity(80);

  Serial.println("Detecting gestures ...");


  do {
    u8g2.setFont(u8g2_font_ncenB14_tr);
    u8g2.drawStr(0, 24, "Detecting ");
    u8g2.drawStr(0, 48, "gestures ...");
  } while ( u8g2.nextPage() );

}

int volume = 5, max_volume = 10;
int song_num = 1; char song_char[100], volume_char[100];
int max_song = 5;

void loop() {

  u8g2.firstPage();
  if (APDS.gestureAvailable()) {
    // a gesture was detected, read and print to serial monitor
    int gesture = APDS.readGesture();

    switch (gesture) {
      case GESTURE_UP:
        Serial.println("Detected UP gesture");
        if (song_num < max_song)
          song_num++;
        else
          song_num = 1;
        itoa(song_num, song_char, 10);
        do {
          u8g2.setFont(u8g2_font_ncenB14_tr);
          u8g2.drawStr(0, 24, "Playing Next");
          u8g2.drawStr(0, 48, "Song:");
          u8g2.drawStr(60, 48, song_char);
        } while ( u8g2.nextPage() );
        break;

      case GESTURE_DOWN:

        Serial.println("Detected DOWN gesture");
        if (song_num > 0)
          song_num--;
        else
          song_num = max_song;
        itoa(song_num, song_char, 10);
        do {
          u8g2.setFont(u8g2_font_ncenB14_tr);
          u8g2.drawStr(0, 24, "Playing Prev.");
          u8g2.drawStr(0, 48, "Song:");
          u8g2.drawStr(60, 48, song_char);
        } while ( u8g2.nextPage() );
        break;

      case GESTURE_LEFT:
        Serial.println("Detected LEFT gesture");
        if (volume < max_volume)
          volume++;
        itoa(volume, volume_char, 10);
        do {
          u8g2.setFont(u8g2_font_ncenB14_tr);
          u8g2.drawStr(0, 24, "Volume");
          u8g2.drawStr(0, 48, "Up:");
          u8g2.drawStr(55, 48, volume_char);
        } while ( u8g2.nextPage() );
        break;

      case GESTURE_RIGHT:
        Serial.println("Detected RIGHT gesture");
        if (volume > 0)
          volume--;
        itoa(volume, volume_char, 10);
        do {
          u8g2.setFont(u8g2_font_ncenB14_tr);
          u8g2.drawStr(0, 24, "Volume");
          u8g2.drawStr(0, 48, "Down:");
          u8g2.drawStr(65, 48, volume_char);
        } while ( u8g2.nextPage() );
        break;

      default:
        Serial.println("Detected NO gesture");
        // ignore
        break;
    }
  }
}
