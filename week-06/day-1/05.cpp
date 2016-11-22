#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// Write a function that receives a string and a character.
// The function should return an array of strings.
// The function should split the string at the character it receives as the second argument.
// The character it uses to split should not be in any of the new strings.
// Example: split("What a nice day", ' ');
// Result: {"What", "a", "nice",  "day"}
// If the character is not in the string throw an exception.
//
// In the main function demonstrate the function when working, and when throwing an exception. 
// Write the results to the console.

bool is_in_string(string text, char mark) {
  for (unsigned int i = 0; i < text.size(); i++) {
    if (text.at(i) == mark) {
      return true;
    }
  }
  return false;
}

vector<string> split(string text, char mark) {
  if (!is_in_string(text, mark)) {
    throw "The character given to split the text is not in the string.";
  }
  vector<string> result = {};
  string word;
  stringstream stream(text);
  while (getline(stream, word, mark)) {
    result.push_back(word);
  }
  return result;
}

void print_vector(vector<string> text) {
  for (unsigned int i = 0; i < text.size(); i++) {
    cout << text[i] << ", ";
  }
  cout << endl;
}

int main() {
  try {
    print_vector(split("What a nice day", ' '));
    print_vector(split("What a nice day", 'b'));
  }
  catch (const char* exp) {
    cout << "Exception: " << exp << endl;
  }
}