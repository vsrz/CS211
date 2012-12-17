/**
 * Project    : Assignment 3 -
 * File       : Person.h
 * Programmer : Jeremy Villegas <ville017@csusm.edu>
 * Date       : 11/13/2006
 * School     : CSU San Marcos - CS211 A. Hadaegh, S. Holt
 *
 * Includes   : Includes.h
 * Purpose    : Basic computer representation of a person, header
 **/

#ifndef PERSON_H
#define PERSON_H

#include "Includes.h"

class Person
{
  protected:  
    long id;
    string name;
    string email;
    string address;
    string dateOfBirth;
    string gender;
  public:
    // Get/Set ID
    long getId(){return id;};
    void setId(long id){this->id = id;};

    // Get/Set Name
    string getName(){return name;};
    void setName(string name){this->name = name;};

    // Get/Set Email
    string getEmail(){return email;};
    void setEmail(string email){this->email = email;};

    // Get/Set Address
    string getAddress(){return address;};
    void setAddress(string address){this->address = address;};

    // Get/Set DateOfBirth
    string getDateOfBirth(){return dateOfBirth;};
    void setDateOfBirth(string dateOfBirth){this->dateOfBirth = dateOfBirth;};

    // Get/Set Gender
    string getGender(){return gender;};
    void setGender(string gender){this->gender = gender;};

    // Constructor/Destructor
    Person(){};
    ~Person(){};
};

#endif