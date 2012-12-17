/// Lab01.cpp
//  Program 1: (Practicing an example of function using call by reference)
//
//  By Jeremy Villegas
//  Cal State San Marcos - CS211
//  09/11/2006
///

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void ProcessARow(int nG[]);
int  CalculateMin(int a1, int a2, int a3);
int  CalculateMax(int a1, int a2, int a3);
int  CalculateAverage(int a1, int a2, int a3);

int main()
{
  ifstream f;
  int nGrades[4];

  f.open("data.txt");

  if (!(f.is_open())) return 1;

  cout << "Student ID   Exam 1   Exam 2   Exam 3   Low   High   Average" << endl;
  cout << "============================================================" << endl;

  while(!f.eof())
  {
    for (int x=0;x < 4; x++)
      f >> nGrades[x];
        ProcessARow(nGrades);
  }
  
  f.close();
  return 0;
}

void ProcessARow(int nG[])
{
  int id, a1, a2, a3;

  id = nG[0];
  a1 = nG[1];
  a2 = nG[2];
  a3 = nG[3];
	
  cout << id
       << setw(10) << a1 
       << setw(9) << a2 
       << setw(9) << a3
       << setw(9) << CalculateMin(a1,a2,a3)
       << setw(6) << CalculateMax(a1,a2,a3) 
       << setw(7) << CalculateAverage(a1,a2,a3) 
       << endl;
  
  return;
}

int CalculateMin(int a1, int a2, int a3)
{
  return min(min(a1,a2),a3);
}


int CalculateMax(int a1, int a2, int a3)
{
  return max(max(a1,a2),a3);
}


int CalculateAverage(int a1, int a2, int a3)
{
  return (a1 + a2 + a3) /3;
}
