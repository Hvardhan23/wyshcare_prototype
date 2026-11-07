#pragma once

#include <Arduino.h>

constexpr uint8_t I2C_SDA_PIN = 21;
constexpr uint8_t I2C_SCL_PIN = 22;
constexpr uint8_t TEMPERATURE_DATA_PIN = 4;
constexpr uint8_t TOUCH_PIN = 27;
constexpr uint8_t DISPLAY_I2C_ADDRESS = 0x3C;
constexpr uint8_t DISPLAY_WIDTH = 128;
constexpr uint8_t DISPLAY_HEIGHT = 64;
constexpr uint32_t SENSOR_UPDATE_INTERVAL_MS = 1000;
constexpr uint16_t TOUCH_THRESHOLD = 30;

bool displayBegin();
void displayUpdate(const String& timeText, float temperatureC,
                   uint32_t infrared, bool touchActive);

bool max30102Begin();
bool max30102Read(uint32_t& red, uint32_t& infrared);

bool mpu6050Begin();
bool mpu6050Read(float& accelX, float& accelY, float& accelZ);

bool temperatureBegin();
bool temperatureReadC(float& temperatureC);

bool touchBegin();
bool touchIsActive();

void clockBegin();
String clockGetTime();

void alertsBegin();
void alert(const char* module, const char* message);
