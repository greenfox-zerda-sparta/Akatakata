#include "GameObject.h"

GameObject::GameObject() {
}


GameObject::~GameObject() {
}

void GameObject::init(GameContext& context) {
  context.load_file("img/floor.bmp"); // remove floor?
}

void GameObject::render(GameContext& context) {
  context.draw_sprite("img/floor.bmp", 0, 0); // remove floor ?
  context.render();
}