
#ifndef Dictionary_h
#define Dictionary_h
#include "Includes.h"

class Dictionary
{
  private:
    const int maxWordsInDict;
    const int maxWordsPerFile;
    const int totalWordsInDict;
    int numOfWordsInFile[26];
    static bool failure;
    static bool success;
  public:
    Dictionary();
    Dictionary(int dictMaxWords, int fileMaxWords);
    bool AddAWord(string word);
    bool DeleteAWord(string word);
    bool SearchForWord(string word);
    bool PrintAFileInDict(string filename);
    bool SpellChecking(string fileName);
    bool InsertWordsIntoDict(string fileName);
    void ProcessTransactionFile();                       

};

bool Dictionary::failure = false;
bool Dictionary::success = true;

Dictionary::Dictionary():maxWordsInDict(10000), maxWordsPerFile(100),
            totalWordsInDict(0)
{
  numOfWordsInFile[0] = 0; 
  numOfWordsInFile[1] = 0; 
  numOfWordsInFile[25] = 0;
}

Dictionary::Dictionary(int dictMaxWords, int fileMaxWords):
            maxWordsInDict(dictMaxWords), maxWordsPerFile(fileMaxWords),
            totalWordsInDict(0)
{
}

bool Dictionary::AddAWord(string word)
{
  // Before opening, check to see if file exists by checking numOfWordsInFile
  // Before adding, search for word
  // If already exists, return Dictionary::failure

  // If not exist, add then return true
  // Increment TotalWordsInDict by 1 if not exceeding MAXWORDSINDICT
  
  // Increment numOfWordsInFile appropriately
  // return Dictionary::success
}

bool Dictionary::DeleteAWord(string word)
{
  // Open appropriate file to see where this word would be kept

  // Place all words in the file into a vector
  // Check if word is in vector
  // If in vector, remove word, and pop_back()
  // If not in vector, return Dictionary::failure

  // Write the vector back to the disk
  // If removed, decrement numWordsInFile by 1
  // If removed, decrement totalWordsInDict by 1
  // Return Dictionary::success
}

bool Dictionary::SearchForWord(string word)
{
  // Open appropriate file to see where the word would be kept
  // Load words into a vector
 
  // Search for word, if not found then return (Dictionary::failure)
  // Otherwise return (Dictionary::success)

}

bool Dictionary::PrintAFileInDict(string filename)
{
  // Open the file filename
  // If file could not be opened, return Dictionary::failure
  // Read values into a vector

  // Print five words per line to the output buffer
  // Return Dictionary::success

}

bool Dictionary::SpellChecking(string fileName)
{
  // Open the file filename
  // If not opened, return Dictionary::failure

  // Words in the file are read to a vector
  // For each word, do a word search
  // If the word search returns false, then print to screen
  // Otherwise, search the next word.

  // Close the file
  // Return Dictionary::true

}

bool Dictionary::InsertWordsIntoDict(string filename)
{
  // Open the filename
  // Return Dictionary::failure if not opened

  // Copy the values into a vector
  // Close the file
  // For each value in the vector, do a word search
  // If word search returns false, open dict. file then insert it into the dictinoary
  // If word search is true, then word exists, and return Dictionary::failure

}

void Dictionary::ProcessTransactionFile()
{
  string filename;
  ifstream fin;

  // Get filename from user and open file
  while (!fin.is_open())
  {
    cout << "Open file (or Q to quit): ";
    cin >> filename;
    if (filename == "Q") exit(1);
    fin.open(filename.data());
 
    if (!fin.is_open())
      cout << endl << "File could not be opened." << endl;
  }

  // Read each command from file
  // Call appropriate method
 

}

#endif
