#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void fill_with_random(vector<int>& vect) {
  unsigned int length = vect.size();
  for (unsigned int i = 0; i < length; i++) {
    vect[i] = rand() % 11;
  }
}

void remove_evens(vector<int>& vect) {
  vector<int> v2;
  for (unsigned int i = 0; i < vect.size(); i++) {
    if (vect[i] % 2 != 0) {
      v2.push_back(vect[i]);
    }
  }
  vect.clear();
  for (unsigned int i = 0; i < v2.size(); i++) {
    vect.push_back(v2[i]);
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
  //create a vector of integers with the size of 20
  //fill this vector with random numbers from 0 to 10
  //print the items of the vector
  //remove the even numbers, then print the items again 
  vector<int> v(20);
  fill_with_random(v);
  print_vector(v);
  remove_evens(v);
  print_vector(v);
  return 0;
}