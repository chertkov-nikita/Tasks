#ifndef POLYGON_H
#define POLYGON_H
#include <math.h>
#include <QList>

class TPolygon
{
double pi = 3.14159265;
public:
    TPolygon();
    ~TPolygon();

    double area();
    double perimetr();

protected:
    void auxCalc();
    QList <double> sideList;
    QList <double> angleList;
    QList <double> iEdge;
    QList <double> iAngle;
};

#endif // POLYGON_H
