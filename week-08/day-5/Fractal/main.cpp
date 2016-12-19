#include <iostream>
#include <SDL.h>
#include "draw.h"

SDL_Rect squares;
SDL_Rect triangles;



int main(int argc, char ** argv) {
  int line = 799;
  bool quit = false;
  SDL_Event event;

  SDL_Init(SDL_INIT_EVERYTHING); 

  SDL_Window* window = SDL_CreateWindow("SDL2 Fractals - press A for triangles, press S for squres",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800, 0);

  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_SetRenderDrawColor(renderer, 19, 19, 70, 0);
  SDL_RenderClear(renderer);

  SDL_Surface* surface = SDL_LoadBMP("squares.bmp");
  if (surface == nullptr) {
    std::cout << "Failed to load surface " << std::endl;
  }
  squares.x = 200;
  squares.y = 200;
  squares.w = 150;
  squares.h = 150;
  SDL_Texture* texture_squares = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);
 

  SDL_Surface* surface2 = SDL_LoadBMP("triangles.bmp");
  if (surface == nullptr) {
    std::cout << "Failed to load surface " << std::endl;
  }
  triangles.x = 500;
  triangles.y = 200;
  triangles.w = 150;
  triangles.h = 150;
  SDL_Texture* texture_triangles = SDL_CreateTextureFromSurface(renderer, surface2);
  SDL_FreeSurface(surface2);

  SDL_RenderCopy(renderer, texture_squares, NULL, &squares);
  SDL_RenderCopy(renderer, texture_triangles, NULL, &triangles);
  draw d(0, 0, 0);

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
         case SDLK_s:
           SDL_SetRenderDrawColor(renderer, 19, 19, 70, 0);
           SDL_RenderClear(renderer);
           SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
           d.grid(renderer, 0, 0, line);
           break;
         case SDLK_a:
           SDL_SetRenderDrawColor(renderer, 19, 19, 70, 0);
           SDL_RenderClear(renderer);
           SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
           d.sierpinsky_triangle(renderer, 10, 50, line - 20);
           break;
       }
    }
    SDL_RenderPresent(renderer);
  }
  SDL_DestroyTexture(texture_squares);
  SDL_DestroyTexture(texture_triangles);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}