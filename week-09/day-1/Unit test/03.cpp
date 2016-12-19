#include <iostream>

class Things {
public:
  unsigned int fibonacci_rec(unsigned int nth) {
    if (nth == 0) {
      return 0;
    }
    if (nth == 1) {
      return 1;
    }
    return fibonacci_rec(nth - 1) + fibonacci_rec(nth - 2);
  }
};