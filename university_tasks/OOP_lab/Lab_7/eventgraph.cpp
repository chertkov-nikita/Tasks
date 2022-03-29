#include "eventgraph.h"
#include "cmath"
TEventGraph::TEventGraph(QString str,int spinBox) : TGraph(str)
{
    active = spinBox -1;
    QVector<qint16> tmp;
    QVector<QVector<qint16>> copy = matrix.get_matrix();
    int i = active;
    int j = 0;
    int t;

    tmp.push_back(i);
    while (j < copy[i].length())
    {
        if (copy[i][j] != 0)
        {
            tmp.push_back(copy[i][j] - 1);
            t = copy[i][j] - 1;
            copy[i][j] = 0;
            i = t;
            j = 0;
        }
        else
        {
            j++;
        }
    }

    events = tmp;
}

void TEventGraph::draw(QPainter* p, QRect r, QColor c)
{
    TGraph::draw(p,r,c);
    qreal cw = 0.5*r.width();
    qreal ch = 0.5*r.height();
    qreal cr = 0.9*(cw>ch?ch:cw);
    qreal a = 2.0*acos(-1.0)/tops_count;
    QPointF t(cw+cr*sin(active*a),ch-cr*cos(active*a));
    p->setPen(QPen(Qt::black));
    p->setBrush(QBrush(Qt::yellow));
    p->drawEllipse(t,0.08*cr,0.08*cr);
}

void TEventGraph::newEvent(bool direction)
{
    if (!direction)
    {
        if (activity_index < events.length() - 1)
        {
            active = events[activity_index  + 1];
            activity_index++;
        }
    }
    else
    {
        if (activity_index != 0)
        {
            active = events[activity_index - 1];
            activity_index--;
        }
    }
}
