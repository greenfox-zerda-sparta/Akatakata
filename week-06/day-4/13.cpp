#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void fill_matrix(vector<vector<int>>& vect, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    vect[i].resize(5, 0);
    for (int j = 0; j < cols; j++) {
      if (i == j) {
        vect[i][j] = 1;
      }
    }
  }
}

void change_matrix(vector<vector<int>>& vect, int rows, int cols, int sel_row, int sel_col) {
  for (int i = 0; i < rows; i++) {
    vect[sel_row][i] = 1;
  }
  for (int i = 0; i < cols; i++) {
    vect[i][sel_col] = 1;
  }
}

void mirror_horizontally(vector<vector<int>>& vect, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    reverse(vect[i].begin(), vect[i].end());
  }
}

void mirror_vertically(vector<vector<int>>& vect, int rows, int cols) {
  for (int i = rows - 1; i >= 0; i--) {
    vect.push_back(vect[i]);
  }
  vect.erase(vect.begin() + 0, vect.begin() + (rows));
}

void print_matrix(const vector<vector<int>>& vect) {
  for (unsigned int i = 0; i < vect.size(); i++) {
    for (unsigned int j = 0; j < vect[i].size(); j++) {
      cout << vect[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  //Create a 2 dimensional vector with matrix!
  // 1 0 0 0
  // 0 1 0 0
  // 0 0 1 0
  // 0 0 0 1
  // Extend it to the following format:
  // 1 1 1 1 1
  // 0 1 0 0 1
  // 0 0 1 0 1
  // 0 0 0 1 1
  // 0 0 0 0 1
  // Mirror it horizontaly!
  // Mirror it verticaly!

  vector<vector<int>> outer(5);
  fill_matrix(outer, 5, 5);
  print_matrix(outer); 
  cout << endl;

  // some 1 put in
  change_matrix(outer, 5, 5, 0, 4);
  print_matrix(outer); 
  cout << endl;

  // mirror horizontally
  mirror_horizontally(outer, 5, 5);
  print_matrix(outer); 
  cout << endl;

  // mirror vertically
  mirror_vertically(outer, 5, 5); 
  print_matrix(outer);
  cout << endl;
  return 0;
}