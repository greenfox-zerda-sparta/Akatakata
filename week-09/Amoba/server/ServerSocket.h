#ifndef SOCKET_H
#define SOCKET_H
#include <iostream>
#include <string>
#include <sstream>
#include "SDL_net.h"
#include "SocketException.h" 

using std::string;
using std::cout;
using std::cerr;
using std::endl;

class ServerSocket
{
	private:
		bool debug;                 // Flag to control whether the ServerSocket should display debug info
		unsigned int port;
		unsigned int bufferSize;
		unsigned int maxSockets;
		unsigned int maxClients;    // maxSockets - 1 as the server socket itself takes 1 port
    IPaddress serverIP;
		TCPsocket serverSocket;
		string    dotQuadString;    // The IP address of the server as a dot-quad string i.e. "127.0.0.1"
		TCPsocket *pClientSocket;
		bool *pSocketIsFree;
		char *pBuffer;
		SDLNet_SocketSet socketSet;
		unsigned int clientCount;
		bool shutdownServer;
	public:
		static const string SERVER_NOT_FULL;
		static const string SERVER_FULL;
		static const string SHUTDOWN_SIGNAL;
		ServerSocket(unsigned int port, unsigned int bufferSize, unsigned int maxSockets);
		~ServerSocket();
		void checkForConnections();
		int checkForActivity();     // -1 if no clients with activity to process
		void dealWithActivity(unsigned int clientNumber);
		bool getShutdownStatus();
};

// Template function to convert anything to a string
template<class T>
std::string toString(const T& t)
{
	std::ostringstream stream;
	stream << t;
	return stream.str();
}

#endif
