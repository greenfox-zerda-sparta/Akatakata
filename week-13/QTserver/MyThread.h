// #pragma once
#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QDebug>

class MyThread : public QThread {
  Q_OBJECT
public:
  explicit MyThread(int ID, QObject* parent = 0);
  void run();
signals:
  void error(QTcpSocket::SocketError socketerror);

public slots :
  void readyRead();
  void disconnected();
private:
  QTcpSocket* socket;
  int socketDescriptor;

};

#endif