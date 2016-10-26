#include <iostream>
#include <string>
using namespace std;

// Create a function that prints each word in a string into a new line!
// Create an other function that takes a string and an array of strings as it's input
// and puts each word in the original string into a new element in the array of strings.
// Decide which argument should be a pointer and which shouldn't.
// In the main function, print out each element of the array into a new line!

void eachWordNewLine(string text) {
  for (int i = 0; i < text.length(); i++) {
    char c = text[i];
    //cout << (c == 'r') << " " << c << endl;
    if (c == ' ') {
      cout << endl;
    } else {
      cout << c;
    }
  }
}

void stringArray(string text, string *array) {
  string word = "";
  for (int i = 0; i < text.length(); i++) {
    char c = text[i];
    if (c == ' ') {
      *array = word;
      array++;
      word = "";
    } else {
      word += text[i];
    }
  }
  *array = word;
}

int main(int argc, char **argv){
  string instructions = "Create a function that prints each word in a string into";
  string my_array[11] = {};
  eachWordNewLine(instructions);
  cout << endl;
  stringArray(instructions, my_array);

  for (int i = 0; i < 11; i++){
     cout << my_array[i] << endl;
  }
  return 0;
}

