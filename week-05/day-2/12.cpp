#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void decrypt_encoded(string filename) {
  string result = "";
  ifstream my_file;
  my_file.open(filename);
  string line;

  while (getline(my_file, line)) {
    for (unsigned int i = 0; i < strlen(line.c_str()); i++) {
      if (line.c_str()[i] != ' ') {
        result += char(int(line.c_str()[i]) - 1);
      } else {
        result += " ";
      }
    }
    result += '\n';
  }
  cout << result << endl;
  my_file.close();
}

int main() {
  // Create a program that decrypts the file called "encoded-lines.txt",
  // and pritns the decrypred text to the terminal window.
  decrypt_encoded("encoded-lines.txt");
  return 0;
}