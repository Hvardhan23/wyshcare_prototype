#include <DallasTemperature.h>
#include <OneWire.h>

#include "config.h"

namespace {
OneWire oneWire(TEMPERATURE_DATA_PIN);
DallasTemperature sensor(&oneWire);
bool initialized = false;
}

bool temperatureBegin() {
  sensor.begin();
  initialized = sensor.getDeviceCount() > 0;
  return initialized;
}

bool temperatureReadC(float& temperatureC) {
  if (!initialized) {
    return false;
  }

  sensor.requestTemperatures();
  const float reading = sensor.getTempCByIndex(0);
  if (reading == DEVICE_DISCONNECTED_C) {
    return false;
  }

  temperatureC = reading;
  return true;
}
