/**
 * Project    : Assignment 3 -
 * File       : Student.cpp
 * Programmer : Jeremy Villegas <ville017@csusm.edu>
 * Date       : 11/13/2006
 * School     : CSU San Marcos - CS211 A. Hadaegh, S. Holt
 *
 * Includes   : Includes.h, Course.h
 * Purpose    : Basic representation of a student, code
 **/

#ifndef STUDENT_CPP
#define STUDENT_CPP

#include "Student.h"


/// Default value of computer generated student ID
long Student::nextStudentId = 500;


/// Default constructor, increments ID
Student::Student()
{
  id = nextStudentId++;
}


/// Constrctor which sets values given
Student::Student(string sName, string sEmail, string sAddress, 
                 string sDateOfBirth, string sGender, int sYearOfStudy, 
                 string sMajor, long sAdvisorId)
{
  name = sName;
  email = sEmail;
  address = sAddress;
  dateOfBirth = sDateOfBirth;
  gender = sGender;
  yearOfStudy = sYearOfStudy;
  major = sMajor;
  advisorId = sAdvisorId;
  id = nextStudentId++;
}


/// Returns value containing index of the course passed, 0 if non-existant
int Student::isCourseTaken(long crn)
{
  // Loop through each course taken
  for (int x = 0; x < (int)coursesTaken.size(); x++)
    if (crn == coursesTaken[x].getCrn())
      return x; // Found!  Return true
  return 0;    // Not found!  Slacker!
}

/// Returns a vector containing the Courses taken
vector<int> Student::getCourseCrnsTaken()
{
  vector<int> cIndex;  // Temporary storage for vector

  // Get each courseId from the coursesTaken list
  for (int x = 0; x < (int)coursesTaken.size(); x++)
    cIndex.push_back(coursesTaken[x].getCrn());
  
  return cIndex;
}

/// Drops course specified by CRN, returns false if failed
bool Student::dropACourse(long crn)
{
  int crnIndex = isCourseTaken(crn);

  // If it exists, we kill it.
  if (crnIndex > 0)
  {
    coursesTaken.erase(coursesTaken.begin() + crnIndex);
    return true;
  }
  return false;
}


/// Prints a one-liner containing the name, and ID of a student
void Student::printBasicInfo() const
{
  cout << name << " (" << id << ")" << endl;
}

#endif
