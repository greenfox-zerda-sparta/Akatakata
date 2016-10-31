#include <iostream>
#include <string>
#include <math.h>

using namespace std;

double string_to_number(string text) {
  int point_loc = text.find('.');
  int howmany_floats = text.length() - point_loc - 1;
  for (int i = point_loc; i < text.length() - 1; i++) {
    // chars moved to the left after removing the point
    text[i] = text[i + 1];
  }
  text.pop_back(); // removes the last, duplicated character
  double result = stoi(text) / pow(10, howmany_floats);
  return result;
}

int main() {
  // Implement a function that takes a string as an argument and converts it to a floating point number
  double number = string_to_number("-2.4");
  double number2 = string_to_number("-352.43477");
  double number3 = string_to_number("112.44");
  cout << number / 2 << endl; // should print -1.2
  cout << number2 / 2 << endl; // should print -176.217...setprecision?
  cout << number3 / 2 << endl; // should print -56.22
  return 0;
}
