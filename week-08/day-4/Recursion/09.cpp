#include <iostream>
#include <string>

using namespace std;

string star_insert(string text) {
  if (text.find("*") > text.length()) {
    text.insert(text.length() - 1, "*");
  }
  if (text.find("*") - 1 == 0) {
    return text;
  }
  return star_insert(text.insert(text.find("*") - 1, "*"));
}

int main() {
  // Given a string, compute recursively a new string where all the
  // adjacent chars are now separated by a "*".
  string ex = "greenfox";

  cout << star_insert(ex) << endl;
  return 0;
}