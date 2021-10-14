#include "sensorManager.h"

sensorSetup setupSensors;
sensorLoop runSensors;

void setupAllSensors()
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off (LOW is the voltage level)
  setupSensors.setupIMU();
  setupSensors.setupHumidityTemperature();
  setupSensors.setupAirGesture();
}

void setup() {
  setupAllSensors();
}

void loop() {
  runSensors.loopSel();
}