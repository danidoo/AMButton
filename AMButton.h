#ifndef AMBUTTON_H
#define AMBUTTON_H

#include "Arduino.h"

#define PRESS 0
#define LONGPRESS 1
#define RELEASE 2
#define scanPeriod 40
#define debouncePeriods 3

class AMButton {
  public:
    AMButton(int bPin, byte bCount, int lpDuration, void (*bHandle)(int, byte));
    void scan(void);
  private:
    void sameButtonPress();
    void differentButtonPress(int button);
};

#endif
