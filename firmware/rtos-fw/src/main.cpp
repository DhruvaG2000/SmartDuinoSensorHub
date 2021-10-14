#include "sensorManager.h"
#include <mbed.h>

sensorSetup setupSensors;
sensorLoop runSensors;

void setup() {
  Serial.begin(9600);
  Serial.println("Serial Started");
  setupSensors.setupIMU();
}

void loop() {
  rtos::Thread thread1(runSensors.loopIMU_accel());
  rtos::Thread thread2(runSensors.loopIMU_gyro());
  rtos::Thread thread3(runSensors.loopSel());
}