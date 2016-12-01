#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm> 
#include <ctime>

int main() {
  std::string container = "0123456789";
  std::srand(unsigned(std::time(0)));
  std::random_shuffle(container.begin(), container.end());
  std::cout << container[0] << " " << container[1] << " " << container[2] << " " << container[3] << std::endl;

  return 0;
}