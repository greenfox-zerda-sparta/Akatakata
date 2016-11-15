#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string read_file(string filename) {
  string result;
  ifstream my_file;
  my_file.open(filename);
  string line;
  while (getline(my_file, line)) {
    result += line + '\n';
  }
  my_file.close();
  return result;
}

int main() {
  // Write a function that reads the content of a file and returns it as a string
  // It should take the filename as a string parameter

  cout << read_file("duplicated-chars.txt"); // using txt from previous exercise
  return 0;
}