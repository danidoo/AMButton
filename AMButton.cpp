#include "AMButton.h"

extern "C" {
  typedef void (*buttonHandle)(int, byte);
}

// Button variables
boolean longPress = false;
byte buttonCount;
byte debounceCount = 0;
int buttonPin;
int pressedButton = -1;
unsigned int buttonsThreashold[10];
unsigned int longPressDuration;
unsigned int debounceTime;
unsigned long time;
unsigned long buttonPressTime;
buttonHandle buttonHandler;

AMButton::AMButton(int bPin, byte bCount, int lpDuration, void (*bHandle)(int, byte)) {
  buttonCount = bCount;
  buttonPin = bPin;
  longPressDuration = lpDuration;
  buttonHandler = bHandle;
  pinMode(buttonPin, INPUT);
  for (byte i = 0; i < buttonCount; i++) {
    buttonsThreashold[i] = int((1024/(buttonCount+1))*0.9*(i+1));
  }
}

void AMButton::scan() {
  if (millis() - time > scanPeriod) {
    int val = analogRead(buttonPin);
    int i = buttonCount-1;
    for (; i >= 0; i--) {
      if (val > buttonsThreashold[i]) {
        if (pressedButton == i) sameButtonPress();
        else differentButtonPress(i);
        break;
      }
    }
    if (i == -1 && pressedButton >= 0) {
      differentButtonPress(i);
    }
    time = millis();
  }
}

void AMButton::sameButtonPress() {
  if (millis() - buttonPressTime >= longPressDuration && !longPress) {
    longPress = true;
    buttonHandler(pressedButton, LONGPRESS);
  }
}

void AMButton::differentButtonPress(int button) {
  debounceCount++;
  if (debounceCount >= debouncePeriods) {
    if (button >= 0) {
      buttonHandler(button, PRESS);
    } else {
      buttonHandler(pressedButton, RELEASE);
    }
    pressedButton = button;
    longPress = false;
    debounceCount = 0;
    buttonPressTime = millis();
  }
}

