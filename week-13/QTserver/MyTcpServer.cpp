#include <iostream>
#include "MyTcpServer.h"

MyTcpServer::MyTcpServer(QObject *parent) :
  QObject(parent) {
  server = new QTcpServer(this);
  connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));

  if (!server->listen(QHostAddress::Any, 1234)) {
    qDebug() << "Server could not start";
  } else {
    qDebug() << "Server started!";
  }
  
}

void MyTcpServer::newConnection() {
  QTcpSocket *socket = server->nextPendingConnection();
  std::cout << "Valai connectelt" << std::endl;

  socket->write("Hello client\r\n");
  socket->flush();

 // socket->close();
}
