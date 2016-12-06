// #pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "MyGame.h"

class GameObject : public MyGame {
public:
  GameObject();
  ~GameObject();
  virtual void init(GameContext& context);
  virtual void render(GameContext& context);
};

#endif