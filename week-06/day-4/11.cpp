#include <iostream>
#include <vector>

using namespace std;

void fill_matrix(vector<vector<int>>& vect, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    vect[i].resize(5, 0);
  }
}

void increase_inner_element(vector<vector<int>>& vect, int selector) {
  for (unsigned int i = 0; i < vect.size(); i++) {
    vect[selector - 1][i] += 1;
  }
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
  //create a function which increase the given inner vector elements by 1 (one inside vector, holding five 0)
  vector<vector<int>> outer(5);
  fill_matrix(outer, 5, 5);
  int selector = 3; // select v3
  increase_inner_element(outer, selector);
  print_outer_vector(outer);
  return 0;
}