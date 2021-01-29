#include <iostream>
using namespace std;

// Create a function
void myFunction()
{
  cout << "I just got executed!";
}

int AddNumbers(int i, int j)
{
  return i + j;
}

int main()
{
  myFunction(); // call the function
  cout << '\n' << AddNumbers(7, 8) << endl;
  return 0;
}