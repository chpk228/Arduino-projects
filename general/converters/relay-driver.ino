const int zero_cross_pin = 3;
const int ssr_control_pin = 2;
volatile unsigned long zero_cross_micros = 0;
const int half_period_micros = 10000;
const int ssr_delay = 5000;

void zero_cross_interrupt() {
  zero_cross_micros = micros();
}

void setup() {
  pinMode(zero_cross_pin, INPUT);
  pinMode(ssr_control_pin, OUTPUT);
  digitalWrite(ssr_control_pin, LOW);
  attachInterrupt(digitalPinToInterrupt(zero_cross_pin), zero_cross_interrupt, RISING);
}

void loop() {
  if (micros() - zero_cross_micros < half_period_micros) {
    if (micros() - zero_cross_micros >= ssr_delay) {
      digitalWrite(ssr_control_pin, HIGH);
    } else {
      digitalWrite(ssr_control_pin, LOW);
    }
  } else {
    digitalWrite(ssr_control_pin, LOW);
  }
}

