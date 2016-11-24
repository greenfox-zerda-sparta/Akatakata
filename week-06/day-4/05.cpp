#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

template<class T>
void print_vector(const vector<T>& vect) {
  unsigned int length = vect.size();
  for (unsigned int i = 0; i < length; i++) {
    cout << vect[i] << " ";
  }
  cout << endl;
}

int main() {
  //create a vector of integers with the size of 10, fill them with random numbers
  //create a vector of doubles and reserve place for 10 items
  //push and item to the end of the vector with the double places
  //print which vectors size is higher (and why?)
  vector<int> v(10);
  for (unsigned int i = 0; i < v.size(); i++) {
    v[i] = rand() % 11;
  }
  print_vector(v);

  vector<double> d;
  d.reserve(10);
  d.push_back(3.14);
  print_vector(d);

  (v.size() > d.size()) ? cout << "int vector is bigger" : cout << "double vector is bigger";
  cout << endl;

  return 0;
}