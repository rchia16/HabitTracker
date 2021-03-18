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
int val0 = 1025, val1 = 430, val2 = 230, val3 = 100, val4 = 50;
int currTime = 0;
Button button0(buttonPin, val0);
Button button1(buttonPin, val1);
Button button2(buttonPin, val2);
Button button3(buttonPin, val3);
Button button4(buttonPin, val4);

void setup() {
    pinMode(ledG, OUTPUT);
    pinMode(ledR, OUTPUT);
    pinMode(ledY, OUTPUT);
    pinMode(buttonPin, INPUT);

    Serial.begin(baudrate);
}

void loop() {
    buttonPinRead = analogRead(buttonPin);

    /* Serial.println(buttonPinRead); */
    currTime = millis();
    button0.SetStartTime(buttonPinRead, currTime);
    button1.SetStartTime(buttonPinRead, currTime);
    button2.SetStartTime(buttonPinRead, currTime);
    bool b0trig = button0.IsButtonTrigger(); 
    bool b1trig = button1.IsButtonTrigger(); 
    bool b2trig = button2.IsButtonTrigger(); 
    if (b2trig) {
        Serial.println("yellow button pressed");
    } else if (b1trig) {
        Serial.println("blue button pressed");
    } else if (b0trig){
        Serial.println("green button pressed");
    }

    button3.SetStartTime(buttonPinRead, currTime);
    button4.SetStartTime(buttonPinRead, currTime);
    /* debugLEDs(); */

    /* debugLEDsTmp(buttonPinRead); */
}

void debugLEDs() {
    if (button0.IsButtonTrigger()) {
        digitalWrite(ledG, LOW);
        digitalWrite(ledR, LOW);
        digitalWrite(ledY, LOW);
    }
    if (button1.IsButtonTrigger()) {
        digitalWrite(ledG, HIGH);
        digitalWrite(ledR, HIGH);
        digitalWrite(ledY, HIGH);
    }
    if (button2.IsButtonTrigger()) {
        digitalWrite(ledG, HIGH);
        digitalWrite(ledR, LOW);
        digitalWrite(ledY, LOW);
    }
    if (button3.IsButtonTrigger()) {
        digitalWrite(ledG, LOW);
        digitalWrite(ledR, LOW);
        digitalWrite(ledY, HIGH);
    }
    if (button4.IsButtonTrigger()) {
        digitalWrite(ledG, LOW);
        digitalWrite(ledR, HIGH);
        digitalWrite(ledY, LOW);
    }

}

void debugLEDsTmp(int buttonPinRead) {
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
