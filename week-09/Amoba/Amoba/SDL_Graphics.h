// #pragma once
#ifndef SDL_GRAPHICS_H
#define SDL_GRAPHICS_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <map>
#include <string>

class SDL_Graphics {
private:
  SDL_Window* window;
  SDL_Renderer* renderer;
  std::map<std::string, SDL_Texture*> sprite_textures;
  std::map<const char*, SDL_Texture*> text_textures;
  SDL_Color font_color;
  SDL_Color bg_color;
  int tile_size;
public:
  SDL_Graphics();
  ~SDL_Graphics();
  void initialize_SDL();
  void initialize_TTF();
  SDL_Window* create_window(unsigned int screen_width, unsigned int screen_height);
  SDL_Renderer* create_renderer();
  void SDL_Graphics::create_sprite_from_file(std::string name);
  void render_sprite(std::string name, int x, int y);
  void create_text_texture(const char* string, int size);
  void render_text(const char* text, int x, int y);
  void render();
  void clear();
};

#endif
