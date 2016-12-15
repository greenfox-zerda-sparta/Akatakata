#include <iostream>
#include <SDL.h>
#include "draw.h"

int main(int argc, char ** argv) {
  int line = 40;
  bool quit = false;
  SDL_Event event;

  SDL_Init(SDL_INIT_EVERYTHING); 

  SDL_Window* window = SDL_CreateWindow("SDL2 Fractal",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800, 0);

  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

  while (!quit) {

    SDL_WaitEvent(&event);

    switch (event.type) {
    case SDL_QUIT:
      quit = true;
      break;
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    draw d(380, 0, 0);
    for (int i = 0; i < 4; i++) {
      d.DrawBy(renderer, line);
      d.TurnBy(90);
    }
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}