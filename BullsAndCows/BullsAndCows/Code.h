// #pragma once
#ifndef CODE_H
#define CODE_H

#include <string>

class Code {
protected:
  std::string possible_elements;
  unsigned int code_length;
public:
  Code();
  ~Code();
};
#endif
