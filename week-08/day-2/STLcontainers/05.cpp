#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <ctime>
#include <stdlib.h>

using namespace std;

// Write a simple program that creates secret santa pairs
// It should read names till the character q is typed to the standard output, 
// than it should print the names as secret santa pairs like:
// Clair - Mike
// Joe - Ron
// Cloe - Clair
// Ron - Cloe
// Mike - Joe

vector<string> get_names() {
  vector<string> list;
  string input = "";
  while (input != "q") {
    cout << "Type a name: " << endl;
    cin >> input;
    if (input != "q") {
      list.push_back(input);
    }
  }
  return list;
}

void push_elements_by_one(vector<string>& vect) {
  vect.push_back(vect[0]);
  vect.erase(vect.begin());
}

void secret_santa_maker() {
  vector<string> all_names = get_names();
  random_shuffle(all_names.begin(), all_names.end());
  vector<string> to_buy = all_names;
  push_elements_by_one(all_names);
  for (unsigned int i = 0; i < all_names.size(); i++) {
    cout << all_names[i] << " - " << to_buy[i] << endl;
  }
}

int main() {
  srand(time(NULL));
  secret_santa_maker();
  return 0;
}