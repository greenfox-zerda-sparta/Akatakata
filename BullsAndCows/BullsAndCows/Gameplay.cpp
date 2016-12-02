#include <iostream>
#include "Gameplay.h"

Gameplay::Gameplay() : bulls(0), cows(0), round(1) {
  MainMessage start;
  std::cout << start.get_welcome_text();
  std::cout << start.get_rules_text();
}

Gameplay::~Gameplay() {
}

void Gameplay::start_game() {
  SecretCode code;
  gameflow(code);
}

void Gameplay::reset_bulls() {
  bulls = 0;
}
void Gameplay::reset_cows() {
  cows = 0;
}
void Gameplay::reset_round() {
  round = 1;
}

void Gameplay::evaluate_guess_for_bulls(SecretCode hidden, GuessCode guess) {
  reset_bulls();
  for (unsigned int i = 0; i < hidden.get_code_length(); i++) {
    if (guess.get_guess_code()[i] == hidden.get_hidden_code()[i]) {
      bulls++;
    }
  }
  std::cout << "Bulls: " << bulls << std::endl;
}

void Gameplay::evaluate_guess_for_cows(SecretCode hidden, GuessCode guess) {
  reset_cows();
  for (unsigned int i = 0; i < hidden.get_code_length(); i++) {
    if (hidden.get_hidden_code().find(guess.get_guess_code()[i]) < hidden.get_code_length() 
        && guess.get_guess_code()[i] != hidden.get_hidden_code()[i]) {
      cows++;
    }
  }
  std::cout << "Cows: " << cows << std::endl;
}

bool Gameplay::is_winner() {
  return bulls == 4;
}

void Gameplay::play_one_round(SecretCode hidden) {
  std::string user_input = "";
  std::cout << "\nRound " << round << ". Enter your guess: ";
  std::cin >> user_input;
  GuessCode guess(user_input);
  evaluate_guess_for_cows(hidden, guess);
  evaluate_guess_for_bulls(hidden, guess);
  round++;
}

void Gameplay::end_game(SecretCode hidden) {
  if (is_winner()) {
    std::cout << "Congratulations! You have found the secret code:\n";
  } else {
    std::cout << "\nGame Over!\n";
    std::cout << "The code was:\n";
  }
  hidden.print_formatted_hidden_code();
}

void Gameplay::ask_for_new_game() {
  std::cout << "\nPress y if you want to play again!\n";
  char play_again;
  std::cin >> play_again;
  if (play_again == 'y' || play_again == 'Y') {
    start_game();
  } else {
    exit;
  }
}

void Gameplay::gameflow(SecretCode hidden) {
  while (!(is_winner()) && round <= 10) {
    play_one_round(hidden);
  }
  end_game(hidden);
  ask_for_new_game();
}