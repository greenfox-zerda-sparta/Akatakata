#include <iostream>
#include <string>

using namespace std;

template<class T>
class Thing {
private:
  T value;
  T something;
public:
  Thing(T a, T b) {
    value = a;
    something = b;
  }

  T get_value() {
    return value;
  }

  T get_something() {
    return something;
  }

  void set_value(T _value) {
    value = _value;
  }

  void set_something(T _something) {
    something = _something;
  }
};

int main() {
  //Create a simple class template which contains 2 item and has both a get and a set method for these!
  Thing<string> thing1("egy", "ketto");
  thing1.set_something("tenyleg");
  thing1.set_value("nahat");
  cout << thing1.get_value() << " " << thing1.get_something() << endl;
  return 0;
}