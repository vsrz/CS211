#ifndef CompSciProfessor_H
#define CompSciProfessor_H

#include <string>

using namespace std;

class CompSciProfessor
{
  protected:
    string name;
    string email;
    long facultyID;
  public:
    string GetName(){return name;} 
    string GetEmail(){return email;} 
    long   GetFacultyID(){return facultyID;};
    void   SetName(string name){this->name = name;}
    void   SetEmail(string email){this->email = email;}
    void   SetFacultyID(long facultyID){this->facultyID = facultyID;}

};  
#endif
 
