/**
 * Project    : Assignment 3 -
 * File       : Faculty.h
 * Programmer : Jeremy Villegas <ville017@csusm.edu>
 * Date       : 11/13/2006
 * School     : CSU San Marcos - CS211 A. Hadaegh, S. Holt
 *
 * Includes   : Person.h
 * Purpose    : Data representation of faculty, header
 **/

#ifndef FACULTY_H
#define FACULTY_H

#include "Person.h"

class Faculty : public Person
{
  protected:
    float salary;
    int yearsOfExp;
    long departmentId;
    static long nextFacultyId;
  public:
    // Print faculty
    void print() const;
    void printBasicInfo() const;

    // Get/Set Salary
    float getSalary(){return salary;};
    void setSalary(float salary){this->salary = salary;};
    
    // Get/Set Years o' Exp
    int getYearsOfExp(){return yearsOfExp;};
    void setYearsOfExp(int yearsOfExp){this->yearsOfExp = yearsOfExp;};

    // Get/Set DepartmentId
    long getDepartmentId(){return departmentId;};
    void setDepartmentId(long departmentId){this->departmentId = departmentId;};

    // Get Next Faculty ID 
    static long getFacultyId(){ return nextFacultyId; };

    // Constructor/Destructor
    Faculty();
    Faculty(string fName, string fEmail, string fAddress, string fDateOfBirth,
      string fGender, float fSalary, int fYearOfExp, long fDepId);
    ~Faculty(){};
};

#endif
