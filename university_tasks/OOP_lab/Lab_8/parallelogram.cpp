#include "parallelogram.h"

TParallelogram::TParallelogram (const double &a, const double &b, const double &alpha)
    : TQuadrangle (a, b, a, alpha, 180 - alpha)
{

}
