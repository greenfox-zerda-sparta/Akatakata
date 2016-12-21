// #pragma once
#ifndef SDL_GRAPHICS_H
#define SDL_GRAPHICS_H

#include <SDL.h>
#include <map>
#include <string>

class SDL_Graphics {
private:
  SDL_Window* window;
  SDL_Renderer* renderer;
  std::map<std::string, SDL_Texture*> sprites;
public:
  SDL_Graphics();
  ~SDL_Graphics();
  void initalize_SDL();
  SDL_Window* create_window(unsigned int screen_width, unsigned int screen_height);
  SDL_Renderer* create_renderer();
  void SDL_Graphics::load_file(std::string name);
  void draw_sprite(std::string name, int x, int y);
  void render();
 // SDL_Texture* create_texture(const std::string& str);

};

#endif
