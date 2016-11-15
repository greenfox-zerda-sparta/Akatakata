#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void reverse_lines(string filename) {
  string result = "";
  ifstream my_file;
  my_file.open(filename);
  string line;
  while (getline(my_file, line)) {
    for (int i = strlen(line.c_str()) - 1; i >= 0; i--) {
      result += line.c_str()[i];
    }
    result += '\n';
  }
  cout << result << endl;
  my_file.close();
}

int main() {
  // Create a program that decrypts the file called "reversed-lines.txt",
  // and pritns the decrypred text to the terminal window.
  reverse_lines("reversed-lines.txt");
  return 0;
}