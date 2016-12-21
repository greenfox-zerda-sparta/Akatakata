#include <iostream>
#include "SDL_Graphics.h"

SDL_Graphics::SDL_Graphics() {
  quit = false;
  initalize_SDL();
  SDL_Event event;
  window = create_window();
  renderer = create_renderer();
  run_loop();
}

SDL_Graphics::~SDL_Graphics() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void SDL_Graphics::initalize_SDL() {
  SDL_Init(SDL_INIT_EVERYTHING);
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
    std::cerr << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
  }
}

SDL_Window* SDL_Graphics::create_window() {
  SDL_Window* win = SDL_CreateWindow("Amoba",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800, 0);
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

void SDL_Graphics::update_screen() {
  SDL_RenderPresent(renderer);
}

void SDL_Graphics::run_loop() {
  while (quit == false) {
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
}