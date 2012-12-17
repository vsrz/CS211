/// Lab03.cpp - Student.cpp
//  Program 1: Collection of Students
//
//  By Jeremy Villegas
//  Cal State San Marcos - CS211
//  09/25/2006
///

#ifndef Student_cpp
#define Student_cpp

#include "Includes.h"
#include "Student.h"

void Student::SetStudentNo(ClassData c)
{
  Stno = c.Stno;
  Course1.SetCourseNum(c.Cnum1);
  Course1.SetCourseName(c.Cname1);  
  Course2.SetCourseNum(c.Cnum2);
  Course2.SetCourseName(c.Cname2);  
  Course3.SetCourseNum(c.Cnum2);
  Course3.SetCourseName(c.Cname3);
}
void Student::PrintStudent()
{
  cout << "Student Number : " << Stno << endl;
  Course1.PrintCourse();
  Course2.PrintCourse();
  Course3.PrintCourse();
}

#endif
