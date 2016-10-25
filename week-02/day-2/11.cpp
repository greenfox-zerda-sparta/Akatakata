#include <iostream>
#include <string>

using namespace std;

string adda(string text) {
  return text + "a";
}

int main() {
  string k = "kuty";
  // write a function that gets a string as an input
  // and appends an 'a' character to its end
  cout << adda(k) << endl;
  return 0;
}
