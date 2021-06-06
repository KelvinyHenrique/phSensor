#include <Arduino.h>
const int adcPin = A0;
  
// Calcule ou teste seu sensor de ph
// Ao usar uma solucao tampao de PH4 para calibracao, m pode ser derivado como:
// m = (pH7 - pH4) / (Vph7 - Vph4)
const float m = -5.436; 

void setup() {
  Serial.begin(115200);
}

void loop() {
  float Po = analogRead(adcPin) * 5.0 / 1024;
  float phValue = 7 - (2.5 - Po) * m;
  Serial.print("ph value = "); Serial.println(phValue);
  delay(5000);
}
