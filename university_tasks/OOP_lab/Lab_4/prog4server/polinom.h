#ifndef POLINOM_H
#define POLINOM_H

#include "number.h"
#include <iostream>

using namespace std;

enum EPrintMode
{
    EPrintModeClassic,
    EPrintModeCanonic,
};

class TPolinom
{
    EPrintMode printMode;
    number a, b, c;
    number roots[2];
public:
    TPolinom(number,number,number);
    number value(number);
    void calculateroots();
    number* getroots();
    void setPrintMode(EPrintMode);
    friend ostream& operator<< (ostream&,TPolinom&);
    friend QString& operator<< (QString&,TPolinom&);
};

#endif // POLINOM_H
