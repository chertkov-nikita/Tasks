#include "polygon.h"

TPolygon::TPolygon()
{

}

TPolygon::~TPolygon()
{

}

double TPolygon::area()
{
    double s = 0;

    if(sideList.size() == 1 && angleList.size() == 0) {
       s = pi * pow(sideList[0], 2);
       return s;
    }

    s += 0.5 * sideList[0] * sideList[1] * sin(angleList[0] * pi / 180);

    if(sideList.size() < 3)
        return s;

    s += 0.5 * iEdge[0] * sideList[2] * sin(iAngle[0]);

    if(sideList.size() < 4)
        return s;

    for(int i = 0; i < sideList.size() - 3; ++i)
        s += 0.5 * iEdge[i + 1] * sideList[i + 3] * sin(iAngle[i + 1]);

    return s;
}

double TPolygon::perimetr()
{
    double p = 0;
    if (sideList.size() == 1 && angleList.size() == 0) {
        p = 2 * pi * sideList[0];
        return p;
    }
    for(int i = 0; i < sideList.size(); ++i)
    {
        p += sideList[i];
    }
    p += iEdge.back();
    return p;
}

void TPolygon::auxCalc()
{
    iEdge.append(sqrt(sideList[0] * sideList[0] + sideList[1] * sideList[1] - 2 * sideList[0] * sideList[1] * cos(angleList[0] * pi / 180)));

    if(sideList.size() > 2)
    {
        iAngle.append(angleList[1] * pi / 180 - asin(sideList[0] * sin(angleList[0] * pi / 180) / iEdge[0]));
        iEdge.append(sqrt(iEdge[0] * iEdge[0] + sideList[2] * sideList[2] - 2 * iEdge[0] * sideList[2] * cos(iAngle[0])));
        for(int i = 0; i < sideList.size() - 3; ++i)
        {
            iAngle.append(angleList[i + 2] * pi / 180 - asin(iEdge[i] * sin(iAngle[i]) / iEdge[i + 1]));
            iEdge.append(sqrt(iEdge[i + 1] * iEdge[i + 1] + sideList[i + 3] * sideList[i + 3] - 2 * iEdge[i + 1] * sideList[i + 3] * cos(iAngle[i + 1])));
        }
    }
}
