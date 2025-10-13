#include <Servo.h>

Servo myServo;
int potPin = A0;
int val;

void setup() {
  myServo.attach(9);
}

void loop() {
  val = analogRead(potPin);
  val = map(val, 0, 1023, 0, 180);
  myServo.write(val);
  delay(15);
}

