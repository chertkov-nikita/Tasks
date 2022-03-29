#ifndef TEVENTGRAPH_H
#define TEVENTGRAPH_H

#include "graph.h"

class TEventGraph : public TGraph
{
    int active;
    int activity_index = 0;
    QVector<qint16> events;

public:
    TEventGraph(QString,int);
    void draw(QPainter*,QRect,QColor);
    void newEvent(bool);
};

#endif // TEVENTGRAPH_H
