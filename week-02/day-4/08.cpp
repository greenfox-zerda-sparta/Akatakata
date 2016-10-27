
#include <iostream>

using namespace std;

void triangle();

int main() {
  // Create a function that takes a number and prints a triangle like this:
  //
  //      *
  //     ***
  //    *****
  //   *******
  //  *********
  // ***********
  //
  // The triangle should have as many lines as the value in the argument
  triangle();
  return 0;
}

void triangle() {
  int num = 0;
  string print = "";
  cout << "Give me a positive number!" << endl;
  cin >> num;
  for (int i = 1; i <= num; i++) {
    for (int x = 0; x <= num - 1 - i; x++) {
      cout << " ";
    }
    for (int n = 1; n <= i * 2 - 1; n++) {
      cout << '*';
    }
    cout << endl;
  }
}
