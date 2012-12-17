#include "CompSciProfessor.h"

class AdjunctProf:public CompSciProfessor
{
  private:
    char degree;
    int NoOfTA;
    int NoOfCourses;
  public:
    char GetDegree(){return degree;}
    int  GetNoOfTA(){return NoOfTA;}
    int  GetNoOfCourses(){return NoOfCourses;}
    void SetDegree(char degree){this->degree = degree;}
    void SetNoOfTA(int NoOfTA){this->NoOfTA = NoOfTA;}
    void SetNoOfCourses(int NoOfCourses){this->NoOfCourses = NoOfCourses;}
    
    AdjunctProf(){};
};

