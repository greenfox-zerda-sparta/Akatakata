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
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  draw d(0, 0, 0);
  d.grid(renderer, 0, 0, line);
  // d.sierpinsky_triangle(renderer, 30, 50, 739);
  
  while (!quit) {
    SDL_WaitEvent(&event);
    switch (event.type) {
     case SDL_QUIT:
       quit = true;
       break;
     case SDL_KEYDOWN:
       if (event.key.keysym.sym == SDLK_ESCAPE) {
       quit = true;
       break;
       }
    }

    SDL_RenderPresent(renderer);
  }
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}