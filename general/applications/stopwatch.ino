unsigned long startTime = 0;
unsigned long elapsedTime = 0;
bool running = false;

const int startStopPin = 2; // Connect a button to this pin and GND
const int resetPin = 3;     // Connect another button to this pin and GND

void setup() {
  Serial.begin(9600);
  pinMode(startStopPin, INPUT_PULLUP);
  pinMode(resetPin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(startStopPin) == LOW) {
    delay(50); 
    while (digitalRead(startStopPin) == LOW); 
    if (running) {
      running = false;
    } else {
      startTime = millis() - elapsedTime;
      running = true;
    }
  }

  if (digitalRead(resetPin) == LOW) {
    delay(50);
    while (digitalRead(resetPin) == LOW);
    running = false;
    elapsedTime = 0;
    startTime = 0;
  }

  if (running) {
    elapsedTime = millis() - startTime;
  }

  long hours = elapsedTime / 3600000;
  long minutes = (elapsedTime % 3600000) / 60000;
  long seconds = ((elapsedTime % 3600000) % 60000) / 1000;
  long milliseconds = elapsedTime % 1000;

  Serial.print(hours);
  Serial.print(":");
  if (minutes < 10) Serial.print("0");
  Serial.print(minutes);
  Serial.print(":");
  if (seconds < 10) Serial.print("0");
  Serial.print(seconds);
  Serial.print(".");
  if (milliseconds < 100) Serial.print("0");
  if (milliseconds < 10) Serial.print("0");
  Serial.println(milliseconds);

  delay(10); 
}
