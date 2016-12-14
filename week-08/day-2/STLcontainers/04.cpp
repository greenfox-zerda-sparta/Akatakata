#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// write a function that takes a string and returns a map
// the map should have the letters of the string as keys and 
// it should have integers as values that represents how many times the
// letter appeared int the string



map<char, int> letter_counter(string word) {
  map<char, int> lettermap;
  for (int i = 0; i < word.size(); i++) {
    lettermap[word.at(i)] = count(word.begin(), word.end(), word.at(i));
  }
  return lettermap;
}


int main() {
  string proba = "almakortebarack";
  map<char, int> proba_map = letter_counter(proba);

  for (map<char, int>::iterator it = proba_map.begin(); it != proba_map.end(); it++) {
    cout << it->first << ": " << it->second << endl;
  }
  return 0;
}