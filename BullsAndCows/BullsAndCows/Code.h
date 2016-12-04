// #pragma once
#ifndef CODE_H
#define CODE_H

class Code {
protected:
  std::string possible_elements;
  unsigned int code_length;
  std::string code;
public:
  Code();
  ~Code();
  bool is_code_correct();
  bool check_for_code_error_duplicated_char();
  bool check_for_code_error_length();
  bool check_for_code_error_wrong_chars();

};
#endif
