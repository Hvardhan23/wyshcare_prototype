#include <Arduino.h>
#include <Wire.h>

#include "config.h"

namespace {
uint32_t lastSensorUpdate = 0;
uint32_t infrared = 0;
float temperatureC = NAN;
bool touchActive = false;
bool displayReady = false;
bool max30102Ready = false;
bool mpu6050Ready = false;
bool temperatureReady = false;
bool touchReady = false;
}

void setup() {
  alertsBegin();
  Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);
  clockBegin();

  displayReady = displayBegin();
  max30102Ready = max30102Begin();
  mpu6050Ready = mpu6050Begin();
  temperatureReady = temperatureBegin();
  touchReady = touchBegin();

  if (!displayReady) {
    alert("display", "Initialization failed");
  }
  if (!max30102Ready) {
    alert("MAX30102", "Initialization failed");
  }
  if (!mpu6050Ready) {
    alert("MPU6050", "Initialization failed");
  }
  if (!temperatureReady) {
    alert("temperature", "Initialization failed");
  }
  if (!touchReady) {
    alert("touch", "Initialization failed");
  }
}

void loop() {
  const uint32_t now = millis();
  if (now - lastSensorUpdate < SENSOR_UPDATE_INTERVAL_MS) {
    delay(10);
    return;
  }
  lastSensorUpdate = now;

  uint32_t red = 0;
  uint32_t sampleInfrared = infrared;
  if (max30102Ready && max30102Read(red, sampleInfrared)) {
    infrared = sampleInfrared;
  }

  float accelX = 0.0F;
  float accelY = 0.0F;
  float accelZ = 0.0F;
  if (mpu6050Ready && !mpu6050Read(accelX, accelY, accelZ)) {
    alert("MPU6050", "Unable to read sample");
  }

  float sampleTemperature = temperatureC;
  if (temperatureReady && temperatureReadC(sampleTemperature)) {
    temperatureC = sampleTemperature;
  }
  if (touchReady) {
    touchActive = touchIsActive();
  }

  if (displayReady) {
    displayUpdate(clockGetTime(), temperatureC, infrared, touchActive);
  }
}
