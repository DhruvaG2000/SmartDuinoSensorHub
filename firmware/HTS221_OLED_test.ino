/*
  HTS221 - Read Sensors

  This example reads data from the on-board HTS221 sensor of the
  Nano 33 BLE Sense and prints the temperature and humidity sensor
  values to the Serial Monitor once a second.

  The circuit:
  - Arduino Nano 33 BLE Sense
  - OLED Module 1.3" (SSD1306)
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

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);


void setup() {
  u8g2.begin();
  Serial.begin(9600);
  if (!HTS.begin()) {
    Serial.println("Failed to initialize humidity temperature sensor!");
    while (1);
  }
}

void loop() {
  // read all the sensor values
  float temperature = HTS.readTemperature();
  float humidity    = HTS.readHumidity();
  u8g2.firstPage();

  // print each of the sensor values
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" °C");
  char result_int, result_float[8]; // Buffer big enough for 7-character float
  //dtostrf(temperature, 6, 2, result); // Leave room for too large numbers!
  result_int = (int) temperature;
  float val_float = (abs(temperature) - abs(result_int)) * 100;
  int val_fra = (int)val_float;
  sprintf (result_float, "%d.%d", result_int, val_fra); //

  do {
    u8g2.setFont(u8g2_font_ncenB14_tr);
    u8g2.drawStr(0, 24, "Temperature in");
    u8g2.drawStr(0, 48, "deg C:");
    u8g2.drawStr(65, 48, result_float);
  } while ( u8g2.nextPage() );
  delay(1500);

  Serial.print("Humidity    = ");
  Serial.print(humidity);
  Serial.println(" %");
  // char result[8]; // Buffer big enough for 7-character float
  //dtostrf(humidity, 6, 2, result); // Leave room for too large numbers!
  result_int = (int) humidity;
  val_float = (abs(humidity) - abs(result_int)) * 100;
  val_fra = (int)val_float;
  sprintf (result_float, "%d.%d", result_int, val_fra); //

  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB14_tr);
    u8g2.drawStr(0, 24, "Humidity");
    u8g2.drawStr(0, 48, "% = ");
    u8g2.drawStr(55, 48, result_float);
  } while ( u8g2.nextPage() );
  // print an empty line
  Serial.println();

  // wait 1 second to print again
  delay(1000);
}
