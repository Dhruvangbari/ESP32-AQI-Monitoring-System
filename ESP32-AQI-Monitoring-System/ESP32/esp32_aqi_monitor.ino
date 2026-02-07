/*
 Air Quality Index (AQI) Monitoring System using ESP32
 Components:
 - ESP32 Dev Board
 - MQ-135 Air Quality Sensor
 - Buzzer
 - Red LED (Bad Air)
 - Green LED (Good Air)
 - 16x2 LCD Display (Parallel)
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(23, 22, 21, 19, 18, 5);

const int airSensorPin = 34;
const int buzzerPin = 25;
const int redLed = 26;
const int greenLed = 27;

int airValue = 0;
int threshold = 2000;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("AQI MONITOR");
  lcd.setCursor(0, 1);
  lcd.print("ESP32 READY");
  delay(2000);
  lcd.clear();
}

void loop() {
  airValue = analogRead(airSensorPin);

  lcd.setCursor(0, 0);
  lcd.print("Air Value: ");
  lcd.print(airValue);
  lcd.print(" ");

  if (airValue > threshold) {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(buzzerPin, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Status: BAD ");
  } else {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(buzzerPin, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Status: GOOD ");
  }

  delay(1000);
}
