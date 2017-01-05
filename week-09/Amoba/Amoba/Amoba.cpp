#include <iostream>
#include <string>
#include <SDL_net.h>
#include "Amoba.h"

Amoba::Amoba() {
  if (SDLNet_Init() == -1) {
    cerr << "Failed to intialise SDL_net: " << SDLNet_GetError() << endl;
    exit(-1);
  }
  cs = new ClientSocket("10.27.99.171"; , 1234, 512);
  cs->connectToServer();
  game = new GamePlay();
  textures = new SDL_Textures;
  textures->make_textures();
  SDL_Event event;
  quit = false;
}

Amoba::~Amoba() {
  SDLNet_Quit();
  delete game;
  delete textures;
}

void Amoba::make_new_game() {
  delete game;
  delete textures;
  game = new GamePlay();
  textures = new SDL_Textures;
  textures->make_textures();
}

bool Amoba::is_click_on_board(int x, int y) {
  int board_edge = BOARD_SIZE * TILE_SIZE;
  return (x < board_edge && y < board_edge);
}

void Amoba::run() {
  while (!quit) {
 // Suvi chatjehez
 //   string user_input;
 //   std::getline(std::cin, user_input);
 //   cs->getUserInput(user_input);

    string receivedCoords = "";
    receivedCoords = cs->checkForIncomingMessages();
    if (receivedCoords.length() > 0) {
      string got_x = "";
      string got_y = "";
      string temp = "";
      for (unsigned int i = 0; i < receivedCoords.length(); i++) {
        if (receivedCoords[i] != ',') {
          temp += receivedCoords[i];
        }
        if (receivedCoords[i] == ',') {
          got_x = temp;
          temp = "";
        }
      }
      got_y = temp;
      game->place_stone_on_board(*textures, stoi(got_x), stoi(got_y));
    }
    
    SDL_PollEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
      quit = true;
      break;
    case SDL_MOUSEBUTTONDOWN:
      if ((is_click_on_board(event.button.x, event.button.y)) && game->is_gameover() == 0) {
        int tile_x = event.button.x / TILE_SIZE;
        int tile_y = event.button.y / TILE_SIZE;
        if (game->is_tile_free(tile_x, tile_y)) {
          string user_input = std::to_string(tile_x) + "," + std::to_string(tile_y);
          cs->getUserInput(user_input);
          break;
        }
      } else if (game->is_gameover()) {
        int click_x = event.button.x;
        int click_y = event.button.y;
        if (630 < click_x && click_x < 740 && 200 < click_y && click_y < 240) {
          make_new_game();
          break;
        } else if (click_x > 655 && click_x < 715 && click_y > 260 && click_y < 300) {
          quit = true;
          break;
        }
      }
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym) {
      case SDLK_ESCAPE:
        quit = true;
        break;
      case SDLK_r:
        if (game->is_gameover()) {
          make_new_game();
          break;
        }
      }
    }
    game->render(*textures);
  }
}
