#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int forceSensorPin = A0;
const int soilMoisturePin = A1;
const int gasSensorPin = A2;
const int tiltSensorPin = 2;
const int buzzerPin = 8;

unsigned long previousMillis = 0;
const long interval = 500;   
int displayStep = 0;

void setup() {
  pinMode(tiltSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  int forceValue = analogRead(forceSensorPin);
  int soilValue = analogRead(soilMoisturePin);
  int gasValue = analogRead(gasSensorPin);
  int tiltState = digitalRead(tiltSensorPin);

  bool buzzerState = false;

  // Check thresholds
  if (forceValue > 100) buzzerState = true;
  if (soilValue > 400) buzzerState = true;
  if (gasValue > 500) buzzerState = true;
  if (tiltState == HIGH) buzzerState = true;

  // Control buzzer
  digitalWrite(buzzerPin, buzzerState ? HIGH : LOW);

  // Handle LCD updates with millis()
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    lcd.clear();
    switch (displayStep) {
      case 0:
        lcd.setCursor(0, 0); lcd.print("Force Sensor:");
        lcd.setCursor(0, 1); lcd.print(forceValue);
        break;
      case 1:
        lcd.setCursor(0, 0); lcd.print("Soil Moisture:");
        lcd.setCursor(0, 1); lcd.print(soilValue);
        break;
      case 2:
        lcd.setCursor(0, 0); lcd.print("Gas Sensor:");
        lcd.setCursor(0, 1); lcd.print(gasValue);
        break;
      case 3:
        lcd.setCursor(0, 0); lcd.print("Tilt Sensor:");
        lcd.setCursor(0, 1);
        if (tiltState == HIGH) lcd.print("Tilt detected!");
        else lcd.print("Stable");
        break;
    }
    displayStep = (displayStep + 1) % 4; 
  }
}
