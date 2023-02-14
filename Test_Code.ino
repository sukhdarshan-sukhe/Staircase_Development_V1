#include <ShiftRegister74HC595.h>

// parameters: <number of shift registers> (data pin, clock pin, latch pin)
ShiftRegister74HC595<2> sr(14, 12, 13);
int sensorPin1 = 5;
int sensorPin2 = 4;
int pirState = LOW;
int val = 0;

unsigned long previousMillis = 0;
const long intervalOn = 1000;  // interval at which to blink (milliseconds)
const long intervalOff = 20000;

void setup() {
  Serial.begin(57600);
  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);
}

void loop() {
  val = digitalRead(sensorPin1);
  if (val == HIGH) {
    ledOn();
  }
  val = digitalRead(sensorPin1);
  if (val == LOW) {
    ledOff();
  }
  val = digitalRead(sensorPin2);
  if (val == HIGH) {
    ledOnBack();
  }
  val = digitalRead(sensorPin2);
  if (val == LOW) {
    ledOffBack();
  }
}
void ledOn() {

  unsigned long currentMillis = millis();
  Serial.print("currentMillis--");
  Serial.println(currentMillis);
  if (currentMillis - previousMillis >= intervalOn) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    Serial.print("previousMillis--");
    Serial.println(previousMillis);

    // setting single pins
    for (int i = 16; i >= 0; i--) {

      sr.set(i, HIGH);  // set single pin HIGH
      delay(250);
    }
  }
}

void ledOff() {
  unsigned long currentMillis = millis();
  Serial.print("currentMillis--");
  Serial.println(currentMillis);
  if (currentMillis - previousMillis >= intervalOff) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    Serial.print("previousMillis--");
    Serial.println(previousMillis);
    for (int i = 16; i >= 0; i--) {

      sr.set(i, LOW);  // set single pin HIGH
      delay(250);
    }
  }
}

void ledOnBack() {

  unsigned long currentMillis = millis();
  Serial.print("currentMillis--");
  Serial.println(currentMillis);
  if (currentMillis - previousMillis >= intervalOn) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    Serial.print("previousMillis--");
    Serial.println(previousMillis);

    // setting single pins
    for (int i = 0; i < 16; i++) {

      sr.set(i, HIGH);  // set single pin HIGH
      delay(250);
    }
  }
}

void ledOffBack() {
  unsigned long currentMillis = millis();
  Serial.print("currentMillis--");
  Serial.println(currentMillis);
  if (currentMillis - previousMillis >= intervalOff) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    Serial.print("previousMillis--");
    Serial.println(previousMillis);
    for (int i = 0; i < 16; i++) {

      sr.set(i, LOW);  // set single pin HIGH
      delay(250);
    }
  }
}