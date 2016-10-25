#include <iostream>
#include <string>

using namespace std;

void  greetz(string name) {
  cout << "Hello " << name << "!" << endl;
}

int main() {
  string i = "Jozsi";
  // create a function that takes a string argument and greets it.
  greetz(i);
  return 0;
}
