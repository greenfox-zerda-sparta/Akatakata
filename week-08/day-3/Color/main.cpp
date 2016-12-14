#include <iostream>
#include "Color.h"

using namespace std;
int main() {
  Color first;
  cout << "first: " << first.get_color_code() << endl;

  Color second(100, 0, 180);
  cout << "second: " << second.get_color_code() << endl;

  Color third(second);
  cout << "third: " << second.get_color_code() << endl;

  cout << "fourth: " << first.blend(second).get_color_code() << endl;
  return 0;
}