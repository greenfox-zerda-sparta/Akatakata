#include "MyThread.h"

MyThread::MyThread(int ID, QObject* parent) : QThread(parent) {
  this->socketDescriptor = ID;
}

void MyThread::run() {
  // thread starts here
  qDebug() << socketDescriptor << " Starting thread...";
  socket = new QTcpSocket();
  if (!socket->setSocketDescriptor(this->socketDescriptor)) {
    emit error(socket->error());
    return;
  }
  connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
  connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()), Qt::DirectConnection);
  qDebug() << socket << " Client connected.";
  
  exec(); // this creates the loop, very important
}

void MyThread::readyRead() {
  // echo server, sends info back
  QByteArray data = socket->readAll();
  qDebug() << socketDescriptor << " Data in: " << data;
  socket->write(data);
}

void MyThread::disconnected() {
  qDebug() << socketDescriptor << " Disconnected";
  socket->deleteLater();
  exit(0);
}
