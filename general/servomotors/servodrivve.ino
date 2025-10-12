#include <Servo.h>

Servo myServo;
int joystickX;
int servoPos;

void setup() {
  myServo.attach(9);
}

void loop() {
  joystickX = analogRead(A0);
  servoPos = map(joystickX, 0, 1023, 0, 180);
  myServo.write(servoPos);
  delay(15);
}

