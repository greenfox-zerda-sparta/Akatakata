#include <iostream>
#include <string>

using namespace std;

int countdown(int n) {
  if (n < 0) {
    return 0;
  }
  cout << n << " ";
  return countdown(n - 1);
}

int main() {
  // write a recursive function
  // that takes one parameter: n
  // and counts down from n
  countdown(10);
  return 0;
}