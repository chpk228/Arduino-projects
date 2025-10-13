const int touchSensorPin = 2; 
const int ledPin = 3; 

void setup() {
  Serial.begin(9600); 
  pinMode(touchSensorPin, INPUT); 
  pinMode(ledPin, OUTPUT); 
}

void loop() {
  int touchState = digitalRead(touchSensorPin); 

  if (touchState == HIGH) {
    Serial.println("Touch detected!");
    digitalWrite(ledPin, HIGH); 
  } else {
    Serial.println("No touch detected.");
    digitalWrite(ledPin, LOW); 
  }
  delay(100); 
}
