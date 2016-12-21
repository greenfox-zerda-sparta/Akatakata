#include "SDL_Graphics.h"
#include <SDL.h>

int main(int argc, char *argv[]) {
  SDL_Graphics game_environment;

 /* SDL_Event event;

  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_Window* window = SDL_CreateWindow("Amoba",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800, 0);

  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
  while (!quit) {
    SDL_WaitEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
      quit = true;
      break;
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym) {
      case SDLK_ESCAPE:
        quit = true;
        break;
      }
    }
    SDL_RenderPresent(renderer);
  }
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();*/
  return 0;
}