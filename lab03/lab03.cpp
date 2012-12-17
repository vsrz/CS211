/// Lab03.cpp
//  Program 1: Collection of Students
//
//  By Jeremy Villegas
//  Cal State San Marcos - CS211
//  09/25/2006
///

#ifndef lab03_cpp
#define lab03_cpp

#include "Includes.h"
#include "StudentCollection.h"

int main()
{
  StudentCollection Students;
  
  Students.ReadStudentData();
  Students.PrintStudentData();

  cout << endl;
  system("pause");
  
  return 0;
}
#endif
