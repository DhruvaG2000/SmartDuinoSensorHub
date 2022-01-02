#include "sensorManager.h"

sensorSetup setupSensors;
sensorLoop runSensors;

void setupAllSensors()
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off (LOW is the voltage level)
  Serial.begin(9600);
  setupSensors.setupIMU();
  setupSensors.setupHumidityTemperature();
  setupSensors.setupAirGesture();
  setupSensors.setupAnalogMQ();
}

void setup() {
  setupAllSensors();
}

void loop() {
  runSensors.loopSel();
}