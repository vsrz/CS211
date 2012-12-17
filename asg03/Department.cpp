/**
 * Project    : Assignment 3 -
 * File       : Department.cpp
 * Programmer : Jeremy Villegas <ville017@csusm.edu>
 * Date       : 11/13/2006
 * School     : CSU San Marcos - CS211 A. Hadaegh, S. Holt
 *
 * Includes   : Includes.h, Dictionary.h
 * Purpose    : Data representation of a department, code
 **/

#ifndef DEPARTMENT_CPP
#define DEPARTMENT_CPP

#include "Department.h"

long Department::nextDepartmentId = 100;

/// Constrctor which sets values given
Department::Department(string name, string location, long chairId)
{
  setName(name);
  setLocation(location);
  setChairId(chairId);
  setId(nextDepartmentId++);
}


/// Prints detailed report of department
void Department::print() const
{
  cout << "Department Information" << endl;
  cout << "======================" << endl;
  cout << "Name (ID) : " << name << "(" << id << ")"  << endl;
  cout << "Location  : " << location << endl;
  cout << "Chair ID  : " <<  chairId << endl << endl;
}


/// Prints a one-liner with dept name and ID Number
void Department::printBasicInfo() const
{
  cout << name << " (" << id << ")" << endl;
}

#endif
