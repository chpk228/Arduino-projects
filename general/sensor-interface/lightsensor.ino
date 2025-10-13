const int ldrPin = A0;
const int ledPin = 3;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  Serial.println(ldrValue);

  if (ldrValue < 500) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  delay(100);
}
