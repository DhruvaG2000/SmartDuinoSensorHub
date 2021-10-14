#include "sensorManager.h"

sensorSetup setupSensors;
sensorLoop runSensors;

void setupAllSensors()
{
  setupSensors.setupHumidityTemperature();
  setupSensors.setupAirGesture();
}

void setup() {
  setupAllSensors();
}

void loop() {
  runSensors.loopAirGesture();
}