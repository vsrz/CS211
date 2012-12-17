/// Lab03.cpp
//  Program 1: Collection of Students
//
//  By Jeremy Villegas
//  Cal State San Marcos - CS211
//  09/25/2006
///

#ifndef Student_h
#define Student_h

#include "Includes.h"
#include "Course.h"

class Student
{
  private:
    long Stno;
    Course Course1;
    Course Course2;
    Course Course3;
  public:	  
    void SetStudentNo(ClassData c);
    void PrintStudent();
};

#endif
