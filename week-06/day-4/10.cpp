#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm> 

using namespace std;

int number_of_divisors(int input) {
  int counter = 0;
  for (unsigned int i = 1; i <= input; i++) {
    if (input % i == 0) {
      counter++;
    }
  }
  return counter;
}

void fill_with_randoms(vector<double>& vect) {
  for (unsigned int i = 0; i < vect.size(); i++) {
    vect[i] = (rand() % 2401);
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
  //find how much integer divisor 2400 has
  //create a vector of doubles, reserve place for the divisors of 2400
  //fill this places with random numbers from 0 to 2400
  //sort them in ascending order
  int num = 2400;
  cout << num << " has " << number_of_divisors(num) << " integer divisors." << endl;
  int size = number_of_divisors(num);
  vector<double> v(size);
  fill_with_randoms(v);
  sort(v.begin(), v.end());
  print_vector(v);
  return 0;
}