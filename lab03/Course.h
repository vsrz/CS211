/// Lab03.cpp - Course.h
//  Program 1: Collection of Students
//
//  By Jeremy Villegas
//  Cal State San Marcos - CS211
//  09/25/2006
///

#ifndef Course_h
#define Course_h

#include "Includes.h"

class Course
{
  private:
    long CourseNum;
    string CourseName;

  public:
    void SetCourseNum(long CourseNum);
    void SetCourseName(string CourseName);
    void PrintCourse();
};

#endif
