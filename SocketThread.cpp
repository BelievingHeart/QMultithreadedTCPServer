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
    if (!_socket->setSocketDescriptor(_socketDescriptor)) {
        qDebug() << _socket->errorString();
        return;
    }

    // TODO: using direct connection should fix bugs?
    connect(_socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(_socket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()), Qt::DirectConnection);

    qDebug() << _socketDescriptor << "Client connected.";

    exec();
}

void SocketThread::readyRead() {
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