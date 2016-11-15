#include <iostream>
#include <fstream>

using namespace std;

int main() {
  // Open a file called "third-exercise.txt"
  // Write numbers from 0 to 20 into the file each in a new line
  ofstream my_file;
  my_file.open("third-exercise.txt");
  for (int i = 1; i <= 20; i++) {
    my_file << i << std::endl;
  }
  my_file.close();
  return 0;
}