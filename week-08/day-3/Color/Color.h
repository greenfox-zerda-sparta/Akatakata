// #pragma once
#ifndef COLOR_H
#define COLOR_H
#include <cstdint>
#include <string>

class Color {
private:
  unsigned char red;
  unsigned char green;
  unsigned char blue;
public:
  Color();
  Color(unsigned char r, unsigned char g, unsigned char b);
  Color(std::string hexcode);
  Color(const Color &obj);
  std::string get_color_code();
  Color blend(const Color& other);
  bool is_amount_correct(float amount);
  void darken(float amount);
  void lighten(float amount);
  Color operator+(const Color& obj);
  Color& operator++();
  Color& operator++(int);
};

#endif
