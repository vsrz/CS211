#include <iostream>

using namespace std;

bool IsFibonacci(long num);
long Fibonacci(long n);

int main()
{
  long n;
  while (n >= 0)
  {
    cout << "Input number: ";
    cin >> n;
    if (IsFibonacci(n)) cout << "Success." << endl << endl;
    else cout << "Sorry, not a FB number." << endl << endl;
   }
  cout << "Have a nice day." << endl;
  return 0;
}

bool IsFibonacci(long num)
{
  int n = 0;
  while (Fibonacci(num) > Fibonacci(n))
    if (num == Fibonacci(n))
      return true;
    else n++;
  return false;
}

// Returns nth number in the Fibonacci Seq
long Fibonacci(long n) 
{
    if (n <= 1) 
      return n;
    else
      return Fibonacci(n-1) + Fibonacci(n-2);
}
