#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

#include "config.h"

namespace {
Adafruit_MPU6050 sensor;
bool initialized = false;
}

bool mpu6050Begin() {
  initialized = sensor.begin(0x68, &Wire);
  return initialized;
}

bool mpu6050Read(float& accelX, float& accelY, float& accelZ) {
  if (!initialized) {
    return false;
  }

  sensors_event_t acceleration;
  sensors_event_t gyro;
  sensors_event_t temperature;
  sensor.getEvent(&acceleration, &gyro, &temperature);
  accelX = acceleration.acceleration.x;
  accelY = acceleration.acceleration.y;
  accelZ = acceleration.acceleration.z;
  return true;
}
