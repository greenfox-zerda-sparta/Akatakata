#include "game-engine2.h"
#include "MyGame.h"

int main(int argc, char* argv[]) {
  MyGame game;
  GameEngine engine(&game, 720, 782);
  engine.run();
  return 0;
}