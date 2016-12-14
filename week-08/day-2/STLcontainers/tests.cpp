#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // accumulate

using namespace std;

void print(int a) {
  cout << a << " ";
}

int main() {
  vector<int> v;
  v.push_back(4);
  v.push_back(2);
  v.push_back(6);
  v.push_back(8);
  v.push_back(1);

  cout << accumulate(v.begin(), v.end(), 0) << endl;
  sort(v.begin(), v.end());
  for_each(v.begin(), v.end(), print);
  cout << endl;
  for_each(v.begin(), v.end(), [](int a) {cout << a << " ";}); // lambda: csak 1* hasznalatos, c++11
  cout << endl;

  return 0;
}