#include <iostream>
#include <cmath>
using namespace std;

bool isprime(int n){
	for (int divider = 2; divider <= sqrt(n); divider++) {
		if (n % divider == 0) {
			return false;
		}
	}
	return true;
}

int main(){
  int number = 121;
  // create a function that decides if a number is a prime number.
  // It should take a number as an argument and return true if it is prime and
  // false otherwise.

  cout << "Is number " << number << " a prime? " << isprime(number);
	return 0;
}
