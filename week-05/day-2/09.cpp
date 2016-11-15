#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void decrypt_from_file(string filename) {
  string result = "";
  ifstream my_file;
  my_file.open(filename);
  string line;
  string temp;
  while (getline(my_file, line)) {
    temp += (line + '\n');
    for (int i = 1; i <= strlen(temp.c_str()); i += 2) {
      result += temp.c_str()[i];
    }
    temp = " ";
  }
  cout << result << endl;
  my_file.close();
}

int main() {
  // Create a program that decrypts the file called "duplicated-chars.txt",
  // and pritns the decrypred text to the terminal window.
  decrypt_from_file("duplicated-chars.txt");
  return 0;
}