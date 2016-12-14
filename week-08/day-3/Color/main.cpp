#include <iostream>
#include "Color.h"

using namespace std;
int main() {
  cout << "DEFAULT CONSTRUCTOR" << endl;
  Color first;
  cout << "first: " << first.get_color_code() << endl;
  cout << endl << "DEFINED CONSTRUCTOR" << endl;
  Color second(100, 0, 180);
  cout << "second: " << second.get_color_code() << endl;
  cout << endl << "COPY CONSTRUCTOR" << endl;
  Color third(second);
  cout << "third: " << second.get_color_code() << endl;
  cout << endl << "BLEND" << endl;
  cout << "second blended into first:   " << first.blend(second).get_color_code() << endl;
  cout << endl << "DARKEN" << endl;
  second.darken(0.4);
  cout << "second darkened by 0.4:   " << second.get_color_code() << endl;
 
  cout << endl << "LIGHTEN" << endl;
  third.lighten(0.3);
  cout << "third lightened by 0.3:   " << third.get_color_code() << endl;
  cout << "EXCEPTION" << endl;
  third.lighten(1.3);
  cout << "third lightened by 1.3:   " << third.get_color_code() << endl;

  cout << endl << "+ FOR BLEND" << endl;
  cout << "third blended into first: " << (first + third).get_color_code() << endl;

  cout << endl << "prefix ++ FOR lighten 10%" << endl;
  ++third;
  cout << "third lightened by 0.1: " << third.get_color_code() << endl;

  cout << endl << "postfix ++ FOR lighten 10%" << endl;
  third++;
  cout << "third lightened by 0.1: " << third.get_color_code() << endl;

  return 0;
}