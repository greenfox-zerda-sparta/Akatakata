#include "SDL_Textures.h"

SDL_Textures::SDL_Textures() {
  font_color = { 0, 0, 0 };
  bg_color = { 236, 227, 206 };
  basic_font = "Arial.ttf";
  info_font_size = 18;
  winner_font_size = 20;
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
  create_sprite_from_file("tile", "img/panel_beigeLight.bmp");
  create_sprite_from_file("red stone", "img/circle.bmp");
  create_sprite_from_file("black stone", "img/ex.bmp");
  create_text_texture("show player", "Current player: ", info_font_size, basic_font);
  create_text_texture("yours", "You are: ", info_font_size, basic_font);
  create_text_texture("show winner", "WINS", winner_font_size, basic_font);
  create_text_texture("button play again", "Play again", info_font_size, basic_font);
  create_text_texture("button exit", "Exit", info_font_size, basic_font);
}

void SDL_Textures::create_sprite_from_file(std::string name, std::string filename) {
  SDL_Surface* result = SDL_LoadBMP(filename.c_str());
  sprite_textures[name] = SDL_CreateTextureFromSurface(renderer, result);
  SDL_FreeSurface(result);
}

void SDL_Textures::render_sprite(std::string name, int x, int y, int w, int h) {
  SDL_Rect temp;
  temp.x = x;
  temp.y = y;
  temp.w = w;
  temp.h = h;
  SDL_RenderCopy(renderer, sprite_textures[name], NULL, &temp);
}

void SDL_Textures::create_text_texture(const char* name, const char* text, int size, const char* font_type) {
  TTF_Font* font = TTF_OpenFont(font_type, size);
  SDL_Surface* text_surface = TTF_RenderText_Shaded(font, text, font_color, bg_color);
  text_textures[name] = SDL_CreateTextureFromSurface(renderer, text_surface);
  SDL_FreeSurface(text_surface);
  TTF_CloseFont(font);
}

void SDL_Textures::render_text(const char* name, int x, int y) {
  SDL_Rect solidRect;
  SDL_QueryTexture(text_textures[name], NULL, NULL, &solidRect.w, &solidRect.h);
  solidRect.x = x;
  solidRect.y = y;
  SDL_RenderCopy(renderer, text_textures[name], NULL, &solidRect);
}

void SDL_Textures::render_text_button(const char* name, int x, int y, int w, int h) {
  SDL_Rect Rect;
  Rect.w = w;
  Rect.h = h;
  SDL_QueryTexture(text_textures[name], NULL, NULL, &Rect.w, &Rect.h);
  Rect.x = x;
  Rect.y = y;
  SDL_RenderCopy(renderer, text_textures[name], NULL, &Rect);
}
