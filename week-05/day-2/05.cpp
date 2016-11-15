#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  // Write a program that prints a content of a file called "fifth-exercise.txt"
  // If it could not open the file it should write: "Could not open the file" to the standard error
  // The program should return 2 if there where an error
  ifstream my_file;
  my_file.open("fifth-exercise.txt");
  if (my_file.is_open()) {
    string line;
    while (my_file >> line) {
      cout << line << endl;
    }
    my_file.close();
  }
  else {
    cerr << "Could not open the file" << endl;
    return 2;
  }

  return 0;
}