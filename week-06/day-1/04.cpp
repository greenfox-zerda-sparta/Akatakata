#include <iostream>
#include <string>
using namespace std;

// Write a function that receives a string and an unsigned integer.
// The function should return an array of strings, with two string in it.
// The first string should be the first part of the original string
// Characters in range [0,index-1].
// The second part should be the rest of the string characters range [index,length-1]
// Example: split("Rebarbara", 2)
// Result: {"Re", "barbara"}
// If the index is out of bounds, throw an exception.
//
// In the main function demonstrate the function when working, and when throwing an exception. 
// Write the results to the console.

string split(string text, int mark) {
  if (mark > text.size() - 1) {
    throw "Mark is out of bounds. You can not split a string there.";
  }
  string s[2] = {};
  s[0] = text.substr(0, mark);
  s[1] = text.substr(mark, text.size());
  return  s[0] + ", " +s[1];
}

int main() {
  try {
    cout << split("Rebarbara", 2) << endl;
    cout << split("Alma", 4) << endl;
  }
  catch (const char* excp) {
    cout << "Exception: " << excp << endl;
  }
  return 0;
}