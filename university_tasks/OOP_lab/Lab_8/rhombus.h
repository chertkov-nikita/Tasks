#ifndef RHOMBUS_H
#define RHOMBUS_H
#include "parallelogram.h"

class TRhombus : virtual public TParallelogram
{
public:
    TRhombus (const double &a, const double &alpha);
};

#endif // RHOMBUS_H
