#include <TimerOne.h>

const int zeroCrossPin = 2;
const int triacGatePin = 4;
const int dimmingPotPin = A0;

volatile bool zeroCrossDetected = false;
int dimmingValue = 0;
int firingDelay = 0;

void setup() {
  pinMode(triacGatePin, OUTPUT);
  digitalWrite(triacGatePin, LOW);
  attachInterrupt(digitalPinToInterrupt(zeroCrossPin), zeroCrossInterrupt, RISING);
  Timer1.initialize(10000);
  Timer1.attachInterrupt(timerInterrupt);
}

void loop() {
  int sensorValue = analogRead(dimmingPotPin);
  dimmingValue = map(sensorValue, 0, 1023, 1000, 7500);
}

void zeroCrossInterrupt() {
  zeroCrossDetected = true;
  Timer1.restart();
}

void timerInterrupt() {
  if (zeroCrossDetected) {
    digitalWrite(triacGatePin, HIGH);
    delayMicroseconds(50);
    digitalWrite(triacGatePin, LOW);
    zeroCrossDetected = false;
  }
}


