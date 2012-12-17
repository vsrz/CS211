/// 
// lab04.cpp - Employee.cpp
// Lab04 - Demonstrate use of Friend Function, Static Variables, and Constant Methods
// 
// By Jeremy Villegas 10/02/2006
// CS211 - Steven Holt
///

#ifndef Employee_cpp
#define Employee_cpp

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

#include "Employee.h"

int Employee::totalNumofEmployees = 0;
int Employee::nextEmpId = 1000;
int Employee::nextOfficeNo = 10;

Employee::Employee():empId(nextEmpId++),officeNo(nextOfficeNo++)
{
  name = "Unknown";
  deptNo = 0;
  empPosition = 'E';
  yearsExp = 0;
  salary = 0;
  ++totalNumofEmployees;
  return;
}

Employee::Employee(string name, int deptNo, char empPosition, int yearsExp):empId(nextEmpId++),officeNo(nextOfficeNo++)
{
  this->name = name;
  this->deptNo = deptNo;
  this->empPosition = empPosition;
  this->yearsExp = yearsExp;
  ++totalNumofEmployees;
  return;
}
Employee::~Employee()
{
  --totalNumofEmployees;  
  return;
}

void Employee::Print() const
{ 
  cout << endl << "Name (ID No.)    : " << name << " (" << empId << ")" << endl;
  cout << "Office/Dept No   : " << officeNo << " " << deptNo << endl;
  cout << "Years of Exp     : " << yearsExp << endl;
  cout << "Position/Salary  : " << empPosition << " " << (long)salary << endl << endl;
  cout << "Total Employees  : " << totalNumofEmployees << endl;
  cout << "Next EmpID is    : " << nextEmpId << endl;
  cout << "Next OfficeNo is : " << nextOfficeNo << endl;

  return;
}

void Employee::GetInfo()
{
  cout << endl << "Enter new employee:" << endl;
  cout << "===================" << endl;
  cout << "Name             : ";
  getline(cin,name,'\n');
  cout << "Position         : ";
  empPosition = getchar();
  cin.ignore(); 
  cout << "Years of Exp     : ";
  cin >> yearsExp;

  return;
}

#endif

