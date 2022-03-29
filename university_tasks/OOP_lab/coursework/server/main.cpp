#include "application.h"

int main(int argc, char *argv[])
{
    TBookkeeping d;
    TApplication a(argc, argv, d);
    return a.exec();
}
