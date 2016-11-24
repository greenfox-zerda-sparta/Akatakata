#include <iostream>
#include <vector>

using namespace std;

void increase_inner_element(vector<vector<int>>& vect, int selector, int elem_selector) {
  vect[selector - 1][elem_selector - 1] += 1;
}

void print_outer_vector(const vector < vector<int>>& vect) {
  for (unsigned int i = 0; i < vect.size(); i++) {
    for (unsigned int j = 0; j < vect[i].size(); j++) {
      cout << vect[i][j] << " ";
    }
  }
  cout << endl;
}

int main() {
  //create a vector of vector of integers
  //the inner vectors have 5 integers, all of them 0
  //the outer vector is holding 5 vector
  //create a function which increase a specific element of an inner vector by 1

  vector<vector<int>> outer(5);
  vector<int> v1(5, 0);
  vector<int> v2(5, 0);
  vector<int> v3(5, 0);
  vector<int> v4(5, 0);
  vector<int> v5(5, 0);
  outer = { v1, v2, v3, v4, v5 };
  int select_vector = 3; // select v3
  int select_elem = 2; // 2nd element in v3
  increase_inner_element(outer, select_vector, select_elem);
  print_outer_vector(outer);
  return 0;
}