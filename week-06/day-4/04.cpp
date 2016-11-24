#include <iostream>
#include <vector>

using namespace std;

void add_char_to_vector(vector<char>& vect) {
  cout << "Enter characters to add. Enter . to finish adding characters." << endl;
  char input = ' ';
  cin >> input;
  while (input != '.') { 
    vect.push_back(input);
    cin >> input;
  }
}

void print_vector(const vector<char>& vect) {
  unsigned int length = vect.size();
  for (unsigned int i = 0; i < length; i++) {
    cout << vect[i] << " ";
  }
  cout << endl;
}

int main() {
  //create a vector of chars with the size of zero;
  //write a function where the user can add characters to the end of this vector
  vector<char> v(0);
  add_char_to_vector(v);
  print_vector(v);
  return 0;
}