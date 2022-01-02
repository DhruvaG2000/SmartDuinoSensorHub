#include <Arduino.h>

static const int count = 9, delayHigh = 100, delayLow = 50;
static int BAR_LEDS[count], counter = 0;

void pinModeAssign()
{
  for (size_t i = 0; i < count; i++)
  {
    pinMode(BAR_LEDS[i], OUTPUT);
  }
}

void setup()
{
  // initialize digital pin LED_BUILTIN as an output.
  BAR_LEDS[8] = 2;
  for (int i = 0; i < 8; i++)
  {
    BAR_LEDS[i] = i + 3;
  }

  pinModeAssign();
}

// the loop function runs over and over again forever
void loop()
{
  for (int i = 0; i < count; i++)
  {
    digitalWrite(BAR_LEDS[i], HIGH); // turn the LED on (HIGH is the voltage level)
    delay(delayHigh);                     // wait for a second
    digitalWrite(BAR_LEDS[i], LOW);  // turn the LED off by making the voltage LOW
    delay(delayLow);                      // wait for a second
  }

    for (int i = 0; i < count; i++)
    {
      digitalWrite(BAR_LEDS[i], HIGH);
      delay(delayHigh); // wait for a second
    }
    for (int i = 0; i < count; i++)
    {
    digitalWrite(BAR_LEDS[i], LOW); // turn the LED off by making the voltage LOW
    delay(50);                      // wait for a second

  }
}