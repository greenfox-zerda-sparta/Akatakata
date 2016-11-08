#include <iostream>
#include <string>
#include "triangle.h"


Tri::Tri(unsigned int number, char symbol) {
  this->length = number;
  this->symbol = symbol;
}

void Tri::draw_characters(int number, char character) {
  for (int i = 0; i < number; ++i) {
    cout << character;
  }
}

void Tri::show_triangle() {
  for (unsigned int i = 0; i < length; i++) {
    draw_characters(i, symbol);
    cout << endl;
  }
}

void Tri::christmas_tree() {
  for (unsigned int i = 1; i <= length; i++) {
    draw_characters(length - i, ' ');
    draw_characters(i * 2 - 1, symbol);
    cout << endl;
  }
}

void Tri::diamond() {
  for (unsigned int i = 0; i <= length / 2 ; i++) {
    draw_characters(length / 2 +1 - i, ' ');
    draw_characters(i * 2 - 1, symbol);
    cout << endl;
  }
  if (length % 2 != 0) {
    draw_characters(length, symbol);
    cout << endl;
  }
  for (int i = length / 2; i >= 0; i--) {
    draw_characters(length / 2 + 1  - i, ' ');
    for (int n = i * 2 - 1; n >= 1; n--) {
      cout << symbol;
    }
    cout << endl;
  }
}
