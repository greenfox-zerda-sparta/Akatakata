#include <iostream>
#include "SDL_Graphics.h"
#include "GameBoard.h"

SDL_Graphics::SDL_Graphics() {
  initialize_SDL();
  initialize_TTF();
  window = create_window(785, 570);
  renderer = create_renderer();
 // font_color = { 0, 0, 0 };
 // bg_color = { 236, 227, 206 };
 // tile_size = 30;
}

SDL_Graphics::~SDL_Graphics() {
/*  for (std::map<std::string, SDL_Texture*>::iterator it = sprite_textures.begin(); it != sprite_textures.end(); ++it) {
    SDL_DestroyTexture(it->second);
  }
  for (std::map<const char*, SDL_Texture*>::iterator it = text_textures.begin(); it != text_textures.end(); ++it) {
    SDL_DestroyTexture(it->second);
 }*/
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  TTF_Quit();
  SDL_Quit();
}

void SDL_Graphics::initialize_SDL() {
  SDL_Init(SDL_INIT_EVERYTHING);
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
  SDL_SetRenderDrawColor(rend, 236, 227, 206, 0); 
  SDL_RenderClear(rend);
  return rend;
}

void SDL_Graphics::clear() {
  SDL_RenderClear(renderer);
}