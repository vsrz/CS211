/**
 * Project    : Assignment 3
 * File       : University.h
 * Programmer : Jeremy Villegas <ville017@csusm.edu>
 * Date       : 11/13/2006
 * School     : CSU San Marcos - CS211 A. Hadaegh, S. Holt
 *
 * Includes   : University.h
 * Purpose    : Standard University implementation, code
 **/

#ifndef UNIVERSITY_CPP
#define UNIVERSITY_CPP

#include "University.h"


/// Failure/success declarations
bool University::failure = false;
bool University::success = true;


/// Creates a new department
bool University::CreateNewDepartment(string depName, string depLoc, long depChairId)
{
  bool found = false;  // Check to see if we have a valid dept chair
  if (depChairId != 0)
  {
    // Check if faculty ID exists
    for (int x = 0; x < (int)Faculties.size(); x++)
      if (depChairId == Faculties[x].getId())
        found = true;
    
    // If not exist return failure
    if (!found) return failure;
  }

  // Was an existing faculty member, continue.
  Department d(depName, depLoc, depChairId);
  Departments.push_back(d);
  return success;
}
  

/// Removes a department, but checks for any majors, courses, or faculty first
bool University::RemoveADepartment(long depId)
{
  bool found = false; // Did we find a faculty/student/course association?

  // Loop through each department
  for (int x = 0; x < (int)Departments.size(); x++)
  {
    // Check for a match
    if (depId == Departments[x].getId())
    {
      // Any faculty have this department ID?
      for (int y = 0; y < (int)Faculties.size(); y++)
        if (Departments[x].getId() == Faculties[y].getDepartmentId())
          found = true;

      // Are any students in this major?
      for (int y = 0; y < (int)Students.size(); y++)
        if (Departments[x].getName() == Students[y].getName())
          found = true;

      // Any courses have this department ID?
      for (int y = 0; y < (int)Courses.size(); y++)
        if (Departments[x].getId() == Courses[y].getDepartmentId())
          found = true;
      
      // No faculty/students/courses conflict, so go ahead and delete
      if (found == false)
      {
        Departments.erase(Departments.begin()+x);
        return success;
      }
    }
  }
  return failure;
}


/// Creates a new student
bool University::CreateNewStudent(string sName, string sEmail, string sAddress,
                                  string sDateOfBirth, string sGender,
                                  int sYearOfStudy, string sMajor, 
                                  long sAdvisorId)
{
  bool found = false; // Valid major?

  // Major is selected
  if (sMajor != "0")
  {
    for (int x = 0; x < (int)Departments.size(); x++)  // For each dept
      if (sMajor == Departments[x].getName())          // Do we match?
        found = true;                                  // Yes, it's valid
  } else found = true; // No major selected
  
  // Was an invalid major was selected? 
  if (found == false)
  {
    DisplayErrorMessage("CreateNewStudent, Major Name", sMajor);
    return failure;
  } else found = false;  // Reset for next test.
         
  // Want an advisor?
  if (sAdvisorId != 0)    // Advisor was chosen
  {
    for (int x = 0; x < (int)Faculties.size(); x++)      // For each faculty
      if (sAdvisorId == Faculties[x].getId())            // Do we match?
        found = true;                                    // Yes it's valid
  } else found = true; // No advisor was selected
  
  // Was an invalid Advisor was selected?
  if (found == false)
  {
    DisplayErrorMessage("CreateNewStudent, Advisor ID", sAdvisorId);
    return failure;
  } else found = false;  // Reset for next test

  // Call constructor, and assign to vector
  Student s(sName,sEmail,sAddress,
    sDateOfBirth,sGender,sYearOfStudy,sMajor,sAdvisorId);
  Students.push_back(s);

  return success;
}


/// Removes a student from the list, drops all their courses first
bool University::RemoveAStudent(long sStId)
{
  int stIndex = studentIsValid(sStId);

  // Was the ID given valid?
  if (stIndex > 0)
  {
    Students[stIndex].dropAllCourses(); // why? deleting the entire entry anyway!
    Students.erase(Students.begin()+stIndex);
    return success;
  }
  return failure;
}


/// Creates a new course
bool University::CreateNewCourse(string cName, long cDepId, long cTaughtBy, int cMaxSeat)
{
  bool found = false; // valid teacher?

  // Taught By is selected
  if (cTaughtBy != 0)
  {
    if (!facultyIsValid(cTaughtBy))
      found = true;
  } else found = true; // No teacher was specified

  // Was an invalid teacher selected?
  if (found)
  {
    DisplayErrorMessage("CreateNewCourse, Teacher", cTaughtBy);
    return failure;
  } 

  // Was an invalid department selected?
  if (!departmentIsValid(cDepId))
  {
    DisplayErrorMessage("CreateNewCourse, Department", cDepId);
    return failure;
  } 

  // All checks passed, create new Course
  Course c(cName, cDepId, cTaughtBy, cMaxSeat);
  Courses.push_back(c);
  return success;
}


/// Removes a course from the list of courses, but first checks to see
///     if any students are enrolled in the course.
bool University::RemoveACourse(long cCRN)
{
  bool found = false;  // Multiple uses, valid CRN, student taking?
  
  for (int x = 0; x < (int)Courses.size(); x++)    // For each course
    if (cCRN == Courses[x].getCrn())               // Valid Crn?
      found = true;
  
  if (found == true)                               // Now check students
  {
    for (int x = 0; x < (int)Students.size(); x++) // For each student
      if (Students[x].isCourseTaken(cCRN) > 0)     // Are they in this course?
        return failure;                            // Return, it was found
  } else return failure;                           // Return, invalid CRN

  for (int x = 0; x < (int)Courses.size(); x++)    // Continue with removal
    if (cCRN == Courses[x].getCrn())               // Match?
      Courses.erase(Courses.begin()+x);            // Erase the match
  
  return success;                                  // Success!
}


/// Creates a new faculty member
bool University::CreateNewFaculty(string fName, string fEmail,
                                  string fAddress, string fDateOfBirth, 
                                  string fGender, float fSalary, 
                                  int fYearOfExp, long fDepId)
{
  bool found = false;  // Keeps track if dept is ever found during search

  // Loop through each department
  for (int x = 0; x < (int)Departments.size(); x++)
    if (fDepId == Departments[x].getId())    // Check if we have a valid dept
      found = true;

  // If we don't find a department, then return a failure message
  if (!found)
  {
    DisplayErrorMessage("CreateNewFaculty, Department", fDepId);
    return failure;
  }

  // Create Faculty, then enter into Vector
  Faculty f(fName, fEmail, fAddress, fDateOfBirth, fGender, fSalary,
    fYearOfExp, fDepId);

  // Insert new faculty into faculties vector
  Faculties.push_back(f);

  // Return success
  return success;

}


/// Removes a faculty member, but checks for any associations
///    with the university before taking any action
bool University::RemoveAFaculty(long fFactId)
{
  int fIndex = -1;        // Stores the value of the index of the faculty ID
  bool found = false;     // Toggle switch for each seperate check

  // Check for valid ID
  for (int x = 0; x < (int)Faculties.size(); x++)
    if (fFactId == Faculties[x].getId())
      fIndex = x;

  // If Valid ID
  if (fIndex < 0) return failure;

  // Check if they are teaching anything
  for (int x = 0; x < (int)Courses.size(); x++)
    if (Faculties[fIndex].getId() == Courses[x].getIsTaughtBy())
      found = true;

  // Are they teaching anything?
  if (found == false)
    return failure;                // Yep, sorry, can't delete
  else found = false;              // Why, yes they are!

  // Check if they are advising anybody
  for (int x = 0; x < (int)Students.size(); x++)
    if (Faculties[fIndex].getId() == Students[x].getAdvisorId())
      found = true;

  // You advising anyone?
  if (found == false)
    return failure;               // Yep, sorry, can't delete
  else found = false;             // Why, yes they are!

  // Are they chairing any departments?
  for (int x = 0; x < (int)Departments.size(); x++)
    if (Faculties[fIndex].getId() == Departments[x].getId())
      found = true;

  // You chairing a department?
  if (found == false)
    return failure;               // Yep, sorry, can't delete
  else found = false;             // Why, yes they are!

  // Finally, delete it!
  Faculties.erase(Faculties.begin()+fIndex);
  return success;
}


/// List all courses taught by a faculty member
bool University::ListCoursesTaughtByFaculty(long facultyId)
{
  vector<int> cIndex;         // Stores index of each course taught
  bool found = false;         // Toggle whether facultyID is valid or not

  // Loop through each faculty and check ID for validity
  for (int x = 0; x < (int)Faculties.size(); x++)
    if (facultyId == Faculties[x].getId())
      found = true;

  // Was ID Valid?
  if (found == false)
  {
    DisplayErrorMessage("ListCoursesTaughtByFaculty, Faculty ID", facultyId);
    return failure;
  } else found = false;  // Yes reset to original value

  // Generate list to print, store in cIndex
  for (int x = 0; x < (int)Courses.size(); x++)
    if (facultyId == Courses[x].getIsTaughtBy())
      cIndex.push_back(x);

  if (cIndex.size() > 0)
  {
    cout << "Courses Taught By Faculty " << facultyId << endl;
    cout << "=============================" << endl;

    // Loop through and print out
    for (int x = 0; x < (int)cIndex.size(); x++)
      Courses[cIndex[x]].printBasicInfo();
    
    cout << endl;
  }
  return success;
}


/// Lists all courses taken by a student
bool University::ListCoursesTakenByStudent(long studentId)
{
  int sIndex = -1;            // Index of where the StudentId was found
  vector<int> cIndex;         // Stores index of each class taken

  // Get index of student id
  sIndex = studentIsValid(studentId);

  // Was ID Valid?
  if (sIndex < 0)
  {
    // No, display error then return  
    DisplayErrorMessage("ListCoursesTakenByStudent, Student", studentId);
    return failure;
  }

  // Generate list to print, store in cIndex
  cIndex = Students[sIndex].getCourseCrnsTaken();

  // Do we even have any?
  if (cIndex.size() > 0)
  {
    cout << "Courses Taken by Student " << studentId << endl;
    cout << "============================" << endl;

    // Loop through and print out
    for (int x = 0; x < (int)cIndex.size(); x++)
      Courses[cIndex[x]].print();
    cout << endl;
  }

  return success;
}


/// Lists all faculties associated with a department
bool University::ListFacultiesInDepartment (long departId)
{
  vector<int> sFaculties;  // Stores list of matching faculties

  // Did we find?
  if (departmentIsValid(departId) == 0)
  {    
    // No, display error then return  
    DisplayErrorMessage("ListFacultiesInDepartment, Department ID", departId);
    return failure;
  } 

  // Find faculty in each dept.
  for (int x = 0; x < (int)Faculties.size(); x++)
    if (departId == Faculties[x].getDepartmentId())
      sFaculties.push_back(x);

  if (sFaculties.size())
  {
    cout << "Faculties in Department " << departId << endl;
    cout << "===========================" << endl;
    // Print each faculty found
    for (int x = 0; x < (int)sFaculties.size(); x++)
      Faculties[sFaculties[x]].printBasicInfo();

    cout << endl;
  }
  return success;
}


/// Short list all students in a faculty
bool University::ListStudentsOfAFaculty(long facultyId)
{
  vector<int> sStudents; // Stores list of matching faculties

  // Did we find?
  if (facultyIsValid(facultyId) == 0)
  {    
    // No, display error then return  
    DisplayErrorMessage("ListStudentsOfAFaculty, Faculty ID", facultyId);
    return failure;
  } 

  // Find students in each faculty.
  for (int x = 0; x < (int)Faculties.size(); x++)
    if (facultyId == Faculties[x].getDepartmentId())
      sStudents.push_back(x);

  // List each student found
  if (sStudents.size() > 0)
  {
    // Header
    cout << "Students in Faculty" << endl;
    cout << "===================" << endl;
    for (int x = 0; x < (int)sStudents.size(); x++)
      Students[sStudents[x]].printBasicInfo();
    cout << endl;
  }
  return success;
}


/// Short list of all courses in a department
bool University::ListCoursesOfADepartment(long departId)
{
  vector<int> sCourses; // Stores list of matching courses

  // If it's invalid, return an error
  if (departmentIsValid(departId) == 0)
  {
    DisplayErrorMessage("ListCoursesOfADepartment", departId);
    return failure;
  }

  // Generate list to print
  for (int x = 0; x < (int)Courses.size(); x++)
    if (departId == Courses[x].getDepartmentId())
      sCourses.push_back(x);

  // List each student found
  if (sCourses.size() > 0)
  {
    // Header
    cout << "Courses in Department " << departId << endl;
    cout << "=========================" << endl;
    for (int x = 0; x < (int)sCourses.size(); x++)
      Courses[sCourses[x]].printBasicInfo();
    cout << endl;
  }
  return success;
}


/// Adds a course to a students course list
bool University::AddACourseForAStudent(long courseId, long stId)
{
  // Get vector index of values
  int courseIndex = courseIsValid(courseId);
  int studentIndex = studentIsValid(stId);

  // Check for validity
  if (courseIndex < 1)
    DisplayErrorMessage("AddACourseForAStudent, Course ID", courseId);
  if (studentIndex < 1)
    DisplayErrorMessage("AddACourseForAStudent, Student ID", stId);
  if (courseIndex < 1 || studentIndex < 1) return failure;
  
  // Increment assigned seats (if possible)
  if (!Courses[courseIndex].incrementSeats())
    return failure;

  // Add course to students list
  Students[studentIndex].addCoursesTaken(Courses[courseIndex]);
  
  return success;

}


/// Drops a course in a students course list
bool University::DropACourseForAStudent(long courseId, long stId)
{
  // Get vector index of values
  int courseIndex = courseIsValid(courseId);
  int studentIndex = studentIsValid(stId);

  // Check for validity
  if (courseIndex < 1)
    DisplayErrorMessage("DropACourseForAStudent, Course ID", courseId);
  if (studentIndex < 1)
    DisplayErrorMessage("DropACourseForAStudent, Student ID", stId);
  if (courseIndex < 1 || studentIndex < 1) return failure;
  
  // Free up a seat
  Courses[courseIndex].decrementSeats();

  // Remove course from students list
  Students[studentIndex].dropACourse(courseId);

  return success;
}


/// Assigns a chair to a department
bool University::AssignDepartmentChair(long facultyId, long departId)
{
  int facIndex = facultyIsValid(facultyId);
  int depIndex = departmentIsValid(departId);

  // Check for validity
  if (depIndex < 1)
    DisplayErrorMessage("AssignDepartmentChair, Department ID", departId);
  if (facIndex < 1)
    DisplayErrorMessage("AssignDepartmentChair, Faculty ID", facultyId);
  if (facIndex < 1 || depIndex< 1) return failure;

  // Assign the chair
  Departments[depIndex].setChairId(facultyId);

  return success;
}


/// Assigns an instructor to a course
bool University::AssignInstructorToCourse (long facultyId, long courseId)
{
  int facIndex = facultyIsValid(facultyId);
  int crnIndex = courseIsValid(courseId);

  // Check for validity
  if (crnIndex < 1)
    DisplayErrorMessage("AssignInstructorToCourse, CRN", courseId);
  if (facIndex < 1)
    DisplayErrorMessage("AssignInstructorToCourse, Faculty ID", facultyId);
  if (facIndex < 1 || crnIndex < 1) return failure;

  // Assign the teacher
  Courses[crnIndex].setIsTaughtBy(facultyId);
  return success;
}

/// Short list of all departments available
bool University::ListDepartments()
{
  if (Departments.size() < 1) return failure;
  cout << "List of Departments (ID)" << endl;
  cout << "========================" << endl;
  // Loop thrugh each and print 
  for (int x = 0; x < (int)Departments.size(); x++)
    Departments[x].printBasicInfo();
  cout << endl;
  return success;
}


/// Short list of all students available
bool University::ListStudents()
{
  // First check if any students are there
  if (Students.size() < 1) return failure;

  cout << "List of Student (ID)" << endl;
  cout << "====================" << endl;
  // Loop thrugh each and print 
  for (int x = 0; x < (int)Students.size(); x++)
    Students[x].printBasicInfo();
  cout << endl;
  return success;
}


/// Short list of all courses available
bool University::ListCourses()
{
  // First check if any courses are there
  if (Courses.size() < 1) return failure;
  
  cout << "List of Courses (ID)" << endl;
  cout << "====================" << endl;
  // Loop thrugh each and print 
  for (int x = 0; x < (int)Courses.size(); x++)
    Courses[x].printBasicInfo();
  cout << endl;
  return success;
}


/// Short list of all faculties
bool University::ListFaculties()
{
  // First check if any faculties are there
  if (Faculties.size() < 1) return failure;
  
  cout << "List of Faculties (ID)" << endl;
  cout << "======================" << endl;
  // Loop thrugh each and print 
  for (int x = 0; x < (int)Faculties.size(); x++)
    Faculties[x].printBasicInfo();
  cout << endl;
  return success;
}


/// Read each item from transaction file and call appropriate function
bool University::ProcessTransactionFile(string fileName)
{
  ifstream f(fileName.data(), ios::out);  // Filestream for input file

  // File read successfully?
  if (!f.is_open())
  {
    DisplayErrorMessage("OpenTransactionFile, filename", fileName);
    return failure;
  }

  // Read one item
  while (!f.eof())
  {
    // Get fresh set of commands/params every execution
    string cmd;
    vector<string> params;    
    
    f >> cmd;                                    // Read in the next cmd
    for (int x = 0; x < 22; x++)
    {
      if (cmd == COMMAND_LIST[x])                // Check against COMMAND LIST
      {
        // Variables used to store each parameter expected
        string s1,s2,s3,s4,s5,s6;
        long l1(0),l2(0);
        int i1(0),i2(0);
        float f1(0);

        // Loop through commands, read params, then call function
        switch(x)
        {
          case 0:
            f >> s1; f >> s2; f >> l1;
            CreateNewDepartment(s1,s2,l1);
            break;
          case 1:
            f >> l1;
            RemoveADepartment(l1);
            break;
          case 2:
            f >> s1; f >> s2; f >> s3; f >> s4; f >> s5; 
            f >> i1; f >> s6; f >> l1;
            CreateNewStudent(s1,s2,s3,s4,s5,i1,s6,l1);
            break;
          case 3:
            f >> l1;
            RemoveAStudent(l1);
            break;
          case 4:
            f >> s1; f >> l1; f >> l2; f >> i1;
            CreateNewCourse(s1,l1,l2,i1);
            break;
          case 5:
            f >> l1;
            RemoveACourse(l1);
            break;
          case 6:
            f >> s1; f >> s2; f >> s3; f >> s4; f >> s5;
            f >> f1; f >> i1; f >> l1;
            CreateNewFaculty(s1,s2,s3,s4,s5,f1,i1,l1);
            break;
          case 7:
            f >> l1;
            RemoveAFaculty(l1);
            break;
          case 8:
            f >> l1;
            ListCoursesTaughtByFaculty(l1);
            break;
          case 9:
            f >> l1;
            ListCoursesTakenByStudent(l1);
            break;
          case 10:
            f >> l1;
            ListFacultiesInDepartment(l1);
            break;
          case 11:
            f >> l1;
            ListStudentsOfAFaculty(l1);
            break;
          case 12:
            f >> l1;
            ListCoursesOfADepartment(l1);
            break;
          case 13:
            f >> l1; f >> l2;
            AddACourseForAStudent(l1,l2);
            break;
          case 14:
            f >> l1; f >> l2;
            DropACourseForAStudent(l1,l2);
            break;
          case 15:
            f >> l1; f >> l2;
            AssignDepartmentChair(l1,l2);
            break;
          case 16:
            f >> l1; f >> l2;
            AssignInstructorToCourse(l1, l2);
            break;
          case 17:
            ListDepartments();
            break;
          case 18:
            ListStudents();
            break;
          case 19:
            ListCourses();
            break;
          case 20:
            ListFaculties();
            break;
          default:
            break;
        }
      }
    }
  }
  return success;
}

/// Verify validity of StudentID, return index of any matches
long University::studentIsValid(long studentId)
{
  // Loop through each, checking for valid faculty id
  for (int x = 0; x < (int)Students.size(); x++)
    if (studentId == Students[x].getId())
      return x;
  return 0;
} 


/// Verify validity of CourseID, return index of any matches
long University::courseIsValid(long crn)
{
  // Loop through each, checking for valid faculty id
  for (int x = 0; x < (int)Courses.size(); x++)
    if (crn == Courses[x].getCrn())
      return x;
  return 0;
} 


/// Verify validity of DepartmentID, return index of any matches
long University::departmentIsValid(long departId)
{
  // Loop through each, checking for valid dept id
  for (int x = 0; x < (int)Departments.size(); x++)
    if (departId == Departments[x].getId())
      return x;
  return 0;
}


/// Verify validity of FacultyID, return index of any matches
long University::facultyIsValid(long facultyId)
{
  // Loop through each, checking for valid faculty id
  for (int x = 0; x < (int)Faculties.size(); x++)
    if (facultyId == Faculties[x].getId())
      return x;
  return 0;
} 


void University::DisplayErrorMessage(string fn, string id)
{
    cout << "ERROR: In " << fn << " " << id << " is invalid." << endl << endl;
}

void University::DisplayErrorMessage(string fn, long id)
{
    cout << "ERROR: In " << fn << " " << id << " is invalid." << endl << endl;
}

#endif
