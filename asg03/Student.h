/**
 * Project    : Assignment 3 -
 * File       : Student.h
 * Programmer : Jeremy Villegas <ville017@csusm.edu>
 * Date       : 11/13/2006
 * School     : CSU San Marcos - CS211 A. Hadaegh, S. Holt
 *
 * Includes   : Person.h, Course.h
 * Purpose    : Basic representation of a student, header
 **/

#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include "Course.h"


class Student : public Person
{
  protected:    
    int yearOfStudy;
    string major;
    long advisorId;
    vector<Course> coursesTaken;
    static long nextStudentId;
  public:
    // Print Student and ID Only
    void printBasicInfo() const;

    // Get/Set Year Of Study
    int getYearOfStudy(){return yearOfStudy;};
    void setYearOfStudy(int yearOfStudy){this->yearOfStudy = yearOfStudy;};

    // Get/Set + Associated Functions for CoursesTaken
    vector<Course> getCoursesTaken(){return coursesTaken;};
    void addCoursesTaken(Course coursesTaken){
      this->coursesTaken.push_back(coursesTaken);};
    int isCourseTaken(long crn);
    void dropAllCourses(){coursesTaken.clear();};
    bool dropACourse(long crn);
    vector<int> getCourseCrnsTaken();

    // Get/Set AdvisorID
    long getAdvisorId(){return advisorId;};
    void setAdvisorId(long advisorId){this->advisorId = advisorId;};

    // Get Next Student ID
    static long getNextStudentId(){ return nextStudentId;};

    // Constructor/Destructor
    Student();
    Student(string sName, string sEmail, string sAddress, string sDateOfBirth,
      string sGender, int sYearOfStudy, string sMajor, long sAdvisorId);
    ~Student(){};
};


#endif