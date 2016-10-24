#include <iostream>
#include <string>

using namespace std;

int main() {
	int k = 1521;
	// tell if k is dividable by 3 or 5
	if (k % 3 == 0 || k % 5 == 0) {
		cout << k << " is dividable by 3 or 5." << endl;
	} else {
		cout << k << " is not dividable by 3 or 5." << endl;
	}
	return 0;
}
