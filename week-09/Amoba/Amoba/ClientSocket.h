#ifndef SOCKET_H
#define SOCKET_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <conio.h> // Needed for kbhit and getch
#include "SDL_net.h"
#include "SocketException.h"

using std::string;
using std::cout;
using std::cerr;
using std::endl;

class ClientSocket {
	private:
		bool debug;
    unsigned int serverPort;
		unsigned int bufferSize;
		string serverHostname;
		IPaddress serverIP;
		string dotQuadString;
		TCPsocket serverSocket;
		TCPsocket clientSocket;
		char* pBuffer;
		string userInput;
		int inputLength;
		SDLNet_SocketSet socketSet;
		bool shutdownClient;
    string user_name;
	public:
		static const string SERVER_NOT_FULL;
		static const string SERVER_FULL;
		static const string SHUTDOWN_SIGNAL;
		static const string QUIT_SIGNAL;
		static const unsigned int CONNECTION_TIMEOUT_PERIOD;
		static const unsigned int SOCKET_SET_POLL_PERIOD;
		ClientSocket(string theServerAddress, unsigned int theServerPort, unsigned int theBufferSize);
		~ClientSocket();
		void connectToServer();
		string checkForIncomingMessages();
		void displayMessage(string &receivedCoords);
		void displayPrompt();
		void getUserInput(string user_input);
		string getCurrentUserInputContents();
		bool getShutdownStatus();
    string get_user_name();
};

template<class T>
std::string toString(const T& t) {
	std::ostringstream stream;
	stream << t;
	return stream.str();
}
#endif
