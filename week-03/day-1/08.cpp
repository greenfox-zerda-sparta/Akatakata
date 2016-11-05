#include <iostream>

using namespace std;

/**
 * Create a function that takes a number and returns a pointer that points to a two dimensional array characters.
 * It should fill the array like (if the number is 7):
 *  #######
 *  ##   ##
 *  # # # #
 *  #  #  #
 *  # # # #
 *  ##   ##
 *  #######
 */

char* box_with_x(int number) {
  const int row = number;
  const int col = number;
  char** box = new char*[row];
  for(int i = 0; i < row; ++i) {
    box[i] = new char[col];
  }
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (i == 0 || i == number - 1 || j == 0 || j == number - 1 || i == j || i + j == number - 1) {
        box[i][j] = '#';
      } else {
        box[i][j] = ' ';
      }
    }
  }

  for(int i = 0; i < number; i++) {
    for(int j = 0; j < number; j++) {
      cout << box[i][j];
    }
    cout << endl;
  }
  return *box;
  // Ha returnolom a pointert, ami egy array of pointerre mutat, hogy tudom deletelni?
  // igy lehetne inkabb void, de a feladatl returnt ker
}

int main() {
  int input = 0;
  cout << "Give me a number" << endl;
  cin >> input;
  char* array = box_with_x(input);
  delete[] array;
  array = nullptr;
  return 0;
}
