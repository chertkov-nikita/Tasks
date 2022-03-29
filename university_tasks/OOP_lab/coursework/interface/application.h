#ifndef TAPPLICATION_H
#define TAPPLICATION_H

#include <QApplication>

#include "transmitter.h"
#include "communicator.h"
#include "mainwindow.h"

class TApplication : public QApplication
{
    Q_OBJECT

    TCommunicator *comm;
    TTransmitter    *transmitter;

public:
    TApplication(int, char**);
    TTransmitter* get_transmitter();

public slots:
    void fromCommunicator(QByteArray);
    void toCommunicator(QString);

};

#endif // TAPPLICATION_H
