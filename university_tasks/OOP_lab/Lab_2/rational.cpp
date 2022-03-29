#include "rational.h"
#include <cmath>

TRational::TRational()
{

}

TRational::TRational(int a, int b)
{
    numerator = a;
    numerator = b;
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
    return t;
}

TRational TRational::operator+ (TRational r)
{
    TRational t;
    t.numerator = numerator * r.denominator + r.numerator * denominator;
    t.denominator = denominator * r.denominator;
    return t;
}

TRational TRational::operator- (TRational r)
{
    TRational t;
    t.numerator = numerator * r.denominator - r.numerator * denominator;
    t.denominator = denominator * r.denominator;
    return t;
}

TRational TRational::operator* (int num)
{
    TRational t;
    t.numerator = numerator * num;
    t.denominator = denominator;
    return t;
}

TRational TRational::operator* (TRational r)
{
    TRational t;
    t.numerator = numerator * r.numerator;
    t.denominator = denominator * r.denominator;
    return t;
}

TRational TRational::operator/ (TRational r)
{
    TRational t;
    t.numerator = numerator * r.denominator;
    t.denominator = denominator * r.numerator;
    return t;
}

TRational sqrt(TRational r)
{
    TRational t;
    t.numerator = sqrt(r.numerator);
    t.denominator = sqrt(r.denominator);
    return t;
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
    int nod = r.gcd(r.numerator,r.denominator);
    os << r.numerator/nod << '/' << r.denominator/nod;
    return os;
}

istream& operator>> (istream& is, TRational r)
{
    is >> r.numerator >> r.denominator;
    return is;
}
