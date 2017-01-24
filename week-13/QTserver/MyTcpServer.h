//#pragma once
#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QTcpServer>
#include <QDebug>
#include "MyThread.h"

class MyTcpServer : public QTcpServer {
  Q_OBJECT
public:
  explicit MyTcpServer(QObject *parent = 0);
  void StartServer();

signals:
  
public slots :

protected:
  void incomingConnection(qintptr socketDescriptor);
};

#endif // MYTCPSERVER_H
