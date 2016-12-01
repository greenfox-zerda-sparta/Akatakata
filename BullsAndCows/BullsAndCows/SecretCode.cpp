#include "SecretCode.h"



SecretCode::SecretCode() : container("0123456789"), code_length(4) {
  generate_hidden_code(code_length);
}


SecretCode::~SecretCode(){
}

void SecretCode::generate_hidden_code(int code_length) {
  std::srand(unsigned(std::time(0)));
  std::random_shuffle(container.begin(), container.end());
  hidden_code = container.substr(0, code_length);
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