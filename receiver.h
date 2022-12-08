#ifndef RECEIVER_H
#define RECEIVER_H
#include<QObject>
#include<QHostAddress>
#include <QUdpSocket>

class Receiver : public QObject
{
    Q_OBJECT
public:
    Receiver(QObject* parent = nullptr);
    ~Receiver();
    Q_INVOKABLE void getInfor(QString port);
private slots:
    void processPendingDatagrams();
private:
    int count_ = 0;
    QUdpSocket *udpSocket = nullptr;
};

#endif // RECEIVER_H
