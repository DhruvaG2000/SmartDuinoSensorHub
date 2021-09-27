#include "sensorSetup.h"

// OLED Display configuration
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

int setupAPDS9960()
{
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
    return 0;
}

int setupHTS221()
{
  Serial.begin(9600);
  if (!HTS.begin()) {
    Serial.println("Failed to initialize humidity temperature sensor!");
    while (1);
  }
  return 0;
}

#define U8LOG_WIDTH 20
#define U8LOG_HEIGHT 8
uint8_t u8log_buffer[U8LOG_WIDTH*U8LOG_HEIGHT];
U8G2LOG u8g2log;

int setupSerialEcho()
{
  u8g2.begin();  
  u8g2.setFont(u8g2_font_5x7_tr);	// set the font for the terminal window
  u8g2log.begin(u8g2, U8LOG_WIDTH, U8LOG_HEIGHT, u8log_buffer);
  u8g2log.setLineHeightOffset(0);	// set extra space between lines in pixel, this can be negative
  u8g2log.setRedrawMode(1);		// 0: Update screen with newline, 1: Update screen for every char
  return 0;
}