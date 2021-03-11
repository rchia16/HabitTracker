#include <SD.h>
#include <SPI.h>
#include "Button.h"

File SaveFile;
const int buffLen = 256;
char buff[256];

const int buttonPin = A0;
const int ledG = 7;
const int ledR = 2;
const int ledY = 3;

const int baudrate = 9600;

int buttonPinRead = 0;
int val0 = 100, val1 = 160, val2 = 260, val3 = 450, val4 = 1100;
int startTime = 0;
button0 = Button(buttonPin, val0);
button1 = Button(buttonPin, val1);
button2 = Button(buttonPin, val2);
button3 = Button(buttonPin, val3);
button4 = Button(buttonPin, val4);

void setup() {
    pinMode(ledG, OUTPUT);
    pinMode(ledR, OUTPUT);
    pinMode(ledY, OUTPUT);
    pinMode(buttonPin, INPUT);

    Serial.begin(baudrate);
    Serial.println("Initialising SD Card...");
}

void loop() {
    buttonPinRead = analogRead(buttonPin);

    startTime = millis();
    button0.SetStartTime(buttonPinRead, startTime);
    button1.SetStartTime(buttonPinRead, startTime);
    button2.SetStartTime(buttonPinRead, startTime);
    button3.SetStartTime(buttonPinRead, startTime);
    button4.SetStartTime(buttonPinRead, startTime);
    debugLEDs();
    /* debugLEDsTmp(buttonPinRead); */
}

void debugLEDs() {
    if (button0.IsButtonTrigger(startTime)) {
        digitalWrite(ledG, LOW);
        digitalWrite(ledR, LOW);
        digitalWrite(ledY, LOW);
    }
    if (button1.IsButtonTrigger(startTime)) {
        digitalWrite(ledG, HIGH);
        digitalWrite(ledR, HIGH);
        digitalWrite(ledY, HIGH);
    }
    if (button2.IsButtonTrigger(startTime)) {
        digitalWrite(ledG, HIGH);
        digitalWrite(ledR, LOW);
        digitalWrite(ledY, LOW);
    }
    if (button3.IsButtonTrigger(startTime)) {
        digitalWrite(ledG, LOW);
        digitalWrite(ledR, LOW);
        digitalWrite(ledY, HIGH);
    }
    if (button4.IsButtonTrigger(startTime)) {
        digitalWrite(ledG, LOW);
        digitalWrite(ledR, HIGH);
        digitalWrite(ledY, LOW);
    }

}

void debugLEDsTmp(buttonPinRead) {
    if (buttonPinRead < val0) {
        digitalWrite(ledG, LOW);
        digitalWrite(ledR, LOW);
        digitalWrite(ledY, LOW);
    }
    if (buttonPinRead < val1) {
        digitalWrite(ledG, HIGH);
        digitalWrite(ledR, HIGH);
        digitalWrite(ledY, HIGH);
    }
    if (buttonPinRead < val2) {
        digitalWrite(ledG, HIGH);
        digitalWrite(ledR, LOW);
        digitalWrite(ledY, LOW);
    }
    if (buttonPinRead < val3) {
        digitalWrite(ledG, LOW);
        digitalWrite(ledR, LOW);
        digitalWrite(ledY, HIGH);
    }
    if (buttonPinRead < val4) {
        digitalWrite(ledG, LOW);
        digitalWrite(ledR, HIGH);
        digitalWrite(ledY, LOW);
    }
}
