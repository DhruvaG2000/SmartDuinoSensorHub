#include <Arduino.h>
#include <mbed.h>
#include <Arduino_LSM9DS1.h>

void setup()
{
  Serial.begin(9600);
  while (!Serial)
    ;
  Serial.println("Started");

  if (!IMU.begin())
  {
    Serial.println("Failed to initialize IMU!");
    while (1)
      ;
  }

  Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Acceleration in g's");
  Serial.println("X\tY\tZ");


  Serial.println("Started gyro");

  Serial.print("Gyroscope sample rate = ");
  Serial.print(IMU.gyroscopeSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Gyroscope in degrees/second");
  Serial.println("X\tY\tZ");


}


long unsigned int loopGyro()
{
  float x, y, z;

  if (IMU.gyroscopeAvailable())
  {
    IMU.readGyroscope(x, y, z);

    Serial.print(x);
    Serial.print('\t');
    Serial.print(y);
    Serial.print('\t');
    Serial.println(z);
  }
  delay(1000);
return 0;
}

long unsigned int loopAccel()
{
float x, y, z, delta = 0.05;

   if (IMU.accelerationAvailable())
  {
    IMU.readAcceleration(x, y, z);
    if (y <= delta && y >= -delta)
      Serial.println("flat");
    else if (y > delta && y < 1 - delta)
      Serial.println("tilted to the left");
    else if (y >= 1 - delta)
      Serial.println("left");
    else if (y < -delta && y > delta - 1)
      Serial.println("tilted to the right");
    else
      Serial.println("right");
  }
  delay(1500);
  return 0;
}

void loop(){

rtos::Thread thread1(loopAccel());
rtos::Thread thread2(loopGyro());

}