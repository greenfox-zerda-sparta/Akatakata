// Create a sum method in your class which has a method that takes a vector reference of integers as parameter
#include <vector>
#include <numeric>

class Things {
public:
  std::vector<int> integers;
  int sum() {
    return std::accumulate(integers.begin(), integers.end(), 0);
  }
};