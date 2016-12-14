#include <iostream>
#include "Color.h"

Color::Color() : red(0), green(0), blue(0) {}

Color::Color(unsigned char r, unsigned char g, unsigned char b) : red(r), green(g), blue(b) {}

Color::Color(std::string hexcode) {
  // something
}

Color::Color(const Color &obj) {
  red = obj.red;
  green = obj.green;
  blue = obj.blue;
  std::cout << "Copy constructor in work!" << std::endl;
}

std::string Color::get_color_code() {
  return  std::to_string((int)red) + ", " + std::to_string((int)green) + ", " + std::to_string((int)blue);
}

Color Color::blend(const Color& other) {
  Color temp(other);
  temp.red = (red + other.red) / 2;
  temp.green = (green + other.green) / 2;
  temp.blue = (blue + other.blue) / 2;
  return temp;
}

bool Color::is_amount_correct(float amount) {
  try {
    if (amount < 0 || amount > 1) {
      throw "Amount should be between 0 and 1.";
    }
  } catch (const char* expr) {
    std::cout << "Error: " << expr << std::endl;
    return false;
  }
  return true;
}

void Color::darken(float amount) {
  if (is_amount_correct(amount)) {
    red = red - (red * amount);
    green = green - (green * amount);
    blue = blue - (blue * amount);
  }
}

void Color::lighten(float amount) {
  if (is_amount_correct(amount)) {
    red = red + ((255 - red) * amount);
    green = green + ((255 - green) * amount);
    blue = blue + ((255 - blue) * amount);
  }
}

Color Color::operator+(const Color& obj) {
  return this->blend(obj);
}

Color& Color::operator++() {
  lighten(0.1);
  return *this;
}

Color& Color::operator++(int) {
  Color temp(*this);
  ++*this;
  return temp;
}
