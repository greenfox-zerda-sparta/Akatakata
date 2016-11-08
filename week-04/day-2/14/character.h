#include <iostream>
#include <string>

using namespace std;

#ifndef CHARACTER_H_
#define CHARACTER_H_

class Character {
  private:
    string name;
    int health;
    unsigned int att;
    unsigned int def;
    unsigned int start_health;
  public:
    Character(string name, int health, int att, int def);
    void attack(Character& target);
    int getHealth();
    int getStartHealth();
    void decreaseHealth(int number);
    int getAtt();
    int getDef();
    string getName();
    void fight(Character& player1, Character& player2);
    void setHealth(int number);


};



#endif /* CHARACTER_H_ */
