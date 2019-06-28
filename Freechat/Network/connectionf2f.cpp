/*
***Copyleft (C) 2019 Softwater, Inc
***Contact: bogdyname@gmail.com
*/

#include "Network/connectionf2f.h"
#include "Bin/bin.h"

ConnectionF2F::ConnectionF2F(QObject *parent)
    : QTcpSocket(parent)
{

}

Peerout::~Peerout()
{
    delete socket;
}

void Peerout::MakeSocket()
{
    socket = new QTcpSocket(this);
    socket->connectToHost("WAN IP OF USER", 80);

        if(socket->waitForConnected(3000))
        {
            qDebug() << "Connected!";

            socket->write("DATA OF TEXT");
            socket->waitForBytesWritten(1000);
            socket->waitForReadyRead(3000);
            qDebug() << "Reading: " << socket->bytesAvailable();

            qDebug() << socket->readAll();

            socket->close();
        }
        else
        {
            qDebug() << "Not connected!";
        }
}
