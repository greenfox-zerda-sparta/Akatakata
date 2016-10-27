#include <iostream>

using namespace std;

void print_characters(int count, char c) {
  for (int i = 0; i < count; ++i) {
    cout << c;
  }
}

void diamond();

int main() {
  // Create a function that takes a number and prints a diamond like this:
  //
  //      *
  //     ***
  //    *****
  //   *******
  //  *********
  // ***********
  //  *********
  //   *******
  //    *****
  //     ***
  //      *
  //
  // The diamond should have as many lines as the value in the argument
  diamond();
  return 0;
}

void diamond() {
  int number = 0;
  cout << "Give me a positive number!" << endl;
  cin >> number;
  char mark = '*';
  for (int i = 1; i <= number; i++) {
    print_characters(number - i, ' ');
    print_characters(i * 2 - 1, mark);
    cout << endl;
  }
  for (int i = number - 1; i >= 1; i--) {
    print_characters(number - i, ' ');
    for (int n = i * 2 - 1; n >= 1; n--) {
      cout << mark;
    }
    cout << endl;
  }
}



