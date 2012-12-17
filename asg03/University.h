/**
 * Project    : Assignment 3
 * File       : University.h
 * Programmer : Jeremy Villegas <ville017@csusm.edu>
 * Date       : 11/13/2006
 * School     : CSU San Marcos - CS211 A. Hadaegh, S. Holt
 *
 * Includes   : Student.h, Department.h, Faculty.h
 * Purpose    : Standard University Implementation, header
 **/

#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "Student.h"
#include "Department.h"
#include "Faculty.h"

const string COMMAND_LIST[21] = {"CreateNewDepartment", "RemoveADepartment",
      "CreateNewStudent","RemoveAStudent","CreateNewCourse","RemoveACourse",
      "CreateNewFaculty","RemoveAFaculty","ListCoursesTaughtByFaculty",
      "ListCoursesTakenByStudent","ListFacultiesInDepartment",
      "ListStudentsOfAFaculty","ListCoursesOfADepartment",
      "AddACourseForAStudent","DropACourseForAStudent","AssignDepartmentChair",
      "AssignInstructorToCourse","ListDepartments","ListStudents",
      "ListCourses","ListFaculties"};

const int NUM_PARAMS[21] = {3,1,8,1,4,1,8,1,1,1,1,1,1,2,2,2,2,0,0,0,0};

class University  
{
  protected:
	  vector<Department> Departments;
	  vector<Student> Students;
	  vector<Course> Courses;
	  vector<Faculty> Faculties;
	  static bool failure;
	  static bool success;
  public:
    University(){};
    ~University(){};
  	
    // Department
	  bool CreateNewDepartment(string depName, string depLoc, long depChairId);
	  bool RemoveADepartment(long depId);
	  bool AssignDepartmentChair(long facultyId, long departId);
	  bool ListDepartments();
    long departmentIsValid(long departId);

    // Students
	  bool CreateNewStudent(string sName, string sEmail, string sAddress, 
      string sDateOfBirth, string sGender,int sYearOfStudy, string sMajor, 
      long sAdvisorId);
	  bool RemoveAStudent(long sStId);
	  bool ListStudentsOfAFaculty(long facultyId);
	  bool AddACourseForAStudent(long courseId, long stId);
	  bool DropACourseForAStudent(long courseId, long stId);
	  bool ListStudents();
    long studentIsValid(long studentId);

    // Courses
    bool CreateNewCourse(string cName, long cDepId, long cTaughtBy, 
      int cMaxSeat);
	  bool RemoveACourse(long cCRN);
	  bool ListCoursesTaughtByFaculty(long facultyId);
	  bool ListCoursesTakenByStudent(long studentId);
	  bool ListCoursesOfADepartment(long departId);
	  bool AssignInstructorToCourse (long facultyId, long courseId);
	  bool ListCourses();
    long courseIsValid(long courseId);

    // Faculties
	  bool CreateNewFaculty(string fName, string fEmail, string fAddress, 
      string fDateOfBirth, string fGender, float fSalary, int fYearOfExp, 
      long fDepId);
	  bool RemoveAFaculty(long fFactId);
	  bool ListFacultiesInDepartment (long departId);
	  bool ListFaculties();
    long facultyIsValid(long facultyId);

    // General UnivUtils
    bool ProcessTransactionFile(string fileName);
    void DisplayErrorMessage(string fn, string id);
    void DisplayErrorMessage(string fn, long id);
};

#endif
