/// Lab03.cpp - StudentProfile.h
//  Program 1: Collection of Students
//
//  By Jeremy Villegas
//  Cal State San Marcos - CS211
//  09/25/2006
///

#ifndef StudentProfile_h
#define StudentProfile_h

#include "Includes.h"
#include "Person.h"
#include "Student.h"

class StudentProfile
{
  private:
    Person PersonalInfo;
    Student StdInfo;
   
  public:
    void CreateStudentProfile(PersonData p, ClassData c);
    void PrintStudentProfile();
};

#endif
