#define _CRT_SECURE_NO_WARNINGS
#include "ClientSocket.h"

const std::string  ClientSocket::SERVER_NOT_FULL = "OK";
const std::string  ClientSocket::SERVER_FULL = "FULL";
const std::string  ClientSocket::SHUTDOWN_SIGNAL = "/shutdown";
const std::string  ClientSocket::QUIT_SIGNAL = "/quit";
const unsigned int ClientSocket::CONNECTION_TIMEOUT_PERIOD = 5000;
const unsigned int ClientSocket::SOCKET_SET_POLL_PERIOD = 10;

ClientSocket::ClientSocket(string theServerAddress, unsigned int theServerPort, unsigned int theBufferSize) {
	debug = false;
	shutdownClient = false;
	serverHostname = theServerAddress;
	serverPort = theServerPort;
	bufferSize = theBufferSize;
	inputLength = 0;
  user_name = "";
	try	{
		pBuffer = new char[bufferSize];
		socketSet = SDLNet_AllocSocketSet(2);
		if (socketSet == NULL) {
			string msg = "Failed to allocate the socket set in ClientSocket constructor: ";
			msg += SDLNet_GetError();
			SocketException e(msg);
			throw e;
		}
	}
	catch (SocketException e)	{
		throw e;
	}
}

ClientSocket::~ClientSocket() {
	SDLNet_TCP_Close(serverSocket);
	SDLNet_TCP_Close(clientSocket);
	SDLNet_FreeSocketSet(socketSet);
	delete pBuffer;
}

void ClientSocket::connectToServer() {
//  cout << "User name: " << endl;
//  std::cin >> user_name;
//  cout << user_name;
	int hostResolved = SDLNet_ResolveHost(&serverIP, serverHostname.c_str(), serverPort);
	if (hostResolved == -1) {
		string msg = "Error: Failed to resolve the server hostname to an IP address.";
		SocketException e(msg);
		throw e;
	} else {
		Uint8 * dotQuad = (Uint8*)&serverIP.host;
		dotQuadString  = toString( (unsigned short)dotQuad[0] );
		dotQuadString += ".";
		dotQuadString += toString( (unsigned short)dotQuad[1] );
		dotQuadString += ".";
		dotQuadString += toString( (unsigned short)dotQuad[2] );
		dotQuadString += ".";
		dotQuadString += toString( (unsigned short)dotQuad[3] );
		if (debug) {
			cout << "Successfully resolved server to IP: " << dotQuadString;
			cout << ", will use port " << SDLNet_Read16(&serverIP.port) << endl;
			const char *pHostname;
			if (!(pHostname = SDLNet_ResolveIP(&serverIP))) {
				cout << "Failed to resolve the server IP to hostname: " << SDLNet_GetError() << endl;
				cout << "Attempting to continue as we have a (technically) valid IP address..." << endl;
			} else {
				serverHostname = toString(pHostname);
				cout << "Successfully resolved IP to hostname: " << serverHostname << endl;
			}
		}
	}

	clientSocket = SDLNet_TCP_Open(&serverIP);
	if (!clientSocket) {
		string msg = "Error: Failed to open connection to server: ";
		msg += SDLNet_GetError();
		SocketException e(msg);
		throw e;
	} else {
		if (debug) { cout << "Connection okay, about to read connection status from the server..." << endl; }
		SDLNet_TCP_AddSocket(socketSet, clientSocket);
		int activeSockets = SDLNet_CheckSockets(socketSet, ClientSocket::CONNECTION_TIMEOUT_PERIOD);
		if (debug) {
			cout << "There are " << activeSockets << " socket(s) with data on them at the moment." << endl;
		}
		int gotServerResponse = SDLNet_SocketReady(clientSocket);
		if (gotServerResponse != 0) {
			int serverResponseByteCount = SDLNet_TCP_Recv(clientSocket, pBuffer, bufferSize);
			if (debug) {
				cout << "Message from server: " << pBuffer << "(" << serverResponseByteCount << " bytes)" << endl;
			}
			string bufferContents = pBuffer;
			if ( pBuffer == ClientSocket::SERVER_NOT_FULL )	{
				if (debug) { cout << "Joining server now..." << endl; }
			} else {
				string msg = "Error: Server is full...";
				SocketException e(msg);
				throw e;
			}
		} else {
			string msg = "Error: No response from server: ";
			msg       += serverHostname;
			msg       += " at IP: ";
			msg       += dotQuadString;
			msg       += " on port ";
			msg       += serverIP.port;
			SocketException e(msg);
			throw e;
		}
	}
}

string ClientSocket::checkForIncomingMessages() {
	string receivedCoords = "";
	int activeSockets = SDLNet_CheckSockets(socketSet, ClientSocket::SOCKET_SET_POLL_PERIOD);
	if (activeSockets != 0) 	{
		int gotMessage = SDLNet_SocketReady(clientSocket); // Check if we got a message from the server
		if (gotMessage != 0) {
			int serverResponseByteCount = SDLNet_TCP_Recv(clientSocket, pBuffer, bufferSize);
			if (debug) {
				cout << endl << "Got message: " << pBuffer << " (" << serverResponseByteCount << " bytes)" << endl;
			}
			if (serverResponseByteCount != 0) {
				receivedCoords = toString(pBuffer);
				if (receivedCoords == ClientSocket::SHUTDOWN_SIGNAL) {
					if (debug) { cout << "Setting shutdownClient to true" << endl; }
					shutdownClient = true;
				}
			} else {
				string msg = "Lost connection to the server!";
				SocketException e(msg);
				throw e;
			}
    } 
	}
	return receivedCoords;
}

void ClientSocket::displayMessage(string& receivedCoords) {
	cout << endl << "Received: " << receivedCoords << endl;
	receivedCoords = "";
}

void ClientSocket::displayPrompt() {
	cout << "Write something >>> " << getCurrentUserInputContents();
	fflush(stdout);
}

void ClientSocket::getUserInput(string user_input) {
	strcpy( pBuffer, user_input.c_str() );
	inputLength = strlen(pBuffer) + 1;
	if (user_input != ClientSocket::QUIT_SIGNAL) {
		if (SDLNet_TCP_Send(clientSocket, (void *)pBuffer, inputLength) < inputLength) {
			string msg  = "Error: Failed to send message: ";
			       msg += SDLNet_GetError();
			SocketException e(msg);
			throw e;
		}
	} 
}

string ClientSocket::getCurrentUserInputContents() {
	return userInput;
}

bool ClientSocket::getShutdownStatus() {
	return shutdownClient;
}

string ClientSocket::get_user_name() {
  return user_name;
}
