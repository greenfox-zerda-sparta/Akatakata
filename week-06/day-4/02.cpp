#include <iostream>
#include <vector>

using namespace std;

int main() {
  //create an integer vector with the size of 5 and print all elements of it
  vector<int> v(5);
  v = { 1, 2, 3, 4, 5 }; // without this, it contains zeros
  for (unsigned int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;

  return 0;
}