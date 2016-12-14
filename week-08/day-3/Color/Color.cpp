#include<string>
#include "Color.h"

Color::Color() : red(0), green(0), blue(0) {}

Color::Color(unsigned char r, unsigned char g, unsigned char b) : red(r), green(g), blue(b) {}

Color::Color(std::string hexcode) {
  // something
}