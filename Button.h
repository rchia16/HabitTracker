#ifndef BUTTON_H
#define BUTTON_H

using namespace std;

// A class for controlling the passcodes for a puzzle box given a set sequence
// length. This class is for each button that is available.
class Button {
    private:
        const int bounce_ms = 25; // ms
        const int long_press = 1e3; // ms
        const int short_press = 350; // ms
        const int buff = 100;

        int buttonPin;
        int startTime;
        int analogTrigVal;
        int onTime;
        bool buttonState, prevButtonState;
    public:
        Button(int buttonpin, int val);
        ~Button();
        void SetStartTime(int val, int starttime);
        void SetButtonTrig(int val);
        int GetButtonPin();
        bool IsButtonTrigger();
};
#endif
