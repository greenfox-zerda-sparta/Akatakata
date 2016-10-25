#include <iostream>
#include <string>

using namespace std;

int main() {
	int e[] = {1, 2, 3, 4, 5};
	// increment the 3rd element, than print all the elements of the array
	e[2]++;
	int length = sizeof(e)/sizeof(int);
	for (int i = 0; i <= length-1; i++) {
		cout << e[i] << " ";
	}
  return 0;
}
