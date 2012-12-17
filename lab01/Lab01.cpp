#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void ProcessARow(int nG[]);

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
  int nId, nX1, nX2, nX3;

  nId = nG[0];
  nX1 = nG[1];
  nX2 = nG[2];
  nX3 = nG[3];
	
  cout << nId
       << setw(10) << nX1 
       << setw(9) << nX2 
       << setw(9) << nX3
       << setw(9) << min(min(nX1,nX2),nX3) 
       << setw(6) << max(max(nX1,nX2),nX3) 
       << setw(7) << (nX1 + nX2 + nX3) / 3  
       << endl;
  
  return;
}



