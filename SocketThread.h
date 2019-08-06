//
// Created by rocke on 2019/8/6.
//

#ifndef QMULTITHREADEDTCPSERVER_SOCKETTHREAD_H
#define QMULTITHREADEDTCPSERVER_SOCKETTHREAD_H

#include <QThread>
#include <QTcpSocket>

class SocketThread : public QThread{
    Q_OBJECT
    qintptr _socketDescriptor;
    QTcpSocket* _socket = nullptr;


public:
   explicit SocketThread(qintptr socketId, QObject* parent = nullptr);
    void run() final;

public slots:
    void readyRead();
    void socketDisconnected();

};


#endif //QMULTITHREADEDTCPSERVER_SOCKETTHREAD_H
