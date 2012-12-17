/// Lab03.cpp
//  Program 1: Collection of Students
//
//  By Jeremy Villegas
//  Cal State San Marcos - CS211
//  09/25/2006
///

#ifndef StudentCollection_cpp
#define StudentCollection_cpp

#include "Includes.h"
#include "StudentCollection.h"

void StudentCollection::ReadStudentData()
{
  // Open Filestream
  ifstream fin;
  fin.open("data.txt");
  if (!fin.is_open()) exit(1);
  
  // Read Datafile
  while(!fin.eof())
  {    
    PersonData p;
    ClassData c;
    StudentProfile s;

    fin >> p.Lname >> p.Fname >> p.Age >> p.Gender >> p.SSN >> c.Stno;
    fin >> c.Cnum1 >> c.Cname1;
    fin >> c.Cnum2 >> c.Cname2;
    fin >> c.Cnum3 >> c.Cname3;

    s.CreateStudentProfile(p, c);
    StCollection.push_back(s);
  }

  // Close File
  fin.close();
  return;

}

void StudentCollection::PrintStudentData()
{
  // Loop through Vector
  for (int x = 0; x < (int)StCollection.size(); x++)
  {
    // Call StudentProfile Print
    StCollection[x].PrintStudentProfile();
    cout << endl;
    
  }

  return;
}

#endif
