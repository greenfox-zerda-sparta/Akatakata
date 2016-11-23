// #pragma once
#ifndef CALCULATOR_H
#define CALCULATOR_H

template<class T>
class Calculator
{
private:
  T value1;
  T value2;
public:
  Calculator(T num1, T num2);
  ~Calculator();
  void add();
  void substract();
  void multiply();
  void divide();
  T get_value1();
  T get_value2();
};
#endif

