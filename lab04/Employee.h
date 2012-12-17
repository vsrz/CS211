/// 
// lab04.cpp - Employee.h
// Lab04 - Demonstrate use of Friend Function, Static Variables, and Constant Methods
// 
// By Jeremy Villegas 10/02/2006
// CS211 - Steven Holt
///

#ifndef Employee_h
#define Employee_h
#include <string>

using namespace std;

class Employee
{
  friend void SetSalary(Employee &e);
  private:
    string name;
    const long officeNo;
    const long empId;
    int deptNo;
    char empPosition; // ‘E’: entry level, ‘M’: manager, ‘D’: Director, ‘P’:Project_leader 
    int yearsExp;
    float salary;
    static int totalNumofEmployees;
    static int nextEmpId;
    static int nextOfficeNo;

  public:
    Employee();
    ~Employee();
    Employee(string theName, int theDeptNo, char theEmpPosition, int yearsExp);
    void Print() const ;
    void GetInfo();

};

#endif
