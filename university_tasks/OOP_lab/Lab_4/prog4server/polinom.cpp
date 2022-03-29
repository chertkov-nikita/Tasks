#include "polinom.h"

TPolinom::TPolinom(number x,number y,number z)
{
    printMode = EPrintModeClassic;
    a = x;
    b = y;
    c = z;
}

ostream& operator<< (ostream& os,TPolinom& p)
{
    if (p.printMode == EPrintModeClassic)
        os<<p.a<<"x^2+"<<p.b<<"x+"<<p.c;
    else
    {
        p.calculateroots();
        os<<p.a<<"(x-("<<p.roots[0]<<"))(x-("<<p.roots[1]<<"))"<<endl;
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
    if (((b*b)-((a*c)*4)) >= 0)
    {
        roots[0] = (b*(-1)+sqrt((b*b)-((a*c)*4)))/(a*2);
        roots[1] = (b*(-1)-sqrt((b*b)-((a*c)*4)))/(a*2);
    }
    else
    {
        roots[0] = 321;
        roots[1] = 321;
    }
}

number* TPolinom::getroots()
{
    return roots;
}

QString& operator<< (QString& s, TPolinom& p)
{
    if (p.printMode == EPrintModeClassic)
    {
        s << p.a;
        s += "x^2+";
        s << p.b;
        s += "x+";
        s << p.c;
    }
    else if (p.printMode == EPrintModeCanonic)
    {
        p.calculateroots();
        s << p.a;
        s += "(x-(";
        s << p.roots[0];
        s += "))(x-(";
        s << p.roots[1];
        s += "))";
    }
    return s;
}
