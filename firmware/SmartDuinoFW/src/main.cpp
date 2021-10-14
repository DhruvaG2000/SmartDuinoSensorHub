#include "sensorManager.h"

sensorSetup setupSensors;
sensorLoop runSensors;

void setupAllSensors()
{
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