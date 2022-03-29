#ifndef GRAPH_H
#define GRAPH_H

#include <QPainter>
#include "matrix.h"

class TGraph
{
    TMatrix matrix;
    int tops_count;
public:
    TGraph();
    TGraph(QString);
    void draw(QPainter*,QRect,QColor);
};

#endif // GRAPH_H
