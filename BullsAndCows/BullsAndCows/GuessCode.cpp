#include "GuessCode.h"

GuessCode::GuessCode() {
}

GuessCode::~GuessCode() {
}

void GuessCode::set_code(std::string code_text) {
  code = code_text;
}

std::string GuessCode::get_guess_code() {
  return code;
}