#include <Servo.h>

Servo myServo;

void setup() {
  myServo.attach(9);
  randomSeed(analogRead(0));
}

void loop() {
  int angle = random(0, 181);
  myServo.write(angle);
  delay(1000);
}

