#ifndef GRAPH_H
#define GRAPH_H

#include <QPainter>
#include "matrix.h"

class TGraph
{
protected:
    int tops_count;
    TMatrix matrix;
public:
    TGraph();
    TGraph(QString);
    void draw(QPainter*,QRect,QColor);
};

#endif // GRAPH_H
