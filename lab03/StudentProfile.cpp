/// Lab03.cpp - StudentProfile.cpp
//  Program 1: Collection of Students
//
//  By Jeremy Villegas
//  Cal State San Marcos - CS211
//  09/25/2006
///

#ifndef StudentProfile_cpp
#define StudentProfile_cpp

#include "Includes.h"
#include "StudentProfile.h"

void StudentProfile::CreateStudentProfile(PersonData p, ClassData c)
{
  // Set Properties for Person
  PersonalInfo.SetLname(p.Lname);
  PersonalInfo.SetFname(p.Fname);
  PersonalInfo.SetGender(p.Gender);
  PersonalInfo.SetAge(p.Age);
  PersonalInfo.SetSSN(p.SSN);

  // Set Properties for Student / Pass Course Info
  StdInfo.SetStudentNo(c);
  
}

void StudentProfile::PrintStudentProfile()
{
  // Call Print of Personal Info Member
  PersonalInfo.PrintPerson();

  // Call Print of Student Info Members
  StdInfo.PrintStudent();
  
}

#endif
