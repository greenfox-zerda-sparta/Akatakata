#include <iostream>
#include <string>
#include "Calculator.h"
#include "Calculator.cpp"
using namespace std;

int main() {
  //Create a class template for a calculator
  //it should have all the basic methods: add, subtract, multiply, divide
  //use exceptions to handle errors in special cases! (find the special cases!)
  Calculator<int> tryit(1000, 1000);
  cout << "Your inputs are: " << tryit.get_value1() << " and " << tryit.get_value2() << endl;
  tryit.add();
  tryit.substract();
  tryit.multiply();
  tryit.divide();
  return 0;
}