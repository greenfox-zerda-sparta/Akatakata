#include <iostream>
#include <string>
#ifndef TRIANGLE_H_
#define TRIANGLE_H_

using namespace std;

class Triangle: public Shape {
  public:
  string* getName();
};

#endif /* TRIANGLE_H_ */
