#ifndef TINTERFACE_H
#define TINTERFACE_H

#include <QObject>

class TTransmitter  : public QObject
{
    Q_OBJECT

    QString response_to_request;

public:
    TTransmitter(QObject *parent = 0);
    ~TTransmitter();

    void formRequest(QString, QString add_data = nullptr);
    QString get_response();

public slots:
    void answer(QString);

signals:
    void request(QString);
};

#endif // TINTERFACE_H
