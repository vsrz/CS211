/// lab03.cpp -- Course.cpp
//  Program 1: Collection of Students
//
//  By Jeremy Villegas
//  Cal State San Marcos - CS211
//  09/25/2006
///

#ifndef Course_cpp
#define Course_cpp

#include "Includes.h"
#include "Course.h"

void Course::SetCourseNum(long CourseNum)
{
  this->CourseNum = CourseNum;
  return;
}

void Course::SetCourseName(string CourseName)
{
  this->CourseName = CourseName;
  return;
}

void Course::PrintCourse()
{
  cout << "Course         : " << CourseNum << " - " << CourseName << endl;
  return;
}
#endif
