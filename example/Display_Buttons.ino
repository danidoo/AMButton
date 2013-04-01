#include <LiquidCrystal.h>
#include "AMButton.h"

// LCD constants and Init
const byte numRows = 2;
const byte numCols = 16;

// Temperature variables
float OnThreashold = 23;
float OffThreashold = 19;
float currentTemp = 21.2;
byte editTemp = 0;

LiquidCrystal lcd(12, 11, 10, 5, 6, 7, 8);

void buttonH(int button, byte action) {
  if (button == 0 && action == LONGPRESS) {
    editTemp = 1;
  }
  if (button == 0 && action == PRESS && editTemp != 0) {
    Serial.println("Entrou");
    if (editTemp == 1) {
      editTemp = 2;
    } else {
      editTemp = 1;
    }
  }
  printTemperatures();
}

AMButton button(A0, 3, 1500, &buttonH);

void printTemperatures() {
  lcd.setCursor(0,1);
  lcd.print(OffThreashold, 1);
  lcd.setCursor(6,1);
  lcd.print(currentTemp, 1);
  lcd.setCursor(12,1);
  lcd.print(OnThreashold, 1);
  lcd.setCursor(1,1);
  Serial.println(editTemp);
  switch (editTemp) {
    case 0:
      lcd.noBlink();
      break;
    case 1:
      lcd.setCursor(1,1);
      lcd.blink();
      break;
    case 2:
      lcd.setCursor(13,1);
      lcd.blink();
      break;
  }
}

void setup() {
  // LCD Setup
  lcd.begin(numCols, numRows);
  lcd.print("Desl  Corr  Liga");
  printTemperatures();
  Serial.begin(9600);
}

void loop() {
  button.Read();
}


