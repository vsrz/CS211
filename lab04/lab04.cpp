/// 
// lab04.cpp
// Lab04 - Demonstrate use of Friend Function, Static Variables, and Constant Methods
// 
// By Jeremy Villegas 10/02/2006
// CS211 - Steven Holt
///

#ifndef lab04_cpp
#define lab04_cpp

#include "Employee.h"

int main()
{
  Employee emp1;
  emp1.Print();

  Employee emp2("Unknown", 10, '?', 0);
  emp2.GetInfo();
  SetSalary(emp2);
  emp2.Print();
  system("pause");

  return 0;
}

void SetSalary(Employee &e)
{
  switch (e.empPosition)
  {
    case 'E':
      if (e.yearsExp < 2) e.salary = 50000;
      if (e.yearsExp >= 2) e.salary = 55000;
      break;
    case 'P':
      if (e.yearsExp < 4) e.salary = 60000;
      if (e.yearsExp >= 4) e.salary = 65000;
      break;
    case 'M':
      e.salary = 70000;
      break;
    case 'D':
      e.salary = 80000;
  }
  return;
}

#endif

