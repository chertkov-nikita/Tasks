#ifndef SQUARE_H
#define SQUARE_H
#include "rectangle.h"
#include "rhombus.h"

class TSquare : public TRectangle, public TRhombus
{
public:
    TSquare (const double &a);
};

#endif // SQUARE_H
