#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void weird_mixing_elements(vector<double>& vect) {
  for (unsigned int i = 0; i < 20; i++) {
    unsigned int rand_index = rand() % vect.size();
    vect[rand_index] += vect.back();
    vect.pop_back();
  }
}

template<class T>
void print_vector(const vector<T>& vect) {
  unsigned int length = vect.size();
  for (unsigned int i = 0; i < length; i++) {
    cout << vect[i] << " ";
  }
  cout << endl;
}

int main() {
  //create a vector of doubles with the size of 30, with every element equal of 1.5
  //create functions that takes this vector, pick the last element of it and adding its value to
  //an other item from the vector(this item place is random) and remove the last element at the end
  //run this function 20 times, then print every element of the vector 
  vector<double> v(30, 1.5);
  weird_mixing_elements(v);
  print_vector(v);
  return 0;
}