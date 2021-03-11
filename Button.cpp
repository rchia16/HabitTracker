#include "Button.h"

Button::Button(int buttonpin, int val) {
    startTime = 0;
    buttonState = false;
    analogTrigVal = val;
    buttonPin = buttonpin;
}

Button::~Button() {}

void Button::SetButtonTrig(int val) {
    analogTrigVal = val;
}

void Button::SetStartTime(int val, int starttime){
    if (val >= analogTrigVal) {
        startTime = starttime;
        buttonState = true;
    } else {
        startTime = 0;
        buttonState = false;
    }
}

int Button::GetButtonPin() {
    return buttonPin;
}

bool Button::IsButtonTrigger(int currtime) {
    int pressduration = 0;
    if (buttonState) {
         pressduration = currtime - startTime;
    }
    if ((pressduration > bounce_ms) && (pressduration < short_press)) {
        return true;
    } else {
        return false;
    }
}
