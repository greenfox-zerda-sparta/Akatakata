#include <iostream>
#include <string>

using namespace std;

int main() {
	int v = 426;
	// print 'Yeah!' if dividable by 4 but print 'End of program' after regardless
	if (v % 4 == 0) {
		cout << "Yeah!" << endl;
	}
	cout << "End of program";
	return 0;
}
