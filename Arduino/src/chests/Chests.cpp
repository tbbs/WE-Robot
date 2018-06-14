#include <Arduino.h>
#include <Servo.h>

int sensor1 = 2;
int sensor2 = 3;
int sensor3 = 4;
int pinServo=8;

int state = 0;
Servo servo;

bool gameIsCleared()
{
    if(!digitalRead(sensor1) && !digitalRead(sensor2) && !digitalRead(sensor3))
        return true;
    else
        return false;
}

void openDoor()
{
    Serial.println("OPEN");
    servo.write(140);
    digitalWrite(LED_BUILTIN, HIGH);
}

void closeDoor()
{
    Serial.println("CLOSED");
    servo.write(35);
    digitalWrite(LED_BUILTIN, LOW);
}



void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  Serial.begin(115200);
  Serial.println("Beggin");
  servo.attach(pinServo);
  openDoor();
  while (!gameIsCleared())
      delay(200);

}

void loop()
{
    if (gameIsCleared())
        openDoor();
    else
        closeDoor();
    delay(100);
}
