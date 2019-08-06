//
// Created by rocke on 2019/8/6.
//

#ifndef QMULTITHREADEDTCPSERVER_MULTITHREADEDTCPSERVER_H
#define QMULTITHREADEDTCPSERVER_MULTITHREADEDTCPSERVER_H

#include <QTcpServer>

class MultithreadedTCPServer: public QTcpServer {
    Q_OBJECT

public:
    void startServer();

protected:
    // This virtual function is called by QTcpServer when a new connection is available
    void incomingConnection(qintptr socketDescriptor) override;

public slots:


};


#endif //QMULTITHREADEDTCPSERVER_MULTITHREADEDTCPSERVER_H
