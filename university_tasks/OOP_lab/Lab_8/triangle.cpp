#include "triangle.h"

TTriangle::TTriangle (const double &a, const double &b, const double &angle)
{
    sideList.append(a);
    sideList.append(b);

    angleList.append(angle);

    auxCalc();
}

