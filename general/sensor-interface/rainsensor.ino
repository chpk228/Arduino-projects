#define rainSensorPin A0
#define ledPin 13
int rainValue;

void setup() {
  pinMode(rainSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  rainValue = analogRead(rainSensorPin);
  
  if (rainValue < 500) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(100);
}

