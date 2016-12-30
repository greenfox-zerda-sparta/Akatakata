//#pragma once
#ifndef SDL_TEXTURES_H
#define SDL_TEXTURES_H
#include "SDL_Graphics.h"

class SDL_Textures : public SDL_Graphics {
private:
  std::map<std::string, SDL_Texture*> sprite_textures;
  std::map<const char*, SDL_Texture*> text_textures;
  SDL_Color font_color;
  SDL_Color bg_color;
  int tile_size;
  const char* basic_font;
public:
  SDL_Textures();
  ~SDL_Textures();
  void render();
  void make_textures();
  void create_sprite_from_file(std::string name);
  void render_sprite(std::string name, int x, int y);
  void create_text_texture(const char* string, int size, const char* font_type);
  void render_text(const char* text, int x, int y);
  int get_tile_size();
};
#endif
