/* Use the comments given in each routine to complete the following program */


#include <iostream>
#include<string>

using namespace std;

class Node;
typedef Node* NodePtr;

class LL;
class Node 
{
  friend class LL;
  private:
    int stId;
    string stName;
    string stEmail;
    int stAge;
    NodePtr nextStudent;
};

class LL
{
  private:
    NodePtr  top;
    void destroy (NodePtr&);

  public:
    LL();
    LL(const LL& source);
    ~LL();
    void insertDataFromFile();
    void print ();
    bool search (int);
    void insertAfterFirst (int id, string name, string email, int age);
    void insertBeforeFirst (int id, string name, string email, int age);
    void insertAfterLast (int id, string name, string email, int age);
    void insertBeforeLast (int id, string name, string email, int age);
    void remove (int);
    void copy (NodePtr top1, NodePtr& top2);
};
//--------------------------------------------
//--------------------------------------------
// the default constructor
LL::LL()
{
  top = new node;
  top->nextStudent = NULL;

}
//--------------------------------------------
//--------------------------------------------
// the copy constructor
LL::LL(const LL& source)
{

}

//--------------------------------------------
//--------------------------------------------
// the destructor
LL::~LL()
{

}

//--------------------------------------------
//--------------------------------------------
// Read a transaction file and insert the data into it
// after reading a set of data you can call any of the 
// insert functions to insert the node into the linked list 
/* use the following data to test your program
	76543	Mary	mary@csusm.edu		19
	98765	Kathy	kathy@csusm.edu		30
	16438	Flora	flora@csusm.edu		25
	43260	Peter	peter@csusm.edu		29
	87590	kim		kim@csusm.edu		31
*/
void LL::insertDataFromFile()
{

}
//--------------------------------------------
//--------------------------------------------
// print the linked list
void LL::print ()
{
}
//--------------------------------------------
//--------------------------------------------
// search for a particular student id in the list
bool LL::search (int id)
{
	
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the top of the
// linked list but after the first node. For example if the
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6
// after inserting 10, we should get:
// list constains 1 --> 10 --> 20 -->13 --> 4 --> 5 --> 6

void LL::insertAfterFirst (int id, string name, string email, int age)
{
  

}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the top of the
// linked list before the first node. For example if the
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6
// after inserting 10, we should get:
// list constains 10 --> 1 --> 20 -->13 --> 4 --> 5 --> 6

void LL::insertBeforeFirst (int id, string name, string email, int age)
{

}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the bottom of the
// linked list after the last node. For example if the
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6
// after inserting 10, we should get:
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6 --> 10

void LL::insertAfterLast (int id, string name, string email, int age)
{
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the bottom of the
// linked list before the last node. For example if the
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6
// after inserting 10, we should get:
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 10 --> 6

void LL::insertBeforeLast (int id, string name, string email, int age)
{
}
//--------------------------------------------
//--------------------------------------------
// removes a node from the list based on the given student id 
void LL::remove (int id)
{
}
//--------------------------------------------
//--------------------------------------------
// copies one list into another
void LL::copy (NodePtr atop, NodePtr& btop)
{

}       
//--------------------------------------------
// deallocate the nodes in a linked list
void LL::destroy(NodePtr& top) 
{

}

//--------------------------------------------

int main () 
{
   LL list1;
   list1.insertDataFromFile();
   list1.print();
   list1.insertAfterFirst (54321, "Jim", "jim@csusm.edu", 25);
   list1.insertBeforeFirst (54123, "Joe", "joe@csusm.edu", 35);
   list1.insertAfterLast (63421, "Adam", "adam@csusm.edu", 20);
   list1.insertBeforeLast (66641, "Nancy", "nancy@csusm.edu", 27);
   list1.print();
   bool  found = list1.search (12321);
   if (found)
	   cout << "the record was found" << endl;
   else
	   cout << "the record was not found" << endl;
   list1.remove (54321);
   list1.print();
   
   LL list2(list1);
   list2.print();
   return 0;

}
//--------------------------------------------
