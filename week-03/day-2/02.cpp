#include <string>
#include <iostream>

using namespace std;

struct RectangularCuboid {
  double a;
  double b;
  double c;
};
int get_surface(RectangularCuboid rcube) {
  int surface = 2 * (rcube.a * rcube.b + rcube.a * rcube.c + rcube.b * rcube.c);
  return surface;
}

int get_volume(RectangularCuboid rcube) {
  int volume = rcube.a * rcube.b * rcube.c;
  return volume;
}

// Write a function called "get_surface" that takes a RectangularCuboid
// and returns it's surface

// Write a function called "get_volume" that takes a RectangularCuboid
// and returns it's volume

int main() {
  RectangularCuboid one;
  one.a = 5;
  one.b = 6;
  one.c = 7;
  int s = get_surface(one);
  int v = get_volume(one);
  cout << s << " and " << v << " are surface and volume." << endl;
  return 0;
}
