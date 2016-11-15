#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void reverse_text(string filename) {
  string result = "";
  ifstream my_file;
  my_file.open(filename);
  string line;
  string temp = "";
  while (getline(my_file, line)) {
    temp += (line + "\n");
    result = temp + result;
    temp = "";
  }
  cout << result << endl;
  my_file.close();
}

int main() {
  // Create a program that decrypts the file called "reversed-order.txt",
  // and pritns the decrypred text to the terminal window.
  reverse_text("reversed-order.txt");
  return 0;
}