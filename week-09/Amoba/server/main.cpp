// Created from: Re-written simple SDL_net socket server example | Nov 2011 | r3dux

#include <iostream>
#include <string>
#include "SDL_net.h"
#include "ServerSocket.h"

int main(int argc, char *argv[]) {
  int FirstTablePlayer = 0;
  int SecondTablePlayer = 2;
  if (SDLNet_Init() == -1) {
    std::cerr << "Failed to intialise SDL_net: " << SDLNet_GetError() << std::endl;
    exit(-1);
  }

  ServerSocket *server;
  try {
    server = new ServerSocket(1234, 512, 15);
  } catch (SocketException e) {
    std::cerr << "Error in creating server socket: " << e.what() << std::endl;
    std::cerr << "Terminating application." << std::endl;
    exit(-1);
  }
  
  try {
    int activeClient = -1;    // Which client is active, -1 means "no client is active"
    do {
      server->checkForConnections();
      do {
        activeClient = server->checkForActivity();     
          if (activeClient != -1) {
            if (FirstTablePlayer == activeClient) {
              server->dealWithActivity(activeClient);
              FirstTablePlayer == 0 ? FirstTablePlayer = 1 : FirstTablePlayer = 0;
            } else if (SecondTablePlayer == activeClient) {
              server->dealWithActivity(activeClient);
              SecondTablePlayer == 2 ? SecondTablePlayer = 3 : SecondTablePlayer = 2;
            }
        }             
      } while (activeClient != -1);             
    } while (server->getShutdownStatus() == false);
  } catch (SocketException e) {
    cerr << "Caught an exception in the main loop..." << e.what() << endl;
    cerr << "Terminating application." << endl;
  }

  SDLNet_Quit();
  return 0;
}
