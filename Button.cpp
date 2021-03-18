#include "Button.h"
#include "Arduino.h"

Button::Button(int buttonpin, int val) {
    startTime = 0;
    onTime = -1;
    buttonState = false;
    prevButtonState = false;
    analogTrigVal = val;
    buttonPin = buttonpin;
}

Button::~Button() {}

void Button::SetButtonTrig(int val) {
    analogTrigVal = val;
}

void Button::SetStartTime(int val, int currTime){
    prevButtonState = buttonState;
    if (val <= analogTrigVal && val > analogTrigVal - buff) {
        buttonState = true;
        if (onTime < 0 ) {
            startTime = currTime;
            onTime = 0;
        } else {
            onTime = (currTime - startTime);
        }
    } else {
        startTime = 0;
        buttonState = false;
    }
}

int Button::GetButtonPin() {
    return buttonPin;
}

bool Button::IsButtonTrigger() {
    if ((!buttonState) && (buttonState^prevButtonState) && 
            (onTime>bounce_ms)) {
        if (onTime < short_press) {
            onTime = -1;
            return true;
        } else {
            onTime = -1;
            return false;
        }
    }
    return false;
}
