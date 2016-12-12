#include <ctime>
#include "game-engine2.h"
#include "MyGame.h"

int main(int argc, char* argv[]) {
  std::srand(std::time(0));
  MyGame game;
  GameEngine engine(&game, 960, 720);
  engine.run();
  return 0;
}
