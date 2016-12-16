#include <iostream>
#include <SDL.h>
#include "draw.h"

int main(int argc, char ** argv) {
  int line = 799;
  bool quit = false;
  SDL_Event event;

  SDL_Init(SDL_INIT_EVERYTHING); 

  SDL_Window* window = SDL_CreateWindow("SDL2 Fractal",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800, 0);

  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_SetRenderDrawColor(renderer, 19, 19, 70, 0);
  SDL_RenderClear(renderer);
  
  while (!quit) {
    SDL_WaitEvent(&event);
    if (event.type == SDL_QUIT) {
      quit = true;
      break;
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    draw d(0, 0, 0);
    d.grid(renderer, 0, 0, line);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}