#include "sensorManager.h"

sensorSetup setupSensors;
sensorLoop runSensors;

void setupAllSensors()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off (LOW is the voltage level)
  setupSensors.setupIMU();
  setupSensors.setupHumidityTemperature();
  setupSensors.setupPressure();
  setupSensors.setupAirGesture();
  setupSensors.setupAnalogMQ();
}

void setup() {
  setupAllSensors();
}

void loop() {
  runSensors.loopSel();
}