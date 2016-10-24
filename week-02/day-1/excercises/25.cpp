#include <iostream>
#include <string>

using namespace std;

int main() {
	// print the even numbers till 20
	int i = 0;
	while (i <= 20) {
		i++;
		if (i % 2 == 0) {
			cout << i << endl;
		}
	}
	return 0;
}
