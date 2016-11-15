#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void string_to_file(string filename, string text) {
  ofstream my_file;
  my_file.open(filename);
  my_file << text;
  my_file.close();
}

int main() {
  // Write a function that writes a string to a file
  // It should take the filename and the content as a string parameter
  string sample = "Adding some more text.";
  string_to_file("fifth-exercise.txt", sample);
  return 0;
}