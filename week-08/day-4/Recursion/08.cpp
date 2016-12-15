#include <iostream>
#include <string>

using namespace std;

string remove_all_x(string text) {
  if (text.find("x") > text.length()) {
    return text;
  }
  text.erase(text.begin() + text.find("x"));
  return remove_all_x(text);
}

int main() {
  // Given a string, compute recursively a new string where all the 'x' chars have been removed.
  string ex = "xoxixkxkxmxjxjxxtx";
  ex.erase(ex.begin() + ex.find("x"));
  cout << remove_all_x(ex) << endl;
  return 0;
}