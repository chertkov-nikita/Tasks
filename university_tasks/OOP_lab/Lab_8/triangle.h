#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "polygon.h"

class TTriangle : public TPolygon
{
public:
    TTriangle (const double &a, const double &b, const double &angle);
};

#endif // TRIANGLE_H
