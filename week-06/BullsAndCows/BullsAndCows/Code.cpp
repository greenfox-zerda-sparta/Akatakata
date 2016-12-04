#include <iostream>
#include "Code.h"

Code::Code() : possible_elements("0123456789"), code_length(4) {
}

Code::~Code() {
}

bool Code::is_code_correct() {
  if (check_for_code_error_length() == false ||
    check_for_code_error_duplicated_char() == false ||
    check_for_code_error_wrong_chars() == false) {
    return false;
  }
  return true;
}

bool Code::check_for_code_error_duplicated_char() {
  try {
    for (unsigned int i = 0; i < code_length - 1; i++) {
      for (unsigned int j = i + 1; j < code_length; j++) {
        if (code.at(i) == code.at(j)) {
          throw "Duplicated chars in code.";
        }
      }
    }
  } catch (const char* expr) {
    std::cout << "Error: " << expr << std::endl;
    return false;
  }
  return true;
}

bool Code::check_for_code_error_length() {
  try {

    if (code.length() != code_length) {
      throw "Incorrect code length.";
    } 
  } catch (const char* expr) {
    std::cout << "Error: " << expr << std::endl;
    return false;
  }
  return true;
}

bool Code::check_for_code_error_wrong_chars() {
  try {
    for (unsigned int i = 0; i < code_length; i++) {
      if (possible_elements.find(code.at(i)) >= possible_elements.length()) {
        throw "Incorrect character in code.";
      }
    }
  } catch (const char* expr) {
    std::cout << "Error: " << expr << std::endl;
    return false;
  }
  return true;
}