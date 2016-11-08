#include <iostream>
#include <string>
#include "character.h"
#include <cstdlib>

using namespace std;

Character::Character(string name, int health, int att, int def) {
  this->name = name;
  this->health = health;
  this->att = att;
  this->def = def;
  start_health = health;
}

void Character::attack(Character& target) {
  int modifier = rand() % 100; // 50% chance for 2 x attack value
  int temp_att = att;
  if (modifier > 50) {
    temp_att *= 2;
  }
  int health_change = temp_att - target.def;
  if (health_change < 0) {
    health -= health_change;
  } else {
    target.decreaseHealth(health_change);
  }
  cout << name << " attacks " << target.getName() << " and hits for " << health_change << " damage." << endl;
  cout << name << " has " << health << " health points. " << target.getName() << " has " <<
      target.getHealth() << " health points." << endl << endl;
}

int Character::getHealth() {
  return health;
}

string Character::getName() {
  return name;
}

void Character::setHealth(int number) {
  health = number;
}

int Character::getStartHealth() {
  return start_health;
}

int Character::getAtt() {
  return att;
}

int Character::getDef() {
  return def;
}

void Character::decreaseHealth(int number) {
  health -= number;
}
void Character::fight(Character& player1, Character& player2) { // SHould not show negative health, only 0
  string winner = "";
  while (player1.getHealth() > 0 && player2.getHealth() > 0) {
    player1.attack(player2);
    if (player2.getHealth() > 0) {
      player2.attack(player1);
    } else {
      break;
    }
  }
  if (player2.getHealth() > 0) {
    cout << player2.getName() << " wins!" << endl;
  } else {
    cout << player1.getName() << " wins!" << endl;
  }
  cout << "Fight again? Press 'y'!" << endl;
  char input = ' ';
  cin >> input;
  if (input == 'y') {
    player1.setHealth(player1.getStartHealth());
    player2.setHealth(player2.getStartHealth());
    fight(player1, player2);
  } else {
    cout << "Bye!" << endl;
  }
}
