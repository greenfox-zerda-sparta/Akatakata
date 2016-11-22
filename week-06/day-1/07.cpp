#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Write a function that can throw two kinds of exceptions: int and const char*
// It should receive an integer.
// It should return a string from the char* array defined below.
// If the integer is larger than 5, throw an integer exception. The value of the exception should be how much larger it is.
// If the integer is less than 0, it should throw a const char* exception stating, that it is a negative number.
//
// Illustrate both cases in the main function.
// HINT: Put each protected code segmetn in a new try-catch block.

const char* sentence[6] = { "What", "a", "pleasant", "surprise", "this", "is." };

string decider(int a) throw(int, const char*) {
  if (a > 5) {
    throw (a - 5);
  }
  if (a < 0) {
    throw "Your input is a negative number.";
  }
  string result;
  for (unsigned int i = 0; i < 6; i++) {
    result += *(sentence + i);
    result += ' ';
  }
  return result;
}

int main() {
  try {
    cout << decider(3) << endl;
    cout << decider(7) << endl;
  }
  catch (int i) {
    cout << "Exception: your input is " << i << " higher than 5." << endl;
  }

  try {
    cout << decider(-5) << endl;
   }
  catch (const char* expr) {
    cout << "Exception: " << expr << endl;
  }

  return 0;
}

