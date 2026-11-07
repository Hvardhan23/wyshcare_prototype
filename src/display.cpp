#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

#include "config.h"

namespace {
Adafruit_SSD1306 display(DISPLAY_WIDTH, DISPLAY_HEIGHT, &Wire, -1);
bool initialized = false;
}

bool displayBegin() {
  initialized = display.begin(SSD1306_SWITCHCAPVCC, DISPLAY_I2C_ADDRESS);
  if (!initialized) {
    return false;
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.display();
  return true;
}

void displayUpdate(const String& timeText, float temperatureC,
                   uint32_t infrared, bool touchActive) {
  if (!initialized) {
    return;
  }

  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(F("Health monitor"));
  display.print(F("Uptime: "));
  display.println(timeText);

  display.print(F("Temp: "));
  if (isnan(temperatureC)) {
    display.println(F("--"));
  } else {
    display.print(temperatureC, 1);
    display.println(F(" C"));
  }

  display.print(F("IR raw: "));
  display.println(infrared);
  display.print(F("Touch: "));
  display.println(touchActive ? F("active") : F("idle"));
  display.display();
}
