/*
 * 11.cpp
 *
 *  Created on: 2016 okt. 31
 *      Author: HP
 */
#include <iostream>
#include <string>

using namespace std;

char rotate_right(char array[5][5]) {
  char rotated_matrix[5][5];
    for (int row = 0; row < 5; row++) {
      for (int col = 0; col < 5; col++) {
        rotated_matrix[row][col] = array[4 - col][row];
      }
    }
  return rotated_matrix[5][5];
}

int main() {
  char matrix[5][5] = {
    {' ', ' ', '#', ' ', ' '},
    {' ', '#', ' ', '#', ' '},
    {' ', '#', '#', '#', ' '},
    {' ', '#', ' ', '#', ' '},
    {' ', '#', ' ', '#', ' '}
  };

  rotate_right(matrix[5][5]);

  // write the rotate_right function that rotates the matrix to the right
  // so the program should print this:
  //
  // ####
  //   # #
  // ####

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      cout << rotated_matrix[i][j];
    }
    cout << endl;
  }

  return 0;
}
