/// Lab03.cpp - Person.cpp
//  Program 1: Collection of Students
//
//  By Jeremy Villegas
//  Cal State San Marcos - CS211
//  09/25/2006
///

#ifndef Person_cpp
#define Person_cpp

#include "Person.h"

void Person::SetSSN(long SSN)
{
  this->SSN = SSN;
  return;
}

void Person::SetFname(string Fname)
{
  this->Fname = Fname;
  return;
}

void Person::SetLname(string Lname)
{
  this->Lname = Lname;
  return;
}

void Person::SetAge(int Age)
{
  this->Age = Age;
  return;
}

void Person::SetGender(char Gender)
{
  this->Gender = Gender;
  return;
}

void Person::PrintPerson()
{
  cout << "Name/Age/Gender: " << Lname << ", " << Fname 
    << " / " << Age << " / " << Gender << endl;
  cout << "SSN            : " << SSN << endl;

  return;
}
  
#endif
