/// 
// Assignment 1: Encrypt/Decrypt ROT/Cryptogram method writing to disk
//
// CS211Lab - Steven Holt
// By Jeremy Villegas
// 09/24/2006
///

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int GetUserInput(string prompt);
vector<string> ReadDataFile(char fn[]);
void WriteDataFile(char fn[], vector<string> out_data);
vector<string> rot(vector<string> toCrypt, int key);
vector<string> cryptogram(vector<string> toCrypt, string key);
vector<string> decryptogram(vector<string> toCrypt, string key);
string ToUpper(string toChange);
string ToLower(string toChange);

int main()
{
  vector<string> in_data, cryptKey;
  int user_input;

  // Display Menu
  cout << "Encryption/Decryption Menu" << endl;
  cout << "==========================" << endl;
  cout << "1 - Encryption" << endl;
  cout << "2 - Decryption" << endl;
  user_input = GetUserInput("Choice: ");

  // Check input value
  if (user_input == 1)
  {
    // Display Menu
    cout << "Encrypt Menu" << endl;
    cout << "============" << endl;
    cout << "1 - ROT" << endl;
    cout << "2 - Cryptogram" << endl;
    user_input = GetUserInput("Choice: ");

    // Check input value
    if (user_input == 1) // Encrypt - ROT Method
    {
      // Get original string from datafile
      in_data = ReadDataFile("original.txt");

      // Get user input for ROT key
      user_input = GetUserInput("Please enter ROT key: ");

      // Encrypt vector for encrypt01.txt, write to disk
      WriteDataFile("encrypt01.txt", rot(in_data, user_input));
    }
    else if (user_input == 2) // Encrypt - Cryptogram Method
    {
      // Open crypt key file
      cryptKey = ReadDataFile("cryptkey.txt");

      // Get original string from datafile
      in_data = ReadDataFile("original.txt");

      // Encrypt vector for encrypt02.txt, write to disk
      WriteDataFile("encrypt02.txt", cryptogram(in_data, cryptKey[0]));
    }
  }
  else if (user_input == 2) // Decryption
  {
      cout << "DeCrypt Menu:" << endl;
      cout << "=============" << endl;
      cout << "1 - ROT" << endl;
      cout << "2 - Cryptogram" << endl;
      user_input = GetUserInput("Choice: ");

      if (user_input == 1) // Decrypt - ROT Method
      {
        // Open encrypted file
        in_data = ReadDataFile("encrypt01.txt");

        // Get ROT key for decryption.
        user_input = GetUserInput("Please enter ROT key: ");

        // Decrypt vector from encrypt02.txt, reverse input value for decryption, write to disk
        WriteDataFile("decrypt01.txt", rot(in_data, user_input*-1));
      }
      else if (user_input == 2) // Decrypt - Cryptogram Method
      {
        // Open crypt key file
        cryptKey = ReadDataFile("cryptkey.txt");

        // Get encrypted data from datafile
        in_data = ReadDataFile("encrypt02.txt");

        // Decrypt vector from encrypt02.txt, write to disk
        WriteDataFile("decrypt02.txt", decryptogram(in_data, cryptKey[0]));
      }
  }
  return 0;
}

/// Returns an int with the user input
int GetUserInput(string prompt)
{
  int in = -1;
  cout << prompt;
  cin >> in;
  cin.ignore();
  cout << endl;
  return in;
}

/// Read datafile from disk
vector<string> ReadDataFile(char fn[])  
{
  ifstream f;
  vector<string> in_data;
  string in;
  f.open(fn);

  // Check to see if readfile opened successfully
  if (!f.is_open()) 
  {
    cout << fn << " was not found.";
    getchar();
    exit(1);
  }

  // Read in each word of the file into vector
  while (!f.eof())
  {
    string in;
    f >> in;
    in_data.push_back(in);
  }
  
  return in_data;
}

/// Write datafile to disk
void WriteDataFile(char fn[], vector<string> out_data)
{
  ofstream out_file;

  // Open file for writing
  out_file.open(fn);

  // Write file to disk
  for (int x = 0; x < (int)out_data.size(); x++)
    out_file << out_data[x] << " ";

  // Close file
  out_file.close();
  
  // Display OK message.
  cout << "Writing " << fn << " successful.  Press Enter to exit.";
  getchar();
  return;
}

/// Takes vector and numeric key to shift alphabet
vector<string> rot(vector<string> toCrypt, int key)
{
  int counter;              // Counter for letter increment
  vector<string> encrypted; // New vector to hold encrypted string
  string sWord;             // Holds each word in vector for manipulation

  for (int nWord = 0; nWord < (int)toCrypt.size(); nWord++)
  {
    // Split vector into words
    sWord = toCrypt[nWord];
    // Process Lowercase Letters
    for (int x = 0; x < (int)sWord.length(); x++)
    {
      if (sWord[x] >= 97 && sWord[x] <= 122)
      {
        counter = key;          // Reset counter for each new letter
        while (counter != 0)    // When counter is zero, ROT has been met whether encrypting or decypting
        {
          if (counter > 0)      // Check to see if you are incrementing or decrementing
          {
            counter--;          // Decrement counter
            sWord[x]++;         // Next Letter

            if (sWord[x] > 122) // Did you pass 'z'?
              sWord[x] = 97;    // Set to 'a'
          }
          else
          {
            counter++;          // Increment counter
            sWord[x]--;         // Previous letter

            if (sWord[x] < 97)  // Did you go pass 'a'?
              sWord[x] = 122;   // Set to 'z'
          }
        }
      }

      if (sWord[x] >= 65 && sWord[x] <= 90)
      {
        // Reset counter for each new letter
        counter = key;         // Reset counter for each new letter
        while (counter != 0)   // When counter is zero, done advancing letters
        {
          if (counter > 0)     // You are encrypting
          {
            counter--;         // Decrement counter
            sWord[x]++;        // Next Letter
                     
            if (sWord[x] > 90) // Did you go past 'Z'?  
              sWord[x] = 65;   // Set to 'A'
          }
          else                 // You are decrypting
          {
            counter++;         // Increment counter
            sWord[x]--;        // Previous letter
            
            if (sWord[x] < 65) // Did you go past 'A'? 
              sWord[x] = 90;   // Set to 'Z'
          }
        }
      }
    }
    // Copy encrypted word into new vector
    encrypted.push_back(sWord);
  }  
  // Return new vector
  return encrypted;  
}

/// Takes vector of string and a key and returns vector with key applied
vector<string> cryptogram(vector<string> toCrypt, string key)
{
  string alpha =  "abcdefghijklmnopqrstuvwxyz"; // Holds comparison vector
  string Ualpha = ToUpper(alpha);               // Uppercase version to preserve capitalization 
  string Ukey = ToUpper(key);                   // Uppercase version of key to preserve capitalization
  string sWord;                                 // Holds each word in vector for manipulation
  vector<string> encrypted;                     // toCrypt vector copied into this after encryption
  
  // Loop through each word
  for (int nWord = 0; nWord < (int)toCrypt.size(); nWord++)
  {
    // Extract word from vector to be encrypted
    sWord = toCrypt[nWord];
    
    // Loop through each letter in sWord
    for (int x = 0; x < (int)sWord.length(); x++)
    {
      // If lowercase letter
      if (sWord[x] >= 97 && sWord[x] <= 122)
        sWord[x] = alpha[key.find(sWord[x])];

      // If uppercase letter
      if (sWord[x] >= 65 && sWord[x] <= 90)
        sWord[x] = Ualpha[Ukey.find(sWord[x])];
    }
    // Insert word into new vector
    encrypted.push_back(sWord);
  }
  
  // Return new vector
  return encrypted;
}

/// Takes vector of string and a key and returns a vector with key reversely applied
vector<string> decryptogram(vector<string> toCrypt, string key)
{
  string alpha =  "abcdefghijklmnopqrstuvwxyz";
  string Ualpha = ToUpper(alpha);
  string Ukey = ToUpper(key);
  string sWord;
  vector<string> encrypted;
  
  // Loop through each word
  for (int nWord = 0; nWord < (int)toCrypt.size(); nWord++)
  {
    // Extract word
    sWord = toCrypt[nWord];
    
    // Loop through each letter
    for (int x = 0; x < (int)sWord.length(); x++)
    {
      // Each lowercase letter
      if (sWord[x] >= 97 && sWord[x] <= 122)
        sWord[x] = key[alpha.find(sWord[x])];

      // Each uppercase letter
      if (sWord[x] >= 65 && sWord[x] <= 90)
        sWord[x] = Ukey[Ualpha.find(sWord[x])];
    }
    // Insert word into new vector
    encrypted.push_back(sWord);
  }
  
  // Return new vector
  return encrypted;
}

/// Convert string to Upper Case
string ToUpper(string toChange)
{
  for (int x = 0; x < (int)toChange.length(); x++)
    if (toChange[x] >= 97 && toChange[x] <= 122) toChange[x] -= 32;

  return toChange;
}

/// Convert string to Lower Case
string ToLower(string toChange)
{
  for (int x = 0; x < (int)toChange.length(); x++)
    if (toChange[x] >= 65 && toChange[x] <= 90) toChange[x] += 32;

  return toChange;
}
