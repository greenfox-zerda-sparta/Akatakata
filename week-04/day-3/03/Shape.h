#include <iostream>
#include <string>

#ifndef SHAPE_H_
#define SHAPE_H_

using namespace std;

class Shape {
  private:
    double width;
    double height;
  protected:
    double mArea;  // in order to reach it from the virtual functions for calc_mArea()
  public:
    virtual double calc_mArea(); // child classes can override
    void setWidth(double new_width);
    void setHeight(double new_height);
    Shape(double height, double width);
    virtual string* getName(); // so the child classes can override
    double getWidth();
    double getHeight();
    double get_mArea();
    virtual ~Shape(); // so the child classes can override
};

#endif /* SHAPE_H_ */
