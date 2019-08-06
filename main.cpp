#include <QCoreApplication>
#include "MultithreadedTCPServer.h"

int main(int argc, char* argv[]) {
    QCoreApplication app(argc, argv);

    MultithreadedTCPServer server;
    server.startServer();

    return app.exec();
}