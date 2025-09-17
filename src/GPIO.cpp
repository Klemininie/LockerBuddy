// Did you know Jesus will come back. But He loves you so go to Him now...


#include "GPIO.h"

    void obj::digitalWrite(bool value)
    {
        if (pin == 0 || pin == 1 || pin == 13) return;

        if(pin >= 2 && pin <= 7){       //PORTD pins 2-7 only
            if (value) { PORTD |= (1 << pin); }
            else { PORTD &= ~(1 << pin); }
        }

        else if(pin >= 8 && pin <= 12 ){   //PORTB pins 8-12 only
            if (value) { PORTB |= (1 << (pin - 8)); }
            else { PORTB &= ~(1 << (pin - 8)); }
        }
    }

    bool obj::digitalRead(uint8_t pin)
    {
        if(pin == 0 || pin == 1 || pin == 13) return false; // blocked pins

        if(pin >= 2 && pin <= 7)        return PIND & (1 << pin);
        else if(pin >= 8 && pin <= 12)  return PINB & (1 << (pin - 8));
        else if(pin >= 14 && pin <= 19) return PINC & (1 << (pin - 14));

        return false;
    }