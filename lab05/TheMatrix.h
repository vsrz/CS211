#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class TheMatrix;


// End of prototype section

class TheMatrix
{
  // MAKE ALL THE FUNCTIONS DEFINED IN THE PROTOTYPE SECTION ABOVE TO BE FRIEND OF THIS CLASS	
  friend TheMatrix  operator/ (const TheMatrix& M1, const TheMatrix& M2);
  friend TheMatrix  operator- (const TheMatrix& M1, const TheMatrix& M2);
  friend TheMatrix  operator+ (const TheMatrix& M1, const TheMatrix& M2);
  friend TheMatrix  operator* (const TheMatrix& M1, const TheMatrix& M2);
  friend ifstream&   operator>> (ifstream& is, TheMatrix& myMatrix); 
  friend ostream&   operator<< (ostream& is, const TheMatrix& myMatrix);

public:
	int  M[5][5];	// 5 by 5 matrix of integer
	TheMatrix(){ 
          for(int i=0;i<5;i++) 
            for(int j=0; j<5; j++) 
              M[i][j]=0;
        };
	~TheMatrix(){};
};
