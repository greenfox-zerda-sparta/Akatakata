#include <iostream>
#include <vector>

// The method should take a sorted array of numbers and a number. 
// (The array can be any array like container like vector) The method should return true
// if the array consists the number and false otherwise. The method should have 
// better than linear order of growth based on the input array size.

bool is_contain(std::vector<int> vec, int num) {
  if (vec[vec.size() / 2] == num) {
    std::cout << "True. " << num << " is " << vec[vec.size() / 2] << std::endl;
    return true;
  } else {
    if (vec.size() != 1) {
      vec[vec.size() / 2] < num ? vec.erase(vec.begin(), vec.begin() + vec.size() / 2) :
          vec.erase(vec.begin() + vec.size() / 2, vec.end());
      is_contain(vec, num);
    } else {
      std::cout << "False." << std::endl;
      return false;
    }
  }
}

int main() {
  std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  std::vector<int> numbers2 = { 2, 3, 6, 8, 11, 27, 36 };
  for (int i : numbers) {
    is_contain(numbers, i);
  }
  is_contain(numbers, 11);
  is_contain(numbers, -1);

  for (int i : numbers2) {
    is_contain(numbers2, i);
  }
  is_contain(numbers2, 26);
  return 0;
}