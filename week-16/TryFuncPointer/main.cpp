#include <iostream>
#include <map>

void print_one() {
  std::cout << 1 << std::endl;
}

void print_two() {
  std::cout << 2 << std::endl;
}

void print_three() {
  std::cout << 3 << std::endl;
}

void print_four() {
  std::cout << 4 << std::endl;
}


int main() {
  void(*ptr_func_one)() = print_one;
  void(*ptr_func_two)() = print_two;
  void(*ptr_func_three)() = print_three;
  void(*ptr_func_four)() = print_four;

  std::map<int, void(*)()> function_map;
  function_map[1] = ptr_func_one;
  function_map[2] = ptr_func_two;
  function_map[3] = ptr_func_three;
  function_map[4] = ptr_func_four;

  std::cout << "Calling from: map<int, void(*)()>" << std::endl;
  function_map[1]();
  function_map[2]();
  function_map[3]();
  function_map[4]();
  
  system("pause");
  return 0;
}