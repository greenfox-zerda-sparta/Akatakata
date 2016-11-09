#include <iostream>
#include <string>

using namespace std;

#ifndef SQUARE_H_
#define SQUARE_H_

class Square: public Shape {
  private:
    double width;
    double height;
    double mArea;
  public:
    Square(double w, double h);
    string* getName();
    double calc_mArea();
    ~Square();
};


#endif /* SQUARE_H_ */
