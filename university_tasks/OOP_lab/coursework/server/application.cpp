#include "application.h"
#include "common.h"

TApplication::TApplication(int argc, char *argv[], TBookkeeping cashbox_info)
            : QCoreApplication(argc,argv)
{
    TCommParams pars = { QHostAddress("127.0.0.1"), 10000,
                         QHostAddress("127.0.0.1"), 10001};
    comm = new TCommunicator(pars, this);
    connect(comm,SIGNAL(recieved(QByteArray)),this,SLOT(recieve(QByteArray)));

    server_data = cashbox_info;
}

void TApplication::recieve(QByteArray msg)
{
    QString answer;
    int pos = msg.indexOf(separator);
    int t = msg.left(pos).toInt();
    int p;

    switch (t)
    {
        case CHANGE_SETTINGS_REQUEST:
            msg = msg.right(msg.length()-pos-1);
            p = msg.indexOf(separator);
            server_data.change_cashbox_cnt(msg.left(p).toInt());
            answer << QString().setNum(CHANGE_SETTINGS_ANSWER);
            break;

        case ADD_EMPLOYEE_REQUEST:
            server_data.add_new_employee();
            answer << QString().setNum(ADD_EMPLOYEE_REQUEST);
            break;

        case DELETE_EMPLOYEE_REQUEST:
            server_data.delete_employee();
            answer << QString().setNum(DELETE_EMPLOYEE_ANSWER);
            break;

        case GET_DATA_REQUEST:
            answer << QString().setNum(GET_DATA_ANSWER) << QString().setNum(server_data.get_cashbox_cnt());
            for (int i = 0; i < server_data.get_cashbox_cnt() ;i++)
            {
                answer << QString().setNum(server_data.get_cashbox_list()[i].get_len());
            }
            break;

        default: return;
    }

    comm->send(QByteArray().append(answer.toUtf8()));
}
