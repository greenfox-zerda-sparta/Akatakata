#include <iostream>
#include <string>

using namespace std;

template<class T1, class T2>
void print_bigger_sized(T1 a, T2 b) {
  if (sizeof(b) == sizeof(a)) {
    cout << "Size of " << a << " and " << b << " are equal." << endl;
  }
  else {
  sizeof(a) > sizeof(b) ? cout << a << endl : cout << b << endl;
  }
}

int main() {
  //Create a function template that takes 2 different typenames, and prints out
  //which one is stored in more bytes from then
  print_bigger_sized<float, int>(7.9987, 145456);
  print_bigger_sized<char, float>('a', 145456.8);
  print_bigger_sized<bool, string>(1, "alma");
  return 0;
}