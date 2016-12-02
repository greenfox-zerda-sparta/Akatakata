#include <iostream>
// #include <string>
#include <cstdlib>
#include <algorithm> 
#include <ctime>
#include "SecretCode.h"

SecretCode::SecretCode() : Code() {
  generate_hidden_code(code_length);
}

SecretCode::~SecretCode(){
}

void SecretCode::generate_hidden_code(int code_length) {
  std::srand(unsigned(std::time(0)));
  std::random_shuffle(possible_elements.begin(), possible_elements.end());
  hidden_code = possible_elements.substr(0, code_length);
  std::cout << "Secret Code generated!" << std::endl;
}

std::string SecretCode::get_hidden_code() {
  return hidden_code;
}

void SecretCode::print_formatted_hidden_code() {
  for (unsigned int i = 0; i < code_length; i++) {
    std::cout << hidden_code[i] << " ";
  }
  std::cout << std::endl;
}

unsigned int SecretCode::get_code_length() {
  return code_length;
}