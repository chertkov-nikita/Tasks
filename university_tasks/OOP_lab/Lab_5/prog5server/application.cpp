#include "application.h"
#include "polinom.h"
#include "rational.h"
#include "common.h"

QByteArray& operator>>(QByteArray& arr, int& c)
{
    int p = arr.indexOf(separator);
    if (p > 0)
    {
        c = atoi(arr.left(p));
        arr = arr.right(arr.length()-p-1);
    }
    return arr;
}

QString& operator<< (QString& s, int r)
{
    s += QString().setNum(r);
    return s;
}

TApplication::TApplication(int argc, char *argv[])
            : QCoreApplication(argc,argv)
{
    TCommParams pars = { QHostAddress("127.0.0.1"), 10000,
                         QHostAddress("127.0.0.1"), 10001};
    comm = new TCommunicator(pars, this);

    connect(comm,SIGNAL(recieved(QByteArray)),this,SLOT(recieve(QByteArray)));
}

void TApplication::recieve(QByteArray msg)
{
    QString answer, s;
    int pos = msg.indexOf(separator);
    int mode = msg.left(pos).toInt();
    msg = msg.right(msg.length()-pos-1);

    if (mode == R_MODE)
    {
        TRational a, b, c, x, v;
        msg>>a>>b>>c;
        TPolinom<TRational> p(a,b,c);
        int pos = msg.indexOf(separator);
        int t = msg.left(pos).toInt();
        switch (t)
        {
            case VALUE_REQUEST:
                msg = msg.right(msg.length()-pos-1);
                msg>>x;
                v = p.value(x);
                s<<(QString)x<<(QString)v;
                answer<<QString().setNum(VALUE_ANSWER);
                answer += s;
                break;
            case ROOTS_REQUEST:
                p.calculateroots();
                s<<(QString)p.getroots()[0]<<(QString)p.getroots()[1];
                answer<<QString().setNum(ROOTS_ANSWER);
                answer += s;
                break;
            case PRINT_CLASSIC_REQUEST:
                p.setPrintMode(EPrintModeClassic);
                s<<p;
                answer<<QString().setNum(PRINT_ANSWER)<<s;
                break;
            case PRINT_CANONIC_REQUEST:
                p.setPrintMode(EPrintModeCanonic);
                s<<p;
                answer<<QString().setNum(PRINT_ANSWER)<<s;
                break;
            default: return;
        }
    }
    if (mode == I_MODE)
    {
        int a, b, c, x, v;
        msg>>a>>b>>c;
        TPolinom<int> p(a,b,c);
        int pos = msg.indexOf(separator);
        int t = msg.left(pos).toInt();
        switch (t)
        {
            case VALUE_REQUEST:
                msg = msg.right(msg.length()-pos-1);
                msg>>x;
                v = p.value(x);
                s<<("("+QString().setNum(x)+")")<<QString().setNum(v);
                answer<<QString().setNum(VALUE_ANSWER);
                answer += s;
                break;
            case ROOTS_REQUEST:
                p.calculateroots();
                s<<QString().setNum(p.getroots()[0])<<QString().setNum(p.getroots()[1]);
                answer<<QString().setNum(ROOTS_ANSWER);
                answer += s;
                break;
            case PRINT_CLASSIC_REQUEST:
                p.setPrintMode(EPrintModeClassic);
                s<<p;
                answer<<QString().setNum(PRINT_ANSWER)<<s;
                break;
            case PRINT_CANONIC_REQUEST:
                p.setPrintMode(EPrintModeCanonic);
                s<<p;
                answer<<QString().setNum(PRINT_ANSWER)<<s;
                break;
            default: return;
        }
    }
    comm->send(QByteArray().append(answer.toUtf8()));
}
