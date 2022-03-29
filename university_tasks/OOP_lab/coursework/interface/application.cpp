#include "application.h"

TApplication::TApplication(int argc, char *argv[])
            : QApplication(argc,argv)
{
    TCommParams pars = { QHostAddress("127.0.0.1"), 10001,
                         QHostAddress("127.0.0.1"), 10000};
    comm = new TCommunicator(pars, this);

    transmitter = new TTransmitter();

    connect(comm,SIGNAL(recieved(QByteArray)),this,
            SLOT(fromCommunicator(QByteArray)));
    connect(transmitter,SIGNAL(request(QString)),
            this,SLOT(toCommunicator(QString)));

}

TTransmitter* TApplication::get_transmitter()
{
    return transmitter;
}

void TApplication::fromCommunicator(QByteArray msg)
{
    transmitter->answer(QString(msg));
}

void TApplication::toCommunicator(QString msg)
{
    comm->send(QByteArray().append(msg.toUtf8()));
}
