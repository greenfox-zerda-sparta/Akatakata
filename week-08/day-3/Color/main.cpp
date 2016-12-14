#include <iostream>
#include <cstdint>
#include "Color.h"

using namespace std;
int main() {
  Color first;
  cout << first.get_color_code() << endl;

  Color second(100, 0, 0);
  cout << second.get_color_code() << endl;

  unsigned char a = 25;
  unsigned char b = 30;
  cout << (int)a;
  return 0;
}