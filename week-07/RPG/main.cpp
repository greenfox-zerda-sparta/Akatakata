#include "game-engine2.h"

class MyGame : public Game {
public:
  MyGame() {}
  virtual void init(GameContext& context) {
    context.load_file("img/floor.bmp");
  }
  virtual void render(GameContext& context) {
    context.draw_sprite("img/floor.bmp", 0, 0);
    context.render();
  }
};

int main(int argc, char* argv[]) {
  MyGame game;
  GameEngine engine(&game, 400, 300);
  engine.run();
  return 0;
}