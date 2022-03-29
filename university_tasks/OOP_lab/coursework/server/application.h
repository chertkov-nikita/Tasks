#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QCoreApplication>

#include "communicator.h"
#include "bookkeeping.h"

class TApplication : public QCoreApplication
{
    Q_OBJECT

    TCommunicator *comm;
    TBookkeeping server_data;

public:

    TApplication(int, char**, TBookkeeping);

public slots:

    void recieve(QByteArray);

};

#endif // APPLICATION_H
