#include "GuessCode.h"

GuessCode::GuessCode(std::string input) : guess_code(input) {
}

GuessCode::~GuessCode() {
}

std::string GuessCode::get_guess_code() {
  return guess_code;
}