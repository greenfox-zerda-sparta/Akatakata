#define _CRT_SECURE_NO_WARNINGS
#include "ServerSocket.h"

const string ServerSocket::SERVER_NOT_FULL = "OK";
const string ServerSocket::SERVER_FULL     = "FULL";
const string ServerSocket::SHUTDOWN_SIGNAL = "/shutdown";

ServerSocket::ServerSocket(unsigned int thePort, unsigned int theBufferSize, unsigned int theMaxSockets) {
	debug = false;
	shutdownServer = false;
	port = thePort;
	bufferSize = theBufferSize;
	maxSockets = theMaxSockets;
	maxClients = theMaxSockets - 1;
	pClientSocket = new TCPsocket[maxClients]; 
	pSocketIsFree = new bool[maxClients];
	pBuffer = new char[bufferSize];
  logbuffer = "";
  std::ofstream logfile;
  logfilename = LocalTimer->GetTimeFileFormat() + ".txt";
  cout << logfilename << endl;
	clientCount = 0;
	socketSet = SDLNet_AllocSocketSet(maxSockets);

	if (socketSet == NULL) {
    string msg = "Failed to allocate the socket set: ";
		msg += SDLNet_GetError();
		SocketException e(msg);
		throw e;
	} else {
		logbuffer = LocalTimer->GetCurrentTime() + "Allocated socket set size: " + toString(maxSockets) + ", of which " + toString(maxClients) + " are free.";
    print_and_log();
	}

	for (unsigned int loop = 0; loop < maxClients; loop++) {
		pClientSocket[loop] = NULL;
		pSocketIsFree[loop] = true; // Set all our sockets to be free
	}

	int hostResolved = SDLNet_ResolveHost(&serverIP, NULL, port);
	if (hostResolved == -1) {
		string msg = "Failed to open the server socket: ";
		msg += SDLNet_GetError();
		SocketException e(msg);
		throw e;
	}
	serverSocket = SDLNet_TCP_Open(&serverIP);
	if (!serverSocket) {
		string msg = "Failed to open the server socket: ";
		msg += SDLNet_GetError();
		SocketException e(msg);
		throw e;
	}
	SDLNet_TCP_AddSocket(socketSet, serverSocket);

  LocalTimer = new Time();
}

ServerSocket::~ServerSocket() {
	for (unsigned int loop = 0; loop < maxClients; loop++) {
		if (pSocketIsFree[loop] == false) {
			SDLNet_TCP_Close(pClientSocket[loop]);
			pSocketIsFree[loop] = true;
		}
	}
	SDLNet_TCP_Close(serverSocket);
	SDLNet_FreeSocketSet(socketSet);
	delete pClientSocket;
	delete pSocketIsFree;
	delete pBuffer;
  delete LocalTimer;
}

void ServerSocket::checkForConnections() {
	int numActiveSockets = SDLNet_CheckSockets(socketSet, 10);
	if (numActiveSockets != 0) {
		if (debug) {
			cout << LocalTimer->GetCurrentTime() << "There are currently " << numActiveSockets << " socket(s) with data to be processed." << endl;
		}
	}
	int serverSocketActivity = SDLNet_SocketReady(serverSocket);
	if (serverSocketActivity != 0) {
		if (clientCount < maxClients) {
			// Find the first free socket in our array of client sockets
			int freeSpot = -99;
			for (unsigned int loop = 0; loop < maxClients; loop++) {
				if (pSocketIsFree[loop] == true) {
					pSocketIsFree[loop] = false;
					freeSpot = loop;
					break;
				}
			}
			pClientSocket[freeSpot] = SDLNet_TCP_Accept(serverSocket);
			SDLNet_TCP_AddSocket(socketSet, pClientSocket[freeSpot]);
			clientCount++;
			strcpy(pBuffer, SERVER_NOT_FULL.c_str()); // message to the client saying "OK" to indicate the incoming connection has been accepted
			int msgLength = strlen(pBuffer) + 1;
			SDLNet_TCP_Send(pClientSocket[freeSpot], (void *)pBuffer, msgLength);

      IPaddress* remote = SDLNet_TCP_GetPeerAddress(pClientSocket[freeSpot]);
      Uint8 bytevalue[4];
      for (int i = 0; i < 4; i++) {
        bytevalue[i] = remote->host >> (i * 8);
      }
      string clientIP = toString((int)bytevalue[0]) + "." + toString((int)bytevalue[1]) + "." +
        toString((int)bytevalue[2]) + "." + toString((int)bytevalue[3]);
      logbuffer = LocalTimer->GetCurrentTime() + "Client connected from : " + clientIP + ", port : " + toString(SDLNet_Read16(&remote->port)) +
        " There are now " + toString(clientCount) + " client(s) connected.";
      print_and_log();
 
		} else {
			logbuffer = LocalTimer->GetCurrentTime() + "Max client count reached - rejecting client connection" ;
      print_and_log();
			TCPsocket tempSock = SDLNet_TCP_Accept(serverSocket);
			strcpy( pBuffer, SERVER_FULL.c_str() );
			int msgLength = strlen(pBuffer) + 1;
			SDLNet_TCP_Send(tempSock, (void *)pBuffer, msgLength);
			SDLNet_TCP_Close(tempSock);
		}
	} 
} 

void ServerSocket::dealWithActivity(unsigned int clientNumber) {
  string bufferContents = pBuffer;
  if (debug) {
    cout << LocalTimer->GetCurrentTime() << "Received: >>>> " << bufferContents << " from client number: " << clientNumber << endl;
  	}   
  logbuffer = LocalTimer->GetCurrentTime() + "Client " + toString(clientNumber) + " placed on: " + toString(bufferContents);
  print_and_log();
  if (clientNumber == 0 || clientNumber == 1) {
    for (unsigned int loop = 0; loop < 2; loop++) {
      unsigned int msgLength = strlen(pBuffer) + 1;
      if ((msgLength > 1) && (pSocketIsFree[loop] == false)) {
        if (debug) {
          cout << LocalTimer->GetCurrentTime() << "Retransmitting: " << bufferContents << " (" << msgLength << " bytes) to client " << loop << endl;
        }
        SDLNet_TCP_Send(pClientSocket[loop], (void*)pBuffer, msgLength);
      }
    }
  }
  if (clientNumber == 2 || clientNumber == 3) {
    for (unsigned int i = 2; i < 4; i++) {
      unsigned int msgLength = strlen(pBuffer) + 1;
      if ((msgLength > 1) && (pSocketIsFree[i] == false)) {
        if (debug) {
          cout << LocalTimer->GetCurrentTime() << "Retransmitting: " << bufferContents << " (" << msgLength << " bytes) to client " << i << endl;
        }
        SDLNet_TCP_Send(pClientSocket[i], (void *)pBuffer, msgLength);
      }
    }
  }
  	if (bufferContents.compare(SHUTDOWN_SIGNAL) == 0)	{
  		shutdownServer = true;
  		if (debug) { cout << LocalTimer->GetCurrentTime() << "Disconnecting all clients and shutting down the server..." << endl; }
  	}
}

int ServerSocket::checkForActivity() {

	for (unsigned int clientNumber = 0; clientNumber < maxClients; clientNumber++)	{
		int clientSocketActivity = SDLNet_SocketReady(pClientSocket[clientNumber]);
		
    if (clientSocketActivity != 0) {
			int receivedByteCount = SDLNet_TCP_Recv(pClientSocket[clientNumber], pBuffer, bufferSize);
			if (receivedByteCount <= 0) {
				/*if (debug) { */
        logbuffer = LocalTimer->GetCurrentTime() + "Client " + toString(clientNumber) + " disconnected.";
        print_and_log();
				SDLNet_TCP_DelSocket(socketSet, pClientSocket[clientNumber]);
				SDLNet_TCP_Close(pClientSocket[clientNumber]);
				pClientSocket[clientNumber] = NULL;
				pSocketIsFree[clientNumber] = true;
				clientCount--;
				if (debug) { cout << LocalTimer->GetCurrentTime() << "Server is now connected to: " << clientCount << " client(s)." << endl; }

			} else {
        return clientNumber;
			}
		} 
	}
  return -1;
} 

bool ServerSocket::getShutdownStatus() {
	return shutdownServer;
}

void ServerSocket::log_buffer() {
  logfile.open(logfilename.c_str(), std::ios::app);
  logfile << logbuffer << endl;
  logfile.close();
}

void ServerSocket::print_and_log() {
  cout << logbuffer << endl;
  log_buffer();
}

