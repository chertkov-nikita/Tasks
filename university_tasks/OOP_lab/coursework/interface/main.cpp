#include "application.h"

int main(int argc, char *argv[])
{
    TApplication a(argc, argv);
    MainWindow w(a.get_transmitter());
    w.show();
    return a.exec();
}
