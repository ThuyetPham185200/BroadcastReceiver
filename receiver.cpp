#include "receiver.h"

Receiver::Receiver(QObject* parent)
    : QObject(parent)
{
    udpSocket = new QUdpSocket(this);
}

Receiver::~Receiver()
{

}

void Receiver::getInfor(QString port)
{
    udpSocket->bind(port.toInt(), QUdpSocket::ShareAddress);
    connect(this->udpSocket, SIGNAL(readyRead()),
            this, SLOT(processPendingDatagrams()));
}

void Receiver::processPendingDatagrams()
{
    QByteArray datagram;
    while (udpSocket->hasPendingDatagrams()) {
        datagram.resize(int(udpSocket->pendingDatagramSize()));
        udpSocket->readDatagram(datagram.data(), datagram.size());
        std::vector<unsigned char> dataFrame_(datagram.begin(), datagram.end());
        this->count_ += 1;
        printf("length of dataFrame: %d\n id: %d\n", dataFrame_.size(), this->count_);
    }
}
