// #pragma once
#ifndef SDL_GRAPHICS_H
#define SDL_GRAPHICS_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <map>
#include <string>
#include <vector>

class SDL_Graphics {
protected:
  SDL_Window* window;
  SDL_Renderer* renderer;
private:
  std::vector<int> window_color;
  void initialize_SDL();
  void initialize_TTF();
  SDL_Window* create_window(unsigned int screen_width, unsigned int screen_height);
  SDL_Renderer* create_renderer();
  void set_window_bg(std::vector<int> color);
public:
  SDL_Graphics();
  ~SDL_Graphics();
};

#endif
