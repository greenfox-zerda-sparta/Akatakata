#include <iostream>
#include <string>

using namespace std;

int fibonacci_rec(int nth) {
  if (nth == 0) {
    return 0;
  }
  if (nth == 1) {
    return 1;
  }
  return fibonacci_rec(nth - 1) + fibonacci_rec(nth - 2);
}

int main() {
  // The fibonacci sequence is a famous bit of mathematics, and it happens to
  // have a recursive definition. The first two values in the sequence are
  // 0 and 1 (essentially 2 base cases). Each subsequent value is the sum of the
  // previous two values, so the whole sequence is: 0, 1, 1, 2, 3, 5, 8, 13, 21
  // and so on. Define a recursive fibonacci(n) method that returns the nth
  // fibonacci number, with n=0 representing the start of the sequence.
  cout << fibonacci_rec(20) << endl;
  return 0;
}