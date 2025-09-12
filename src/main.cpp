#include <Arduino.h>

#include <MFRC522.h>
#include <SPI.h>

#define p_sel 8   //Pin 8 = select pin; Pin 3 = reset pin
#define p_rst 7

 MFRC522 rfid(p_sel, p_rst);

class Relay{
public:
  const byte pin;
  bool state;
    Relay(byte pin) : pin(pin) {state = false;}
};

class ShiftReg{
protected: static byte _CLCK, _RCLCK, _SCLR;
public:
  struct {  //  Chip select, clock. register clock, serial, and serial hard clear
    byte _CS, _SER;
  } pins;

  ShiftReg(byte _CS, byte _CLCK, byte _RCLCK, byte _SER, byte _SCLR) :
    pins{_CS, _SER} {}
};

//  Utils
inline void SS(ShiftReg* ss){digitalWrite(ss->pins._CS, true);}
inline void on_relay(Relay rr){digitalWrite(rr.pin, true);}
inline void off_relay(Relay rr){digitalWrite(rr.pin, false);}


void setup()
{
  SPI.begin();

}

void loop()
{
static byte response;

}