#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

void print(char array[], int length) {
  for (int i = 0; i < length; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

bool check_win(char arr[], char secret[], int length) {
  // to check if all letters have been found successfully
  bool check = false;
  int success = 0;
  for (int i = 0; i < length; i++) {
    if (secret[i] == arr[i]) {
      success++;
    }
  }
  if (success == length) {
    check = true;
  } else {
    check = false;
  }
  return check;
}

void gameplay(char arr[], char secret[], int length, int guess) {
  char input = ' ';
  print(secret, length);
  cout << "Give me a letter!" << endl;
  cin >> input;
  int occurence = 0;
  while (check_win(arr, secret, length) == false) {
    for (int i = 0; i < length; i++) {
      if (input == arr[i]) {
        secret[i] = arr[i];
        occurence += 1;
      }
    }
    if (occurence == 0) {
      guess -= 1;
      cout << "That is not in the word. You have " << guess << " more wrong guesses." << endl;
      if (guess == 0) {
        cout << "Out of guesses. Game over." << endl;
        exit(0);
      }
    }
    if (check_win(arr, secret, length) == true) {
      print(secret, length);
      cout << "You win!" << endl;
      break;
    }
    gameplay(arr, secret, length, guess);
  }
}

void hangman(string text, int guess) {
  // Starts the game: can be played with any word, any length.
  // Could be done without arrays.
  int size = text.size();
  char original[size] = {};
  char coded[size] = {};
  for (int i = 0; i < size; i++) {
    original[i] = text[i];
  }
  for (int i = 0; i < size; i++) {
    coded[i] = '_';
  }
  cout << "Let's play hangman! You can guess wrong 5 times." << endl;
  gameplay(original, coded, size, guess);
  cout << "Thanks for playing! Bye!" << endl;
}

int main() {
  // Create a program that playes hangman
  // It should have a hardcoded word.
  // The user should be able to guess wrong five times
  // It should request for letters like:
  // Give me a letter:
  //
  // If the word contains the letter:
  //
  // As an answer it should print the word in its current form like:
  // _PP_E
  // Remaining wrong guesses: 5
  //
  // If don't contains:
  //
  // It should reduce the remaing wrong guesses by one, and print the error:
  //
  // Wrong guess
  // Remaining wrong guesses 4
  //
  // If the user ran out of guesses, it should display: Game over! :(
  //
  // If the user figured out all the letters in the word it should display: You Win! :)
  //
  string word = "greenfox";
  int wrong_guess = 5;
  hangman(word, wrong_guess);


  return 0;
}
