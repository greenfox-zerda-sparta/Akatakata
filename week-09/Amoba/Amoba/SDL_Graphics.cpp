#include <iostream>
#include "SDL_Graphics.h"
#include "GameBoard.h"

SDL_Graphics::SDL_Graphics() {
  initialize_SDL();
  initialize_TTF();
  window = create_window(785, 570);
  renderer = create_renderer();
  font_color = { 0, 0, 0 };
  bg_color = { 236, 227, 206 };
}

SDL_Graphics::~SDL_Graphics() {
  for (std::map<std::string, SDL_Texture*>::iterator it = sprites.begin(); it != sprites.end(); ++it) {
    SDL_DestroyTexture(it->second);
  }
  for (std::map<const char*, SDL_Texture*>::iterator it = text_textures.begin(); it != text_textures.end(); ++it) {
    SDL_DestroyTexture(it->second);
 }
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

void SDL_Graphics::create_text_texture(const char* text, int size) {
  TTF_Font* font = TTF_OpenFont("Arial.ttf", size);
  SDL_Surface* text_surface = TTF_RenderText_Shaded(font, text, font_color, bg_color);

  text_textures[text] = SDL_CreateTextureFromSurface(renderer, text_surface);
  SDL_FreeSurface(text_surface);

  TTF_CloseFont(font);

}

void SDL_Graphics::draw_text(const char* text, int x, int y) {
  SDL_Rect solidRect;
  SDL_QueryTexture(text_textures[text], NULL, NULL, &solidRect.w, &solidRect.h);
  solidRect.x = x;
  solidRect.y = y;
  SDL_RenderCopy(renderer, text_textures[text], NULL, &solidRect);
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
