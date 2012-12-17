/**
 * Project    : Assignment 3 -
 * File       : Faculty.cpp
 * Programmer : Jeremy Villegas <ville017@csusm.edu>
 * Date       : 11/13/2006
 * School     : CSU San Marcos - CS211 A. Hadaegh, S. Holt
 *
 * Includes   : Faculty.h
 * Purpose    : Data representation of Faculty, code
 **/

#ifndef FACULTY_CPP
#define FACULTY_CPP

#include "Faculty.h"

/// Default value of computer generated faculty ID
long Faculty::nextFacultyId = 600;

/// Default constructor, set values later
Faculty::Faculty()
{
  id = nextFacultyId++;
}

/// Constrctor which sets values given
Faculty::Faculty(std::string fName, std::string fEmail, std::string fAddress,
                 std::string fDateOfBirth, std::string fGender, float fSalary,
                 int fYearOfExp, long fDepId)
{
  id = nextFacultyId++;
  name = fName;
  email = fEmail;
  address = fAddress;
  dateOfBirth = fDateOfBirth;
  gender = fGender;
  salary = fSalary;
  yearsOfExp = fYearOfExp;
  departmentId = fDepId;
}

/// Prints detailed report of department
void Faculty::print() const
{
  cout << "Faculty Information" << endl;
  cout << "===================" << endl;
  cout << "Name (ID) : " << name << "(" << id << ")"  << endl;
  cout << "Experience: " << yearsOfExp << " years" << endl;
  cout << "Salary    : " << "$" << salary << endl << endl; 
}

/// Prints a one-liner with faculty name and ID
void Faculty::printBasicInfo() const
{
  cout << name << " (" << id << ")" << endl;
}

#endif
