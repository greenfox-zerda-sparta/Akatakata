#include <iostream>
#include <string>

using namespace std;

int main() {
	int h1 = 350;
	int h2 = 200;
	// tell if the double of h2 is bigger than h1
	(h2 * 2 > h1) ? cout << "The double of " << h2 << " is bigger, than " << h1 << endl : cout << "The double of " << h2 << " is NOT bigger, than " << h1 << endl;
	return 0;
}
