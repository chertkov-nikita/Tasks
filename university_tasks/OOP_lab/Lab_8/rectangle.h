#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "parallelogram.h"

class TRectangle : virtual public TParallelogram
{
public:
    TRectangle (const double &a, const double &b);
};

#endif // RECTANGLE_H
