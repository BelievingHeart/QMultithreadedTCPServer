//
// Created by rocke on 2019/8/6.
//

#include "MultithreadedTCPServer.h"
#include <QDebug>
#include "SocketThread.h"

void MultithreadedTCPServer::startServer() {
    if (listen(QHostAddress::Any, 1234)) {
        qDebug() << "Listening...";
    } else {
        qDebug() << "Could not start server";
    }
}

void MultithreadedTCPServer::incomingConnection(qintptr socketDescriptor) {
    qDebug() << socketDescriptor << " Connecting...";

    auto thread = new SocketThread(socketDescriptor, this);
    // The thread can automatically clear itself
    // when the socket is disconnected
    // which causes the thread to exit
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    thread->start();
}
