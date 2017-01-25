#include <QtCore/QCoreApplication>
#include "ChatServer.h"

int main(int argc, char **argv) {
  QCoreApplication app(argc, argv);

  ChatServer server;
  server.StartServer();

  return app.exec();
}
// ha elkezd irni egy kliens, akkor addig nem fogad