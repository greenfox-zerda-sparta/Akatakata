#include <iostream>

using namespace std;

void pswapper(int *num1, int *num2);

int main() {
  int first = 12;
  int second = 54;

  // Write a function that takes two int pointers and swaps the values where the pointers point

  cout << "From: " << first << ", " << second  << endl;
  pswapper(&first, &second);
  cout << "To: " << first << ", " << second  << endl;
  return 0;
}

void pswapper(int *num1, int *num2) {
  int temp = 0;
  temp = *num1;
  *num1 = *num2;
  *num2 = temp;
}
