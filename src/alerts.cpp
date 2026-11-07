#include "config.h"

void alertsBegin() {
  Serial.begin(115200);
  delay(100);
}

void alert(const char* module, const char* message) {
  Serial.print('[');
  Serial.print(millis());
  Serial.print(F(" ms] "));
  Serial.print(module);
  Serial.print(F(": "));
  Serial.println(message);
}
