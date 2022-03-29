#include "rational.h"
#include "common.h"
#include <cmath>

char TRational::SEPARATOR = separator;

TRational::TRational()
{

}

TRational::TRational(int a, int b)
{
    numerator = a;
    if (b == 0)
    {
        denominator = 1;
        cout << "Error denominator 0" << endl;
    }
    else
        denominator = b;
}

TRational::TRational(const int& a)
{
    numerator = a;
    denominator = 1;
}

TRational TRational::operator+ (int num)
{
    TRational t;
    t.numerator = numerator + (num * denominator);
    t.denominator = denominator;

    int nod = t.gcd(t.numerator,t.denominator);
    t.numerator = t.numerator/nod;
    t.denominator = t.denominator/nod;
    return t;
}

TRational TRational::operator+ (TRational r)
{
    TRational t;
    t.numerator = numerator * r.denominator + r.numerator * denominator;
    t.denominator = denominator * r.denominator;

    int nod = t.gcd(t.numerator,t.denominator);
    t.numerator = t.numerator/nod;
    t.denominator = t.denominator/nod;
    return t;
}

TRational TRational::operator- (TRational r)
{
    TRational t;
    t.numerator = numerator * r.denominator - r.numerator * denominator;
    t.denominator = denominator * r.denominator;

    int nod = t.gcd(t.numerator,t.denominator);
    t.numerator = t.numerator/nod;
    t.denominator = t.denominator/nod;
    return t;
}

TRational TRational::operator* (int num)
{
    TRational t;
    t.numerator = numerator * num;
    t.denominator = denominator;

    int nod = t.gcd(t.numerator,t.denominator);
    t.numerator = t.numerator/nod;
    t.denominator = t.denominator/nod;
    return t;
}

TRational TRational::operator* (TRational r)
{
    TRational t;
    t.numerator = numerator * r.numerator;
    t.denominator = denominator * r.denominator;

    int nod = t.gcd(t.numerator,t.denominator);
    t.numerator = t.numerator/nod;
    t.denominator = t.denominator/nod;
    return t;
}

TRational TRational::operator/ (TRational r)
{
    TRational t;
    t.numerator = numerator * r.denominator;
    t.denominator = denominator * r.numerator;

    int nod = t.gcd(t.numerator,t.denominator);
    t.numerator = t.numerator/nod;
    t.denominator = t.denominator/nod;
    return t;
}

TRational sqrt(TRational r)
{
    TRational t;
    t.numerator = sqrt(r.numerator);
    t.denominator = sqrt(r.denominator);

    int nod = t.gcd(t.numerator,t.denominator);
    t.numerator = t.numerator/nod;
    t.denominator = t.denominator/nod;
    return t;
}

bool TRational::operator>= (int num)
{
    if ((numerator < 0 and denominator < 0) or (numerator > 0 and denominator < 0))
    {
        numerator *= -1;
        denominator *= -1;
    }
    if (numerator >= num*denominator)
        return true;
    else
        return false;
}

int TRational::gcd(int a, int b)
{
    int c;
       while (b) {
          c = a % b;
          a = b;
          b = c;
       }
       return abs(a);
}

ostream& operator<< (ostream& os, TRational r)
{
    os << r.numerator << '/' << r.denominator;
    return os;
}

istream& operator>> (istream& is, TRational& r)
{
    is >> r.numerator >> r.denominator;
    return is;
}

QString& operator<< (QString& s, TRational r)
{
    s += QString().setNum(r.numerator);
    s += '/';
    s += QString().setNum(r.denominator);
    return s;
}


TRational::operator QString ()
{
    QString s;
    s += QString().setNum(numerator);
    s += "/";
    s += QString().setNum(denominator);
    return s;
}

TRational::TRational(const QByteArray& arr)
{
    int p = arr.indexOf(SEPARATOR);
    numerator = arr.left(p).toInt();
    denominator = arr.right(arr.length()-p-1).toInt();
    if (denominator == 0)
    {
        denominator = 1;
        cout << "Error denominator 0" << endl;
    }

}

QByteArray& operator>>(QByteArray& arr, TRational& c)
{
    int p = arr.indexOf(TRational::SEPARATOR);
    p = arr.indexOf(TRational::SEPARATOR,p+1);
    if (p > 0)
    {
        c = TRational(arr.left(p));
        arr = arr.right(arr.length()-p-1);
    }
    return arr;
}

void TRational::setSeparator(char ch)
{
    SEPARATOR = ch;
}
