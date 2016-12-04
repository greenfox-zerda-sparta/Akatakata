#include <iostream>
#include "Gameplay.h"
#include "Round.h"

Gameplay::Gameplay() : round_counter(1), is_winner(0) {
  MainMessage start;
  std::cout << start.get_welcome_text();
  std::cout << start.get_rules_text();
}

Gameplay::~Gameplay() {
}

void Gameplay::start_game() {
  reset_round_counter();
  set_is_winner(0);
  SecretCode code;
  gameflow(code);
}

void Gameplay::gameflow(SecretCode hidden) {
  while (is_winner == 0 && round_counter <= 10) {
    Round gameround(round_counter, hidden);
    if (check_winner(hidden, gameround.get_bulls())) {
      set_is_winner(1);
    }
    round_counter++;
  }
  end_game(hidden);
  ask_for_new_game();
}

bool Gameplay::check_winner(SecretCode hidden, unsigned int guessed_bulls) {
  return guessed_bulls == hidden.get_code_length();
}

void Gameplay::set_is_winner(bool win_or_not) {
  is_winner = win_or_not;
}

void Gameplay::end_game(SecretCode hidden) {
  if (is_winner == 1) {
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
  }
}

void Gameplay::reset_round_counter() {
  round_counter = 1;
}
