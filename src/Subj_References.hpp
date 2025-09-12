#include <Arduino.h>

#ifndef Subj_References_h
#define Subj_References_h

// Create Class Subject

class Subject{
  public:
  String Name;
  byte PinAddress;
  bool state;
    Subject::Subject(String Subj_Name, byte PinAddress)
    {
      Name = Subj_Name;
      this->PinAddress = PinAddress;
    };
};

// The Subject Pool, an array contaning all objects

extern Subject SubjectPool[17];

// Helper lookup function

Subject* getSubject(const char* name) {
    for (auto& subj : SubjectPool) {
        if (subj.Name == name) return &subj;
    }
    return nullptr;
}

extern Subject* Sarr[5][7];

#endif
