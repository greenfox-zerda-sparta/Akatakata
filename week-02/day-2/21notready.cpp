#include <iostream>
#include <string>
using namespace std;

void alphabetSlicer(char beginner, char array[6]);

//Implement the above declared function to return the next 5 characters in the english alphabet
//after the character 'beginner' in an array of characters.
//The last chracter of the array should be '\0'.
//If there are less then 5 characters left after 'beginner' start from the beginning.
//So, alphabetSlicer(y) should return {'z','a','b','c','d','\0'}

int main(int argc, char** argv){

	string alphabet = "abcdefghijklmnopqrstuwxyz";
	string alpha[] = {};
	for (int i = 0; i < alphabet.length(); i++) {
		alpha[i] = alphabet[i];
	}
	cout << alpha
	char arr[6];
	alphabetSlicer('d', arr);
	cout << arr << endl;
	alphabetSlicer('w', arr);
	cout << arr << endl;

	return 0;
}
/*
void alphabetSlicer(char a, char arr[6]) {
	char arr[6] = {};
	arr[5] = '\0';
	for (int i = 0; i < alphabet.length(); i++) {
		if (alpha[i] == a) {
			for (int counter = 0; counter < 5; counter++) {
				arr[counter] = alpha[i + counter];
			}
		}
	}
}
