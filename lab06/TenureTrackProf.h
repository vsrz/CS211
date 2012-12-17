#include "CompSciProfessor.h"

class TenureTrackProf: public CompSciProfessor
{
  private:
    char rank;
    int yearOfExp;
  public:
    char GetRank(){return rank;}
    int  GetYearOfExp(){return yearOfExp;}
    void SetRank(char rank){this->rank = rank;}
    void SetYearOfExp(int yearOfExp){this->yearOfExp = yearOfExp;}
    TenureTrackProf(){};
};

