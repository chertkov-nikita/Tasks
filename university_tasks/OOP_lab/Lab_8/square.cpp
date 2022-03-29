#include "square.h"

TSquare::TSquare (const double &a)
    : TParallelogram (a, a, 90), TRectangle (a, a), TRhombus(a, 90)
{

}

