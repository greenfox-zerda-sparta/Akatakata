#include <iostream>
#include "Color.h"

using namespace std;
int main() {
  Color first;
  cout << "first: " << first.get_color_code() << endl;

  Color second(100, 0, 180);
  cout << "second: " << second.get_color_code() << endl;

  Color third(second);
  cout << "third: " << second.get_color_code() << endl << endl;

  cout << "second blended into first:   " << first.blend(second).get_color_code() << endl;

  second.darken(0.4);
  cout << "second darkened by 0.4:   " << second.get_color_code() << endl;

  third.lighten(0.3);
  cout << "third lightened by 0.3:   " << third.get_color_code() << endl;
  third.lighten(1.3);
  cout << "third lightened by 1.3:   " << third.get_color_code() << endl;
  return 0;
}