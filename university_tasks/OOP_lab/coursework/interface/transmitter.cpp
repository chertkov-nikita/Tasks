#include "transmitter.h"
#include "common.h"

TTransmitter::TTransmitter(QObject *parent)
    : QObject(parent)
{

}

TTransmitter::~TTransmitter()
{

}

void TTransmitter::formRequest(QString str, QString add_data)
{
    QString msg;
    if (str == "ADD EMP")
        msg << QString().setNum(ADD_EMPLOYEE_REQUEST);
    if (str == "DEL EMP")
        msg << QString().setNum(DELETE_EMPLOYEE_REQUEST);
    if (str == "CH SETT")
        msg << QString().setNum(CHANGE_SETTINGS_REQUEST) << add_data;
    if (str == "GET DATA")
        msg << QString().setNum(GET_DATA_REQUEST);
    emit request(msg);
}

QString TTransmitter::get_response()
{
    return response_to_request;
}

void TTransmitter::answer(QString msg)
{
    int p = msg.indexOf(separator);
    int t = msg.left(p).toInt();
    msg = msg.mid(p+1,msg.length()-p-2);
    switch (t)
    {
        case ADD_EMPLOYEE_ANSWER:

            break;
        case DELETE_EMPLOYEE_ANSWER:

            break;
        case CHANGE_SETTINGS_ANSWER:

            break;
        case GET_DATA_ANSWER:
            response_to_request = msg;
            break;
        default: break;
    }
}
