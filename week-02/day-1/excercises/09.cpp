#include <iostream>
#include <string>

using namespace std;

int main() {
	long long int i = 1357988018575474;
	// tell if it has 11 as a divisor
	(i%11 == 0) ? cout << "11 is a divisor of " << i << endl : cout << "11 is not a divisor of " << i << endl;
	return 0;
}
