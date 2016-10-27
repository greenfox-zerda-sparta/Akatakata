
#include <iostream>

using namespace std;
void print_characters(int count, char c) {
  for (int i = 0; i < count; ++i) {
    cout << c;
  }
}

void triangle(char main_character, int times) {
  for (int row = 1; row <= times; ++row) {
    print_characters(row * 2 - 1, main_character);
    cout << endl;
  }
}

int main() {
  // create a function that takes a number and prints a triangle like this:
  // *
  // **
  // ***
  // ****
  // *****
  // ******
  //
  // The triangle should have as many lines as the value in the argument
  char mark = '*';
  triangle(mark, 6);
  return 0;
}

