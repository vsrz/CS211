/**
 * Project    : Assignment 3 -
 * File       : Course.h
 * Programmer : Jeremy Villegas <ville017@csusm.edu>
 * Date       : 11/13/2006
 * School     : CSU San Marcos - CS211 A. Hadaegh, S. Holt
 *
 * Includes   : Includes.h
 * Purpose    : 
 **/

#ifndef COURSE_H
#define COURSE_H

#include "Includes.h"

class Course
{
  protected:
    long crn;
    int maximumAvailableSeats;
    string name;
    long departmentId;
    long assignedSeats;
    long isTaughtBy;
    static long nextCrn;
  public:
    // Print Course ID
    void print() const;
    void printBasicInfo() const;

    // Get/Set CRN
    long getCrn(){return crn;};
    void setCrn(long crn){this->crn = crn;};
    
    // Get/Set CourseName
    string getName(){return name;};
    void setName(string name){this->name = name;};
    
    // Get/Set Course Department ID
    long getDepartmentId(){return departmentId;};
    void setDepartmentId(long departmentId)
      {this->departmentId = departmentId;};

    // Get/Set Seats assigned
    long getAssignedSeats(){return assignedSeats;};
    void setAssignedSeats(long assignedSeats)
      {this->assignedSeats = assignedSeats;};
    bool incrementSeats();
    void decrementSeats(){assignedSeats--;};

    // Get/Set Teacher
    long getIsTaughtBy(){return isTaughtBy;};
    void setIsTaughtBy(long isTaughtBy){this->isTaughtBy = isTaughtBy;}

    // Get nextCRN     
    static long getNextCrn(){ return nextCrn; };
    
    // Constructor/Destructor
    Course(){crn = nextCrn++;};
    Course(string cName, long cDepId, long cTaughtBy, int cMaxSeat);
    ~Course(){};
};

#endif