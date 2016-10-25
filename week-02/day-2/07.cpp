#include <iostream>
#include <string>

using namespace std;

int main() {
  char g1 = 'a';
  double g2 = 12.345;
  // Tell if g1 is stored in more bytes than g2
  if (sizeof(g1) > sizeof(g2)) {
	  cout << g1 << " is stored in more bytes, than " << g2 <<endl;
  } else {
	  cout << g1 << " is stored in less bytes, than " << g2 <<endl;
  }
  return 0;
}
