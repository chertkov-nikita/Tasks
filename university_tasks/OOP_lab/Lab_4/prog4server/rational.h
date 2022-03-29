#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
using namespace std;

#include <QString>

class TRational
{
    static char SEPARATOR;
    int numerator, denominator;

public:
    TRational();
    TRational(int, int);
    TRational(const int&);
    TRational(const QByteArray&);

    TRational operator+ (int);
    TRational operator+ (TRational);
    TRational operator- (TRational);
    TRational operator* (int);
    TRational operator* (TRational);
    TRational operator/ (TRational);
    bool operator>= (int);

    int gcd(int, int);

    friend TRational sqrt(TRational);
    friend ostream& operator<< (ostream&, TRational);
    friend istream& operator>> (istream&, TRational&);
    friend QString& operator<< (QString&, TRational);

    static void setSeparator(char);

    friend QByteArray& operator>>(QByteArray&,TRational&);
    operator QString ();
};

#endif // RATIONAL_H
