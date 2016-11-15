#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool copy_file(string file_from, string file_to) {
  ifstream from_file;
  from_file.open(file_from);
  ofstream to_file;
  to_file.open(file_to);
  if (from_file.is_open() && to_file.is_open()) {
    string line;
    while (getline(from_file, line)) {
      to_file << line << "\n";
    }
    from_file.close();
    to_file.close();
    return true;
  }
  else {
    return false;
  }

}

int main() {
  // Write a function that copies a file to an other
  // It should take the filenames as parameters
  // It should return a boolean that shows if the copy was successful

  cout << copy_file("duplicated-chars.txt", "sample.txt") << endl;
  return 0;
}