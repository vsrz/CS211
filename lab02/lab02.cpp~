/// Lab02.cpp
//  Program 1: Use the Concept of vector and string to do the following question
//
//  By Jeremy Villegas
//  Cal State San Marcos - CS211
//  09/17/2006
///

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void Insert(vector<string>& V, int element, string data);
void Delete(vector<string>& V, int element);
void  Print(vector<string> V);

int main()
{
  vector<string> V;
  ifstream f;  
	
  f.open("data.txt");
  if (!f.is_open()) return 1;
	
  while (!f.eof())
  {
    string cmd = "", text;
    int element;

    f >> cmd;
		
    if (cmd == "Insert")
    {
      f >> text >> element;
      Insert(V, element, text);
    }    else if (cmd == "Delete")    {
      f >> element;
      Delete(V, element);    }    else if (cmd == "Print")      Print(V);
  }

  return 0;
}

void Insert(vector<string>& V, int element, string data)
{
  while (element > (int)V.size())
    V.push_back("");    
    V.insert(V.begin() + element, data);
}

void Delete(vector<string>& V, int element)
{
  if (element < (int)V.size())
    V.erase(V.begin() + element);
}

void Print(vector<string> V)
{
  for (int x = 0; x < (int)V.size(); x++)
    cout << V[x] << " ";
  cout << endl;
}

// Program output
/*

[ville017@uh270linux27]$ ./a.out
Total Perfect England Book
Total England Money  Perfect
[ville017@uh270linux27]$

*/
