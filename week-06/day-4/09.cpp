#include <iostream>
#include <vector>

using namespace std;

void fill_matrix(vector<vector<int>>& vect, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    vect[i].resize(5, 0);
  }
}

void add_vector(vector<vector<int>>& main, vector<int>& to_add) {
  main.push_back(to_add);
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
  //create a vector of vector of integers, yeah a vector that holds vectors of integers
  //the inner vectors have 5 integers, all of them 0
  //the outer vector is holding 5 vector at the begining
  //create a function that will add a new vector of integers to the end of our outer vector
  vector<vector<int>> outer(5);
  fill_matrix(outer, 5, 5);
  vector<int> v6(5, 1);
  add_vector(outer, v6);
  print_outer_vector(outer);
  cout << outer.size() << endl;

  return 0;
}