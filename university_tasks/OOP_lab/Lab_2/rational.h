#ifndef TRATIONAL_H
#define TRATIONAL_H

#include <iostream>

using namespace std;

class TRational
{
    int numerator, denominator;
public:
    TRational();
    TRational(int, int);
    TRational(const int&);

    TRational operator+ (int);
    TRational operator+ (TRational);
    TRational operator- (TRational);
    TRational operator* (int);
    TRational operator* (TRational);
    TRational operator/ (TRational);

    int gcd(int, int);

    friend TRational sqrt(TRational);
    friend ostream& operator<< (ostream&, TRational);
    friend istream& operator>> (istream&, TRational);
};

#endif // TRATIONAL_H
