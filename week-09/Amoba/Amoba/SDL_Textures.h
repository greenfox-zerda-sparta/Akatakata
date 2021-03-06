//#pragma once
#ifndef SDL_TEXTURES_H
#define SDL_TEXTURES_H
#include "SDL_Graphics.h"

#define TILE_SIZE 30

class SDL_Textures : public SDL_Graphics {
private:
  std::map<std::string, SDL_Texture*> sprite_textures;
  std::map<const char*, SDL_Texture*> text_textures;
  SDL_Color font_color;
  SDL_Color bg_color;
  const char* basic_font;
  int info_font_size;
  int winner_font_size;
public:
  SDL_Textures();
  ~SDL_Textures();
  void render();
  void make_textures();
  void create_sprite_from_file(std::string name, std::string filename);
  void render_sprite(std::string name, int x, int y, int w, int h);
  void create_text_texture(const char* name, const char* text, int size, const char* font_type);
  void render_text(const char* name, int x, int y);
  void render_text_button(const char* name, int x, int y, int w, int h);
};
#endif
