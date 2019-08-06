//
// Created by rocke on 2019/8/6.
//

#include "SocketThread.h"
#include <QDebug>
SocketThread::SocketThread(qintptr socketId, QObject *parent)
:_socketDescriptor{socketId}, QThread{parent}
{

}

void SocketThread::run() {
    qDebug() << "Starting thread...";
    _socket = new QTcpSocket;

    // Bind socket id from operating system to a QAbstractSocket object
    if (!_socket->setSocketDescriptor(_socketDescriptor)) {
        // When the socket id is invalid
        qDebug() << _socket->errorString();
        return;
    }

    // NOTE: using direct connection should fix bugs
    // because both `readyRead` and `socketDisconnected` are going to executed on threads that don't run an event loop
    // reference: https://stackoverflow.com/questions/15051553/qt-signals-queuedconnection-and-directconnection
    connect(_socket, SIGNAL(readyRead()), this, SLOT(socketReadyRead()), Qt::DirectConnection);
    connect(_socket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()), Qt::DirectConnection);

    qDebug() << _socketDescriptor << "Client connected.";

    exec();
}

void SocketThread::socketReadyRead() {
    // receive data
    QByteArray data = _socket->readAll();
    qDebug() << _socketDescriptor << "Data in:" << data;

    // respond to client
    _socket->write(data);
}

void SocketThread::socketDisconnected() {
    qDebug() << _socketDescriptor << "Client disconnected.";

    _socket->deleteLater();
    exit(0);
}