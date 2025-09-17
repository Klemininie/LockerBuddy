#include <Arduino.h>
#include "GPIO.h"
#include <MFRC522.h>
#include <SPI.h>

#define SS_PIN 8    //Pin 8 = select pin; Pin 7 = reset pin
#define RST_PIN 7
#define RelayO1 6   // Pin for obj 1 and obj 2
#define RelayO2 5
#define DELAY_OPEN 1000

const byte security_uid[4] = {0x3F, 0xA6, 0xBB, 0xDE };
uint16_t security_uid_size = sizeof(security_uid) / sizeof(security_uid[0]);

MFRC522 rfid(SS_PIN, RST_PIN);

obj arr_of_relays_in_project[] = {obj(RelayO1), obj(RelayO2)}; // Array of objs
const obj (&relays)[2] = arr_of_relays_in_project;             // reference to array

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

//                                Turn On objs
template <typename T, int N>
inline void on_obj(const T (&arrobj)[N]){ // Pass a reference as an array arrobj
  for(obj& rr : arrobj)                   // For each rr of arrobj, digitalWrite
  {
    rr.digitalWrite(HIGH);
  }
}

//                                 Vice versa
template <typename T, int N>
inline void off_obj(const T (&arr)[N]){
  for(const obj& rr : arr)
  {
    rr.digitalWrite(LOW);
  }
}

bool auth_uid(){
  for (byte i = 0; i < rfid.uid.size; i++){
    if (rfid.uid.uidByte[i] != security_uid[i]){
      return false;
    }
  }
  return true;
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

  if (auth_uid()) Serial.println("Access Granted");
  else Serial.println("Access Denied");

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}