#include <iostream>
#include "MyTcpServer.h"

MyTcpServer::MyTcpServer(QObject *parent) :
  QTcpServer(parent) {
}

void MyTcpServer::StartServer() {
  if (!this->listen(QHostAddress::Any, 1234)) {
    qDebug() << "Could not start server";
  } else {
    qDebug() << "Listening.";
  }
}

void MyTcpServer::incomingConnection(qintptr socketDescriptor) {
  qDebug() << socketDescriptor << " Connecting.";
  MyThread* thread = new MyThread(socketDescriptor, this);
  connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
  thread->start();
}
