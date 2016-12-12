// Create a function like macro, that gets an expression as it's input.
// If the expression is false, it should print out some error message.

#include <iostream>
#define my_own_error_msg_if_expr_false(a) if(!(a)){std::cerr << "some error message is here because the expression is false" << std::endl;}


int main() {
  int x = 3;
  int y = 2;
  my_own_error_msg_if_expr_false(x < y);
  int n = 4;
  int m = 5;
  my_own_error_msg_if_expr_false(n < m);
  return 0;
}