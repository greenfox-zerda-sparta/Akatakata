#include <iostream>
#include "Color.h"

using namespace std;
int main() {
  Color first;
  cout << first.get_color_code() << endl;

  Color second(100, 0, 0);
  cout << second.get_color_code() << endl;

  Color third(second);
  cout << second.get_color_code() << endl;
  return 0;
}