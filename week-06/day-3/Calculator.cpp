#include <iostream>
#include "Calculator.h"

template<class T>
Calculator<T>::Calculator(T num1, T num2) {
  value1 = num1;
  value2 = num2;
}

template<class T>
Calculator<T>::~Calculator()
{
}

template<class T>
T Calculator<T>::get_value1() {
  return this->value1;
}

template<class T>
T Calculator<T>::get_value2() {
  return this->value2;
}

template<class T>
void Calculator<T>::add() {
  cout << "I can add them: " << T(get_value1() + get_value2()) << endl;
}

template<class T>
void Calculator<T>::substract() {
  cout << "I can substract them: " << T(get_value1() - get_value2()) << endl;
}

template<class T>
void Calculator<T>::multiply() {
  cout << "I can multiply them: " << T(get_value1() * get_value2()) << endl;
}

template<class T>
void Calculator<T>::divide() {
  try {
    if (get_value2() == 0) {
      throw 1;
  }
  cout << "I can divide them: " << T(get_value1() / get_value2()) << endl;
  }
  catch (int e) {
    cout << "Error " << e << ". You should never try to divide by 0! $#%^@!!!!\n";
  }
}