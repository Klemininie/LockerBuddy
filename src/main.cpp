#include <Arduino.h>
#include <MFRC522.h>
#include <SPI.h>

#define SS_PIN 8    //Pin 8 = select pin; Pin 7 = reset pin
#define RST_PIN 7
#define RR1 6   // Pin for relay 1 and relay 2
#define RR2 5
#define DELAY_OPEN 1000

const byte security_uid[4] = {0x3F, 0xA6, 0xBB, 0xDE };
uint16_t security_uid_size = sizeof(security_uid) / sizeof(security_uid[0]);

MFRC522 rfid(SS_PIN, RST_PIN);

class Relay{
public:
  const byte pin;
  bool state;
    Relay(byte pin) : pin(pin) {state = false;}
};
const Relay arr[] = {Relay(RR1), Relay(RR2)};

/*class ShiftReg{        //DEPRECATED (NO SHIFT REGISTER FOR NOW...)
protected: static byte _CLCK, _RCLCK, _SCLR;
public:
  struct {  //  Chip select, clock. register clock, serial, and serial hard clear
    byte _CS, _SER;
  } pins;

  ShiftReg(byte _CS, byte _CLCK, byte _RCLCK, byte _SER, byte _SCLR) :
    pins{_CS, _SER} {}
};
inline void Shift(ShiftReg* SS){digitalWrite(SS->pins._CS, true);}*/ 

////////////////////////////////////////////////////////////////////////////////////////
//                           Project Utility Functions 
////////////////////////////////////////////////////////////////////////////////////////

//                                Turn On Relays
inline void on_relay(const Relay (&arr)[2]){ // Pass a reference to an array arr with 2 members
  for(const Relay& rr : arr)                 // For each pin rr of arr, use it for digitalWrite
  {
    digitalWrite(rr.pin, HIGH);
  }
}

//                                  Vice versa
inline void off_relay(const Relay (&arr)[2]){
  for(const Relay& rr : arr)
  {
    digitalWrite(rr.pin, false);
  }
}

bool auth_uid(){
  bool match = true;
  for (byte i; i < rfid.uid.size; i++){
    if (rfid.uid.uidByte[i] != security_uid[i]){
      match = false;
      break;
    }

  }
  return match;
}

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();   
}

void loop()
{
  if (!rfid.PICC_IsNewCardPresent()) return; // Waits for new card

  if (!rfid.PICC_ReadCardSerial()) return;

  if (auth_uid) Serial.println("Access Granted");
  else Serial.println("Access Denied");

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}