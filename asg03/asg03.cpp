/**
 * Project    : Assignment 3 -
 * File       : asg03.cpp
 * Programmer : Jeremy Villegas <ville017@csusm.edu>
 * Date       : 11/13/2006
 * School     : CSU San Marcos - CS211 A. Hadaegh, S. Holt
 *
 * Includes   : Includes.h, University.h
 * Purpose    : Main module.  Given by instructor.
 **/

#ifndef ASG03_CPP
#define ASG03_CPP
#define DEBUG

#include "University.h"

int main()
{
  University csusm;
	csusm.ProcessTransactionFile("TransactionFile.txt");
  system("Pause");
  return 0;
}

#endif