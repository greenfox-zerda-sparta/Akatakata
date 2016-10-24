#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
	int j1 = 10;
	int j2 = 3;
	// tell if j1 is higher than j2 squared and smaller than j2 cubed

	if (j1 > pow(j2, 2) && j1 < pow(j2, 3)) {
		cout << j1 << " is higher than " << j2 << " squared and smaller than " << j2 << " cubed." << endl;
	} else {
		cout << j1 << " is NOT higher than " << j2 << " squared and smaller than " << j2 << " cubed." << endl;
	}
	return 0;
}
