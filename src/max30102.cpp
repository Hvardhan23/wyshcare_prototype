#include <MAX30105.h>
#include <Wire.h>

#include "config.h"

namespace {
MAX30105 sensor;
bool initialized = false;
}

bool max30102Begin() {
  initialized = sensor.begin(Wire, I2C_SPEED_STANDARD);
  if (initialized) {
    sensor.setup();
  }
  return initialized;
}

bool max30102Read(uint32_t& red, uint32_t& infrared) {
  if (!initialized) {
    return false;
  }

  sensor.check();
  if (sensor.available() == 0) {
    return false;
  }

  red = sensor.getRed();
  infrared = sensor.getIR();
  sensor.nextSample();
  return true;
}
