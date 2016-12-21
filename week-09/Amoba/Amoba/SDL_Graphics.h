// #pragma once
#ifndef SDL_GRAPHICS_H
#define SDL_GRAPHICS_H

#include <SDL.h>

class SDL_Graphics {
private:
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Event event;
  bool quit;
public:
  SDL_Graphics();
  ~SDL_Graphics();
  void initalize_SDL();
  SDL_Window* create_window();
  SDL_Renderer* create_renderer();
  void update_screen();
  void run_loop();
};

#endif
