#include <iostream>
#include <string>

using namespace std;

int factorial(int n) {
  if (n >= 1) {
    return n*factorial(n - 1);
  } else {
    return 1;
  }
}

int main() {
  // create a function that returns it's input factorial
	int a = 0;
	cout << "Give me a number!" << endl;
	cin >> a;
	cout << "It's factorial is: " << factorial(a) << endl;

	return 0;
}
