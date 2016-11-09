#include <iostream>
#include <string>
#ifndef TRIANGLE_H_
#define TRIANGLE_H_

using namespace std;

class Triangle: public Shape {
  private:
    double width;
    double height;
  public:
    Triangle(double w, double h);
    string* getName();
    double calc_mArea();
    ~Triangle();
};

#endif /* TRIANGLE_H_ */
