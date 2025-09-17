// Kleminini's GPIO library for general purposes
// Extremely Basic Stuff
// Currently made for the Arduino

#pragma once
#include <Arduino.h>

class obj{
    protected:
    uint8_t pin = 0;
    bool state = 0;

    public:
    obj(byte pin) : pin(pin)
    {
        if (pin == 0 || pin == 1 || pin == 13) { // PRAGMA WARNING
            pin = 5;
            #pragma message("Using digital pins 0, 1, or 13 is highly dangerous!")
        }
        Arduino_h::pinMode(pin, OUTPUT);
    }

    void digitalWrite(bool value);

    bool digitalRead(uint8_t pin);
};