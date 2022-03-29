#ifndef POLINOM_H
#define POLINOM_H

#include <iostream>
#include <QString>

using namespace std;

enum EPrintMode
{
    EPrintModeClassic,
    EPrintModeCanonic,
};

template <class number>
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
    template<class T>
    friend ostream& operator<< (ostream&,TPolinom<T>&);
    template<class T>
    friend QString& operator<< (QString&,TPolinom<T>&);
};

template <class number>
TPolinom<number>::TPolinom(number x,number y,number z)
{
    printMode = EPrintModeClassic;
    a = x;
    b = y;
    c = z;
}

template <class number>
ostream& operator<< (ostream& os,TPolinom<number>& p)
{
    if (p.printMode == EPrintModeClassic)
        os<<p.a<<"x^2+"<<p.b<<"x+"<<p.c;
    else
    {
        os<<p.a<<"(x-("<<p.calculateroots()[0]<<"))(x-("<<p.calculateroots()[1]<<"))"<<endl;
    }
    return os;
}

template <class number>
number TPolinom<number>::value(number x)
{
    return a*x*x+b*x+c;
}

template <class number>
void TPolinom<number>::setPrintMode(EPrintMode m)
{
    printMode = m;
}

template <class number>
void TPolinom<number>::calculateroots()
{
    if (((b*b)-((a*c)*4)) >= 0)
    {
        roots[0] = (b*(-1)+sqrt((b*b)-((a*c)*4)))/(a*2);
        roots[1] = (b*(-1)-sqrt((b*b)-((a*c)*4)))/(a*2);
    }
}

template <class number>
number* TPolinom<number>::getroots()
{
    return roots;
}

template <class number>
QString& operator<< (QString& s, TPolinom<number>& p)
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

#endif // POLINOM_H
