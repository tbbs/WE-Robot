#include <Arduino.h>

int hallSensorPin = 2;
int ledPin =  13;
int state = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(hallSensorPin, INPUT);
  Serial.begin(115200);
  Serial.println("Beggin");
  //comment
}

void loop(){

  state = digitalRead(hallSensorPin);

  if (state == LOW) {
    Serial.println("HIGH");
  }
  else {
    Serial.println("LOW");
  }
  delay(1000);
}
