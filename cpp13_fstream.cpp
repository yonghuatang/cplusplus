#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream // Create and open a text file
    MyFile("example.txt");
    MyFile << "Hello everyone!"; // Write to the file
    MyFile.close(); // Close the file
}