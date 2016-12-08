//#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
protected:
  int loc_x;
  int loc_y;
public:
  Character();
  ~Character();
  int get_loc_x();
  int get_loc_y();
};

#endif

