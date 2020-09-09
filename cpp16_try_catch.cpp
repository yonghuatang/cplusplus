// exceptions
#include <iostream>
using namespace std;

int main() {
  int x;
  try {
    throw 20;
  }
  catch (int e) {
    cout << "An exception occurred.";
  }
  return 0;
}