#include "quadrangle.h"

TQuadrangle::TQuadrangle (const double &a, const double &b, const double &c,
                        const double &alpha, const double &beta)
{
    sideList.append (a);
    sideList.append (b);
    sideList.append (c);
    angleList.append (alpha);
    angleList.append (beta);
    auxCalc ();
}
