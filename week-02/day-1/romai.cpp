#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	//converts arabic number to roman
	int i = 0;
	cout << "Irj egy 4000 alatti szamot!" << endl;
	cin >> i;

	if (i < 4000) {
		vector<string> egyesek = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
		vector<string> tizesek = {"", "X", "XX", "XXX", "IL", "L", "LI", "LII", "LIII", "IX"};
		vector<string> szazasok = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
		vector<string> ezresek = {"", "M", "MM", "MMM"};

		cout << ezresek[i% 10000 / 1000] << szazasok[i % 1000 / 100] << tizesek[i % 100 / 10] << egyesek[i % 10];
	} else {
		cout << "Ez nem 4000 alatti szam, nem valtom at.";
	}
	return 0;
}


