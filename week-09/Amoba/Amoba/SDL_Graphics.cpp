#include <iostream>
#include "SDL_Graphics.h"
#include "GameBoard.h"

SDL_Graphics::SDL_Graphics() {
  initalize_SDL();
  window = create_window(900, 570);
  renderer = create_renderer();
}

SDL_Graphics::~SDL_Graphics() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  for (std::map<std::string, SDL_Texture*>::iterator it = sprites.begin(); it != sprites.end(); ++it) {
    SDL_DestroyTexture(it->second);
  }
  SDL_Quit();
  std::cout << "renderer, window, textures destroyed" << std::endl;
}

void SDL_Graphics::initalize_SDL() {
  SDL_Init(SDL_INIT_EVERYTHING);
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
    std::cerr << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
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

void SDL_Graphics::load_file(std::string name) {
  SDL_Surface* result = SDL_LoadBMP(name.c_str());
  sprites[name] = SDL_CreateTextureFromSurface(renderer, result);
  SDL_FreeSurface(result);
}

void SDL_Graphics::draw_sprite(std::string name, int x, int y) {
  SDL_Rect temp;
  temp.x = x;
  temp.y = y;
  temp.w = 30;
  temp.h = 30;
  SDL_RenderCopy(renderer, sprites[name], NULL, &temp);
}
void SDL_Graphics::render() {
  SDL_RenderPresent(renderer);
}



/*

SDL_Texture* SDL_Graphics::create_texture(const std::string& str) {
  SDL_Surface* surface = SDL_LoadBMP(str.c_str());
  if (surface == nullptr) {
    std::cout << "Failed to load surface " << SDL_GetError() << std::endl;
    return nullptr;
  }
  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);
  return texture;
}

*/
