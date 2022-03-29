#include "polinom.h"
#include "math.h"

TPolinom::TPolinom(number x, number y, number z)
{
    printMode = EPrintModeClassic;
    a=x;
    b=y;
    c=z;
}

ostream& operator<< (ostream& os, TPolinom p)
{
    if (p.printMode == EPrintModeClassic)
        os<<p.a<<"x^2+"<<p.b<<"x+"<<p.c;
    else if (p.printMode == EPrintModeCanonic)
    {
        p.calculateroots();
        os<<p.a<<"(x-("<<p.root1<<"))(x-("<<p.root2<<"))"<<endl;
    }
    return os;
}

number TPolinom::value(number x)
{
    return a*x*x+b*x+c;
}

void TPolinom::setPrintMode(EPrintMode m)
{
    printMode = m;
}

void TPolinom::calculateroots()
{
    root1 = (b*(-1)+sqrt((b*b)-((a*c)*4)))/(a*2);
    root2 = (b*(-1)-sqrt((b*b)-((a*c)*4)))/(a*2);
}
