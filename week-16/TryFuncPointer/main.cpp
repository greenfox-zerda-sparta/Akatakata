#include <iostream>
#include <map>
#include <vector>

struct IDs {
  int first;
  int second;
  int third;
};

void print_one() {
  std::cout << "This function writes: " << 1 << std::endl;
}

void print_two() {
  std::cout << "This function writes: " << 2 << std::endl;
}

void print_three() {
  std::cout << "This function writes: " << 3 << std::endl;
}

void print_four() {
  std::cout << "This function writes: " << 4 << std::endl;
}

void print_number(int num) {
  std::cout << "This function writes a number, now: " << num << std::endl;
}


int main() {
  void(*ptr_func_one)() = print_one;
  void(*ptr_func_two)() = print_two;
  void(*ptr_func_three)() = print_three;
  void(*ptr_func_four)() = print_four;
  void(*ptr_func_number)(int num) = print_number;

  std::map<int, void(*)()> function_map;
  function_map[1] = ptr_func_one;
  function_map[2] = ptr_func_two;
  function_map[3] = ptr_func_three;
  function_map[4] = ptr_func_four;

  std::map<int, void(*)(int)> function_map_with_arg;
  function_map_with_arg[5] = ptr_func_number;

  std::cout << "Calling from: map<int, void(*)()>" << std::endl;
  function_map[1]();
  function_map[2]();
  function_map[3]();
  function_map[4]();

  std::cout << "Calling from: map<int, void(*)(int)> which has an argument." << std::endl;
  function_map_with_arg[5](9);
  function_map_with_arg[5](11);
  
  std::vector<IDs> vec;
  vec.push_back({ 1, 2, 3 });
  std::cout << vec[0].first << " " << vec[0].third << std::endl;
  system("pause");
  return 0;
}