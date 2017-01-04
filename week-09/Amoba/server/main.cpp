// Created from: Re-written simple SDL_net socket server example | Nov 2011 | r3dux

#include <iostream>
#include <string>
#include "SDL_net.h"
#include "ServerSocket.h"

int main(int argc, char *argv[]) {
  int current_player = 0;
  if (SDLNet_Init() == -1) {
    std::cerr << "Failed to intialise SDL_net: " << SDLNet_GetError() << std::endl;
    exit(-1);
  }

  ServerSocket *ss;
  try {
    ss = new ServerSocket(1234, 512, 3);
  } catch (SocketException e) {
    std::cerr << "Error in creating server socket: " << e.what() << std::endl;
    std::cerr << "Terminating application." << std::endl;
    exit(-1);
  }

  try {
    int activeClient = -1;    // Which client is active, -1 means "no client is active"
    do {
      ss->checkForConnections();
      do {
        activeClient = ss->checkForActivity();     
        if (activeClient != -1 && current_player % 2 == activeClient) {               // If there's a client with unprocessed activity...
          ss->dealWithActivity(activeClient);   // ...then process that client!
          current_player++;
        }             
      } while (activeClient != -1);             // When there are no more clients with activity to process, continue...
    } while (ss->getShutdownStatus() == false);
  } catch (SocketException e) {
    cerr << "Caught an exception in the main loop..." << e.what() << endl;
    cerr << "Terminating application." << endl;
  }

  SDLNet_Quit();
  return 0;
}
