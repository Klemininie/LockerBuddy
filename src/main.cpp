#include <Arduino.h>
#include <Wire.h>

enum SchDay{
  Mon, Tue, Wed, Thu, Fri
};

// Create Class Subject
class Subject{
  public:
  String Name;
  byte PinAddress;
  bool state;

  Subject(String Subj_Name, byte PinAddress)
  {
    Name = Subj_Name;
    this->PinAddress = PinAddress;
  };
};


// The Subject Pool

Subject SubjectPool[] = {

SubjectPool("SCL", 0x1),
SubjectPool("Health", 0x2),
SubjectPool("Mathematics", 0x3),
SubjectPool("TLE", 0x4),
SubjectPool("Homeroom", 0x5),
SubjectPool("Computer", 0x6),
SubjectPool("Advanced Statistics", 0x7),
SubjectPool("Araling Panlipunan", 0x8),
SubjectPool("Filipino", 0x9),
SubjectPool("English", 0xA),
SubjectPool("Arts", 0xB),
SubjectPool("Science", 0xC),
SubjectPool("Music", 0xD),
SubjectPool("Physical Education", 0xE),
SubjectPool("Values Education", 0xF),
SubjectPool("Health", 0x10),
SubjectPool("Enrichment", 0x11)
};

Subject* getSubject(const char* name) {
    for (auto& subj : SubjectPool) {
        if (subj.Name == name) return &subj;
    }
    return nullptr;
}

Subject* Sarr[5][7] = {
    {getSubject("SCL"), getSubject("Health"), getSubject("TLE"), getSubject("TLE"), getSubject("Computer"), getSubject("Advanced Statistics"), getSubject("Araling Panlipunan")},
    {getSubject("Filipino"), getSubject("Araling Panlipunan"), getSubject("English"), getSubject("Arts"), getSubject("Science"), getSubject("Mathematics"), getSubject("Enrichment")},
    {getSubject("Filipino"), getSubject("Science"), getSubject("English"), getSubject("Music"), getSubject("Physical Education"), getSubject("Mathematics"), getSubject("TLE")},
    {getSubject("Filipino"), getSubject("Science"), getSubject("English"), getSubject("Values Education"), getSubject("Araling Panlipunan"), getSubject("Mathematics"), getSubject("Enrichment")},
    {getSubject("Filipino"), getSubject("Science"), getSubject("English"), getSubject("Values Education"), getSubject("Computer"), getSubject("Mathematics"), nullptr}
};

// Create RFID stuff for RC522
// I need to know pins first

class RFid {

  byte IRQ;
  byte Transmit;
  byte Receive;

  void Write(int t)
  {
  Wire.begin();
  Wire.write(t);
  Wire.end();
  }

  void Read(int t)
  {
  Wire.begin();
  Wire.write(t);
  Wire.end();
  }
};

class Relay{
  byte pib;
  byte state;
};

void setup()
{

}

void loop()
{

}