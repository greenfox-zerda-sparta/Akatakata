#include <iostream>
#include <math.h>
using namespace std;

// Create a function that list all prime palindrome numbers
// between 0 and 1000000 and stores it in an array, then prints
// the 3rd element of it this array in binary format.

bool isPrime(int n){
  for (int divider = 2; divider <= sqrt(n); divider++) {
    if (n % divider == 0) {
      return false;
    }
  }
  return true;
}

bool isPalindrome(int n) {
   int nchange = n;
   int reverse = 0;
   int last_digit = 0;
   while (nchange > 0){
        last_digit = nchange % 10;
        nchange = nchange / 10;
        reverse = reverse * 10 + last_digit;
   }
   if (reverse == n) {
     return true;
   } else {
     return false;
   }
}

int prime_pali(int number, int array[113]) {
  int index = 0;
  int counter = 0;
  for (int i = 2; i <= number; i++) {
    if (isPrime(i) == 1) {
      if (isPalindrome(i) == 1) {
        cout << i << endl;
        *(array + index) = i;
        index++;
        counter++;
      }
    }
  }
  cout << "There are " << counter << " prime palindromes till " << number << "." << endl;
  return array[113];
}

void to_binary(int n) {
  if (n / 2 != 0) {
    to_binary(n / 2);
  }
  cout << n % 2;
}

int main() {
  int prime_palindrome[113] = {};
  prime_pali(1000000, prime_palindrome);
  cout << "The third palindrome prime is " << prime_palindrome[2] << endl;
  cout << "In binary: " << endl;
  to_binary(prime_palindrome[2]);
  return 0;
}
