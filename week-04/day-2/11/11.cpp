#include <iostream>
#include <string>
#include "triangle.h"

using namespace std;

int main() {
    // Create a triangle class that takes a length parameter and prints a triangle like this:
    //   *
    //   **
    //   ***
    //   ****
    //   *****
    //   ******
    // It should take a number as parameter that describes how many lines the triangle has
    cout << "Give me a number!" << endl;
    char mark = '*';
    unsigned int input = 0;
    cin >> input;
    Tri sample = Tri(input, mark);
    sample.show_triangle();
    cout << endl;
    sample.christmas_tree();
    cout << endl;
    sample.diamond();
  return 0;
}
