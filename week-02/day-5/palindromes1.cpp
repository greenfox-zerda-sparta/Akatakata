#include <iostream>
#include <string>

using namespace std;

string CreatePalindrome(string text) {
  string palindrome = text;
  for (int i = text.size() - 1; i >= 0; i--) {
    palindrome = palindrome + text[i];
  }
  return palindrome;
}

int main() {
  string output = CreatePalindrome("pear");

  cout << output << endl; // it prints: pearraep

  return 0;
}
