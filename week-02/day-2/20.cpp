#include <iostream>
#include <string>

using namespace std;

int occurences(string text, char a) {
	int counter = 0;
	for (int i = 0; i < text.length(); i++) {
		if (text[i] == a) {
			counter = counter + 1;
		}
	}
	return counter;
}

int main() {
  string word = "makkoshotyka-also";
  char letter = 'o';
  // Write a function that takes a string and a character, and counts how many
  // times the character occures in the string and it should return a number

  cout << "Counting the letter " << letter << " in " << word << ": " << occurences(word, letter);
  return 0;
}
