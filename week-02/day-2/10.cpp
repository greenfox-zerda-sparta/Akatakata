#include <iostream>
#include <string>

using namespace std;

int doubler(int n) {
  return n * 2;
}

int main() {
  int j = 123;
  // create a function that doubles it's input
  // double j with it
  cout << "The double of " << j << ": " << doubler(j) << endl;
  return 0;
}
