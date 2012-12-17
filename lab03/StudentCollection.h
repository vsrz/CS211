/// Lab03.cpp -- StudentCollection.h
//  Program 1: Collection of Students
//
//  By Jeremy Villegas
//  Cal State San Marcos - CS211
//  09/25/2006
///

#ifndef StudentCollection_h
#define StudentCollection_h

#include "Includes.h"
#include "StudentProfile.h"

class StudentCollection
{
  private:
    vector<StudentProfile> StCollection; 
  public:
		void ReadStudentData();
    void PrintStudentData();
};

#endif
