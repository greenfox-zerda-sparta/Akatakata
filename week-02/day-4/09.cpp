
#include <iostream>

using namespace std;

void triangle();

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
  triangle();
  return 0;
}

void triangle() {
  int num = 0;
  string print = "";
  cout << "Give me a positive number!" << endl;
  cin >> num;
  for (int i = 1; i <= num; i++) {
    for (int x = 0; x <= num - 1- i; x++) {
      cout << " ";
    }
    for (int n = 1; n <= i * 2 - 1; n++) {
      cout << '*';
    }
    cout << endl;
  }
  for (int i = num - 1; i >= 1; i--) {
    for (int x = 1; x <= num - i; x++) {
      cout << " ";
    }
    for (int n = i * 2 - 1; n >= 1; n--) {
      cout << '*';
    }
    cout << endl;
  }
}
