/// Lab03.cpp - Includes.h
//  Program 1: Collection of Students
//
//  By Jeremy Villegas
//  Cal State San Marcos - CS211
//  09/25/2006
//
//  List of Include Files for all Projects
///

#ifndef Includes_h
#define Includes_h

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct PersonData
{
  string Lname, Fname;
  int Age;
  char Gender;
  long SSN;
};

struct ClassData
{
  long Stno, Cnum1, Cnum2, Cnum3;
  string Cname1, Cname2, Cname3;
};

#endif
