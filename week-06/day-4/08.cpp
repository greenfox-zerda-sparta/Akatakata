#include <iostream>
#include <vector>

using namespace std;

void guess_chars(vector<char>& vect, const vector<char>& reference) {
  cout << "Enter the letters one by one.\n";
  for (unsigned int i = 0; i < vect.size(); i++) {
    char input = ' ';
    cout << "Enter letter " << i + 1 << ":\n";
    cin >> input;
    try {
      if (input == reference[i]) {
        vect[i] = input;
      }
      else {
        i--;
        throw "Your input is wrong.";
      }
    }
    catch (const char* expr) {
      cout << "--- Error!" << expr << "You can try again.\n" << endl;
    }
  }
  cout << "Correct!\n";
}

template<class T>
void print_vector(const vector<T>& vect) {
  unsigned int length = vect.size();
  for (unsigned int i = 0; i < length; i++) {
    cout << vect[i] << " ";
  }
  cout << endl;
}

int main() {
  //create a vector of characters with the size of 8
  //ask the user to fill this vector with characters one by one
  //at the end make sure the vector holds the letters of "GREENFOX"
  //so correct the user if he/she gives a different letter from the one we want them to give :)
  vector<char> reference = { 'g', 'r', 'e', 'e', 'n', 'f', 'o', 'x' };
  vector<char> guess(reference.size());
  guess_chars(guess, reference);
  print_vector(guess);
  return 0;
}