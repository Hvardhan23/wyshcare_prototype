#include "config.h"

bool touchBegin() {
  pinMode(TOUCH_PIN, INPUT);
  return false;
}

bool touchIsActive() {
  return false;
}
