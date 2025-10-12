#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); 
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

#define ledPin 13

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
  
  if (finger.begin()) {
    Serial.println("Fingerprint sensor initialized.");
  } else {
    Serial.println("Fingerprint sensor not detected.");
    while (1);
  }
}

void loop() {
  getFingerprintID();
  delay(50);
}

uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  
  if (p != FINGERPRINT_OK) {
    Serial.println("No fingerprint detected.");
    return p;
  }
  
  p = finger.image2Tz();
  
  if (p != FINGERPRINT_OK) {
    Serial.println("Failed to convert image.");
    return p;
  }
  
  p = finger.fingerSearch();
  
  if (p == FINGERPRINT_OK) {
    Serial.println("Fingerprint match found!");
    digitalWrite(ledPin, HIGH);  // Turn on LED
    delay(2000);  // Keep LED on for 2 seconds
    digitalWrite(ledPin, LOW);   // Turn off LED
  } else {
    Serial.println("No match found.");
  }
  
  return p;
}

