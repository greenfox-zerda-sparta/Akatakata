// Implement the quick union algorithm as an object. 
// It should take an array length in its constructor. It should have a unite method 
// that takes two indexes of nodes and connects them. It should have a find method 
// that takes two indexes of nodes and returns a boolean if they are 
// in the same group.It shoudl have a getGroups method that returns a list of all groups.

#include <vector>
#include <iostream>
#include <map>

class Union {
public:
  Union(int _length) {
    length = _length;
    for (int i = 0; i < length; i++) {
      numbers.push_back(i);
    }
    siblings = std::vector<int>(length, 1);
  }

  int root(int i) {
    while (i != numbers[i]) {
      numbers[i] = numbers[numbers[i]];
      i = numbers[i];
    }
    return i;
  }

  void unite(int index1, int index2) { 
    if (siblings[root(index1)] >= siblings[root(index2)]) {
      siblings[root(index1)] += siblings[root(index2)];
      numbers[root(index2)] = root(index1);
    } else {
      siblings[root(index2)] += siblings[root(index1)];
      numbers[root(index1)] = root(index2);
    }
  }

  bool find(int index1, int index2) {
    return root(index1) == root(index2);
  }

  void getGroups() {
    // make groups:
    std::map<int, std::vector<int>> groups;
    for (int i = 0; i < length; i++) {
      groups[root(numbers[i])].push_back(i);
    }

    // printing
    std::cout << " Parent: ";
    for (auto i : numbers) { std::cout << i << " "; }

    std::cout << " GROUPS: ";
    for (auto pair : groups) {
      std::cout << "[  ";
      for (int i : pair.second) std::cout << i << "  ";
      std::cout << "] ";
    }
    std::cout << std::endl;
  }
 
private:
  std::vector<int> numbers;
  std::vector<int> siblings;
  int length;
};

int main() {
  Union uni = Union(10);
  std::vector<std::vector<int>> connections = { {3, 4}, {4, 9}, {8, 0}, {2, 3}, {5, 6}, {5, 9}, {7, 3}, {4, 8}, {6, 1} };
  for (std::vector<int> nodes : connections) {
    uni.unite(nodes[0], nodes[1]);
    std::cout << "connect: " << nodes[0] << "-" << nodes[1]; 
    uni.getGroups();
  }
  return 0;
}