#include <iostream>
#include <string>

using namespace std;

string x_to_y(string text) {
  if (text.find("x") > text.length()) {
    return text;
  }
  return x_to_y(text.replace(text.find("x"), 1, "y"));
}

int main() {
  // Given a string, compute recursively (no loops) a new string where all the
  // lowercase 'x' chars have been changed to 'y' chars.
  string ex = "xoxixkxkxmxjxjxxtx";
  cout << x_to_y(ex) << endl;
  return 0;
}