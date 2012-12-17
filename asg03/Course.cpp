/**
 * Project    : Assignment 3 -
 * File       : Course.cpp
 * Programmer : Jeremy Villegas <ville017@csusm.edu>
 * Date       : 11/13/2006
 * School     : CSU San Marcos - CS211 A. Hadaegh, S. Holt
 *
 * Includes   : Includes.cpp
 * Purpose    : Structure for Courses
 **/

#ifndef COURSE_CPP
#define COURSE_CPP

#include "Course.h"

/// Sets starting value for "computer generated" CRN
long Course::nextCrn = 200;


/// Constrctor which sets values given
Course::Course(string cName, long cDepId, long cTaughtBy, int cMaxSeat)
{
  crn = nextCrn++;
  assignedSeats = 0;
  name = cName;
  departmentId = cDepId;
  isTaughtBy = cTaughtBy;
  maximumAvailableSeats = cMaxSeat;
}


/// Prints detailed report of Course
void Course::print() const
{
  cout << "Course Information" << endl;
  cout << "==================" << endl;
  cout << "CRN/Name    : (" << crn << ") " << name << endl;
  cout << "Seats       : " << assignedSeats << "/" <<
    maximumAvailableSeats << endl;
  cout << "Department  : " << departmentId << endl;
  cout << "Teacher ID  : " << isTaughtBy << endl;
  cout << endl << endl;
}

bool Course::incrementSeats()
{
  // Check for available space 
  if (assignedSeats+1 <= maximumAvailableSeats)
  {
    assignedSeats++;
    return true;
  }
  // No space available
  return false;
}

/// Prints a one-liner with course reference number and name
void Course::printBasicInfo() const
{
  cout << name << " (" << crn << ")" << endl;
}


#endif
