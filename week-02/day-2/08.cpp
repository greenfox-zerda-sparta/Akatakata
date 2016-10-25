#include <iostream>
#include <string>

using namespace std;

int main() {
  int h[] = {3, 4, 5, 6, 7};
	// print the sum of all numbers in h
  int length = sizeof(h)/sizeof(int);
  int sum = 0;
  for (int i = 0; i <= length-1; i++) {
	  sum = sum + h[i];
  }
  cout << "The sum is " << sum << endl;
  return 0;
}
