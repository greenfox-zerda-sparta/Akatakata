#include <iostream>
#include <string>

using namespace std;

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

class Tri {
  private:
    unsigned int length;
    char symbol;
  public:
    Tri(unsigned int number, char symbol);
    void draw_characters(int number, char character);
    void show_triangle();
    void christmas_tree();
    void diamond();
};




#endif /* TRIANGLE_H_ */
