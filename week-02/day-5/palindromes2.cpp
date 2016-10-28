#include <iostream>
#include <string>

using namespace std;
// Create a function that searches for all the palindromes
// in a string that are at least than 3 characters, and
// returns a list with the found palindromes.

void find_words(string &text, int count, int start, int mod, string &word, string &to){
  // Finds palindromes of odd and even length in text
  // writes them to string if longer than 2 chars, and resets counter
  while (text[start - count + mod] == text[start + count]) {
    count++;
  }
  for (int n = start +1 - count + mod; n < start + count; n++) {
    word = word + text[n];
  }
  if (word.size() > 2) {
    to = to + "'" + word + "', ";
  }
  count = 1;
  word = "";
}

string SearchPalindromes(string text) {
  string palis = "";
  string to_concat = "";
  int distance = 1;
  for (int i = 0; i < text.size(); i++) {
    if (text[i - distance] == text[i + distance]) {
      find_words(text, distance, i, 0, to_concat, palis);
    }
    if (text[i] == text[i + distance]) {
      find_words(text, distance, i, 1, to_concat, palis);
    }
  }
  return palis;
}

int main() {
  string output = SearchPalindromes("dog goat dad duck doodle never");
  cout << output << endl; // it prints: ['og go', ' dad ', 'd d', 'dood', 'eve']
  return 0;
}
