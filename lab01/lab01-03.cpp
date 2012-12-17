/// Lab01-03.cpp
//  Program 3:
//
//  By Jeremy Villegas
//  Cal State San Marcos - CS211
//  09/11/2006
///

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

void ReverseNumbers(const int arrA[], int arrB[]);
void FillArray(int arrA[]);
void PrintArray(const int array[], const int size);
int  FindRange(const int arrA[], const int MinNum, const int MaxNum);
int  FindDivisible(const int arrA[], const int DivNum);
void PrintDivisible(const int arrA[], const int DivNum);
int  MeanOfArray(const int arrA[], const int size);
int  FindMinimum(const int arrA[], const int size);
bool SearchNumber(const int arrA[], const int size, const int SearchNum);

int main()
{
  int arrA[10],arrB[10],searchNum;

  FillArray(arrA);

  cout << "Array A : ";
  PrintArray(arrA, 10);

  ReverseNumbers(arrA,arrB);
 
  cout << "Array B : ";
  PrintArray(arrB, 10);

  cout << "Range   : " << FindRange(arrA, 80, 100) << endl;
  cout << "DivBy5  : " << FindDivisible(arrA, 5) << endl;
  
  PrintDivisible(arrA, 5);
  cout << "Mean    : " << MeanOfArray(arrA, 10) << endl;
  cout << "MinNum  : " << FindMinimum(arrA, 10) << endl;

  cout << "Please type a number: ";
  cin >> searchNum;

  cout << searchNum << " " << (SearchNumber(arrA, 10, searchNum) ? "was" : "was not") << " found." << endl << endl; 
  return 0;
}

void ReverseNumbers(const int arrA[],int arrB[])
{
  int y = 9, tmp[10];
  
  for (int x=0; x < 10; x++)
    tmp[x] = arrA[x];

  for (int x=0;x < 10; x++)
  {
    arrB[y] = tmp[x];
    y -= 1;
  }

}

void FillArray(int arrA[])
{
  ifstream f;
  f.open("data.txt");

  while (!f.eof())
  {
     for (int x = 0; x < 10; x++)
       f >> arrA[x];
  }

  f.close();
  return;
}

void PrintArray(const int array[], const int size)
{
  for (int x = 0; x < size; x++)
    cout << array[x] << " ";

  cout << endl;
 
  return;
}

int FindRange(const int arrA[], const int MinNum, const int MaxNum)
{
  int total = 0;
 
  for (int x = 0; x < 10; x++)
     if ((arrA[x] >= MinNum) && (arrA[x] <= MaxNum))
       total++;

  return total;
}

int FindDivisible(const int arrA[], const int DivNum)
{
  int total = 0;
 
  for (int x = 0; x < 10; x++)
    if ((arrA[x] % DivNum) == 0)
      total++;
 
  return total;
}

void PrintDivisible(const int arrA[], const int DivNum)
{
  cout << "Index/5 : ";

  for (int x = 0; x < 10; x++)
    if ((arrA[x] % DivNum) == 0)
      cout << x << " ";
  
  cout << endl;

  return;
}

int MeanOfArray(const int arrA[], const int size)
{
  int total = 0;

  for (int x = 0; x < size; x++)
    total += arrA[x];

  return total/size;
}
  
int FindMinimum(const int arrA[], const int size)
{
  int MinNum = arrA[0];

  for (int x = 0; x < size; x++)
    MinNum = min(MinNum,arrA[x]);

  return MinNum;
}

bool SearchNumber(const int arrA[], const int size, const int SearchNum)
{
  for (int x = 0; x < size; x++)
    if (arrA[x] == SearchNum)
      return true;
  return false;
}

  
