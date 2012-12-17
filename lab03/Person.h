/// Lab03.cpp - Person.h
//  Program 1: Collection of Students
//
//  By Jeremy Villegas
//  Cal State San Marcos - CS211
//  09/25/2006
///

#ifndef Person_h
#define Person_h

#include "Includes.h"

class Person
{
  private:
    long SSN;
    string Fname, Lname;
    int Age;
    char Gender; // 'M' for male, 'F' for female

  public:
    void SetSSN(long SSN);
    void SetFname(string Fname);
    void SetLname(string Lname);
    void SetAge(int Age);
    void SetGender(char Gender);
    void PrintPerson();
};
#endif
