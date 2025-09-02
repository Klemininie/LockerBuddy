#include <Arduino.h>

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

struct 


// The Subject Pool
Subject Elec2("SCL", 0x1);
Subject Hlth("Health", 0x2);
Subject Math("Mathematics", 0x3);
Subject _Tle("TLE", 0x4);
Subject Hmrm("Homeroom", 0x5);
Subject Comp("Computer", 0x6);
Subject Elec1("Advanced Statistics", 0x7);
Subject ArlP("Araling Panlipunan", 0x8);
Subject Fili("Filipino", 0x9);
Subject Engl("English", 0xA);
Subject Arts("Arts", 0xB);
Subject Scnce("Science", 0xC);
Subject Music("Music", 0xD);
Subject PysEd("Physical Education", 0xE);
Subject ValEd("Values Education", 0xF);
Subject Health("Health", 0x10);
Subject Enrch("Enrichment", 0x11);

Subject* Sarr[5][7] = {
  {&Elec2, &Hlth, &_Tle, &_Tle, &Comp, &Elec1, &ArlP},  //Monday
  {&Fili, &ArlP, &Engl, &Arts, &Scnce, &Math, &Enrch},  //Tuesday
  {&Fili, &Scnce, &Engl, &Music, &PysEd, &Math, &_Tle},  //Wednesday
  {&Fili, &Scnce, &Engl, &ValEd, &ArlP, &Math, &Enrch},  //Thursday
  {&Fili, &Scnce, &Engl, &ValEd, &Comp, &Math, nullptr} //Friday (nullptr == no subj)
};

// Create RFID stuff for RC522
// Create IO Ext stuff for 

void setup()
{

}

void loop()
{

}