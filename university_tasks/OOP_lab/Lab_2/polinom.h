#ifndef TPOLINOM_H
#define TPOLINOM_H

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

public:
    number root1, root2;

    TPolinom(number, number, number);
    friend ostream& operator<< (ostream&, TPolinom);
    number value(number);
    void setPrintMode(EPrintMode);
    void calculateroots();
};

#endif // TPOLINOM_H
