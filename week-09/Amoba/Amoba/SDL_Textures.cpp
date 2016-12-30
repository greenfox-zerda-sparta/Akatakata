#include "SDL_Textures.h"

SDL_Textures::SDL_Textures() {
  font_color = { 0, 0, 0 };
  bg_color = { 236, 227, 206 };
  tile_size = 30;
}

SDL_Textures::~SDL_Textures() {
  for (std::map<std::string, SDL_Texture*>::iterator it = sprite_textures.begin(); it != sprite_textures.end(); ++it) {
    SDL_DestroyTexture(it->second);
  }
  for (std::map<const char*, SDL_Texture*>::iterator it = text_textures.begin(); it != text_textures.end(); ++it) {
    SDL_DestroyTexture(it->second);
  }
}

void SDL_Textures::render() {
  SDL_RenderPresent(renderer);
}

void SDL_Textures::make_textures() {
  create_sprite_from_file("img/panel_beigeLight.bmp");
  create_sprite_from_file("img/circle.bmp");
  create_sprite_from_file("img/ex.bmp");
  create_text_texture("Current player: ", 18);
  create_text_texture("WINS", 20);
  create_text_texture("Press R to play again.", 18);
  create_text_texture("Press ESC to quit.", 18);
}

void SDL_Textures::create_sprite_from_file(std::string name) {
  SDL_Surface* result = SDL_LoadBMP(name.c_str());
  sprite_textures[name] = SDL_CreateTextureFromSurface(renderer, result);
  SDL_FreeSurface(result);
}

void SDL_Textures::render_sprite(std::string name, int x, int y) {
  SDL_Rect temp;
  temp.x = x;
  temp.y = y;
  temp.w = tile_size;
  temp.h = tile_size;
  SDL_RenderCopy(renderer, sprite_textures[name], NULL, &temp);
}

void SDL_Textures::create_text_texture(const char* text, int size) {
  TTF_Font* font = TTF_OpenFont("Arial.ttf", size);
  SDL_Surface* text_surface = TTF_RenderText_Shaded(font, text, font_color, bg_color);
  text_textures[text] = SDL_CreateTextureFromSurface(renderer, text_surface);
  SDL_FreeSurface(text_surface);
  TTF_CloseFont(font);
}

void SDL_Textures::render_text(const char* text, int x, int y) {
  SDL_Rect solidRect;
  SDL_QueryTexture(text_textures[text], NULL, NULL, &solidRect.w, &solidRect.h);
  solidRect.x = x;
  solidRect.y = y;
  SDL_RenderCopy(renderer, text_textures[text], NULL, &solidRect);
}

int SDL_Textures::get_tile_size() {
  return tile_size;
}