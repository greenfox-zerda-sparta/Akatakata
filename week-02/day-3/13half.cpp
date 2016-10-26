#include <iostream>
#include <string>
using namespace std;

// Create a function that prints each word in a string into a new line!
void eachWordNewLine(string &_text, int length);

// Create an other function that takes a string and an array of strings as it's input
// and puts each word in the original string into a new element in the array of strings.
// Decide which argument should be a pointer and which shouldn't.
//void wordsToArray(string text, string words[]);

// In the main function, print out each element of the array into a new line!
int main(int argc, char **argv){
  string instructions = "Create a function that prints each word in a string into";
  string addition[] = {"Decide", "which", "argument", "should", "be", "a", "pointer"};
  string *pointer = &instructions;
  int instructions_l = sizeof(instructions) / sizeof(*pointer);

  eachWordNewLine(instructions, 56);

  return 0;
}

void eachWordNewLine(string &_text, int length) {
  //cout << length;
  for (int i = 0; i < length; i++) {
    char c = _text[i];
    //cout << (c == 'r') << " " << c << endl;
    if (c == ' ') {
      cout << endl;
      continue;
    }
    cout << c;

  }
}
