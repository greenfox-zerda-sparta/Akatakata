/*
 * circle.h
 *
 *  Created on: 2016 nov. 8
 *      Author: HP
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

class Circle {
  private:
    double radius;
  public:
    Circle(double r);

    double get_circumference();

    double get_area();
};



#endif /* CIRCLE_H_ */
