#ifndef QUADRANGLE_H
#define QUADRANGLE_H
#include "polygon.h"

class TQuadrangle : public TPolygon
{
public:
    explicit TQuadrangle (const double &a, const double &b, const double &c, const double &alpha, const double &beta);
};

#endif // QUADRANGLE_H
