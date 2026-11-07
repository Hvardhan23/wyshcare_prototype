#include "config.h"

void clockBegin() {
}

String clockGetTime() {
  const uint32_t seconds = millis() / 1000;
  const uint32_t hours = (seconds / 3600) % 100;
  const uint32_t minutes = (seconds / 60) % 60;
  const uint32_t remainingSeconds = seconds % 60;

  char timeText[9];
  snprintf(timeText, sizeof(timeText), "%02lu:%02lu:%02lu",
           static_cast<unsigned long>(hours),
           static_cast<unsigned long>(minutes),
           static_cast<unsigned long>(remainingSeconds));
  return String(timeText);
}
