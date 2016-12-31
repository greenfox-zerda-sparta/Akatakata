#include <iostream>
#include "SDL_Graphics.h"
#include "GameBoard.h"

#define W_WIDTH 785
#define W_HEIGHT 570

SDL_Graphics::SDL_Graphics() {
  initialize_SDL();
  initialize_TTF();
  window = create_window(W_WIDTH, W_HEIGHT);
  renderer = create_renderer();
  window_color = { 236, 227, 206, 0 };
  set_window_bg(window_color);
}

SDL_Graphics::~SDL_Graphics() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  TTF_Quit();
  SDL_Quit();
}

void SDL_Graphics::initialize_SDL() {
  SDL_Init(SDL_INIT_EVERYTHING);
  std::cout << "init" << std::endl;
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
    std::cerr << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
  }
}

void SDL_Graphics::initialize_TTF() {
  TTF_Init();
  if (TTF_Init() == -1) {
    std::cerr << "Failed to initialize TTF : " << SDL_GetError() << std::endl;
  }
}

SDL_Window* SDL_Graphics::create_window(unsigned int screen_width, unsigned int screen_height) {
  SDL_Window* win = SDL_CreateWindow("Amoba",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, 0);
  if (win == nullptr) {
    std::cerr << "Failed to create window : " << SDL_GetError();
  }
  return win;
}

SDL_Renderer* SDL_Graphics::create_renderer() {
  SDL_Renderer* rend = SDL_CreateRenderer(window, -1, 0);
  if (rend == nullptr) {
    std::cerr << "Failed to create renderer : " << SDL_GetError();
  }
  return rend;
}

void SDL_Graphics::set_window_bg(std::vector<int> color) {
  SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], color[3]);
  SDL_RenderClear(renderer);
}