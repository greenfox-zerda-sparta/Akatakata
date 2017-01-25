//#pragma once
#ifndef CHAT_SERVER_H
#define CHAT_SERVER_H
#include <QStringList>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>
#include <QSet>

class ChatServer : public QTcpServer {
  Q_OBJECT

public:
  ChatServer(QObject *parent = 0);
  void StartServer();

  private slots:
  void readyRead();
  void disconnected();
  void PrintUserList();

protected:
  void incomingConnection(qintptr SocketDescriptor);

private:
  QSet<QTcpSocket*> clients;
  QMap<QTcpSocket*, QString> users;
  int ID;
};

#endif