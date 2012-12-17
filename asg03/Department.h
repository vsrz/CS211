/**
 * Project    : Assignment 3 -
 * File       : Department.h
 * Programmer : Jeremy Villegas <ville017@csusm.edu>
 * Date       : 11/13/2006
 * School     : CSU San Marcos - CS211 A. Hadaegh, S. Holt
 *
 * Includes   : Includes.h, Dictionary.h
 * Purpose    : Data representation of a department, header
 **/

#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Includes.h"

class Department
{
  protected:
    long id;
    string name;
    string location;
    long chairId;
    static long nextDepartmentId;
  public:
    // Print Method
    void print() const;
    void printBasicInfo() const;

    // Get/Set ID
    long getId(){return id;};
    void setId(long id){this->id = id;};
    
    // Get/Set Name
    string getName(){return name;};
    void setName(string name){this->name = name;};

    // Get/Set Location
    string getLocation(){return location;};
    void setLocation(string location){this->location = location;};

    // Get/Set ChairID
    long getChairId(){return chairId;};
    void setChairId(long chairId){this->chairId = chairId;};

    // Department ID
    static long getNextDepartmentId(){ return nextDepartmentId;};

    // Constructor/Destructor
    Department(){ nextDepartmentId++;};
    Department(string name, string location, long chairId);
    ~Department(){};
};

#endif