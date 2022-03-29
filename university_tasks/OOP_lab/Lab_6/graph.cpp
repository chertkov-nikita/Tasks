#include "graph.h"
#include <math.h>

TGraph::TGraph()
{
    tops_count = 0;
}

TGraph::TGraph(QString str)
{
    matrix = TMatrix(str);
    tops_count = matrix.get_size();
}

void TGraph::draw(QPainter* p, QRect r, QColor c)
{
    qreal cw = 0.5*r.width();
    qreal ch = 0.5*r.height();
    qreal cr = 0.9*(cw>ch?ch:cw);
    qreal a = 2.0*acos(-1.0)/tops_count;
    qreal rad = 0.1*(cw>ch?ch:cw);

    QRectF *t = new QRectF[tops_count];
    for (int i=0; i<tops_count; i++)
    {
        t[i] = QRectF(cw+cr*sin(i*a)-rad, ch-cr*cos(i*a)-rad, 2*rad, 2*rad);
    }

    p->setPen(QPen(Qt::black));
    p->setBrush(QBrush(c));
    QFont font;
    qreal cf = 0.6*rad;
    font.setPointSize(cf);
    font.setBold(true);
    p->setFont(font);

    qreal arrow_len = 12;
    double arrow_acuity = 0.6;
    double f1x2 , f1y2;
    double angle;
    for (int i=0; i<tops_count; i++)
    {
        for (int j=0; j<tops_count; j++)
        {
            if (i == j && matrix.get_matrix()[i][j] == 1)
            {
                p->drawEllipse(QRectF(cw+cr*sin(i*a)-rad*2.2, ch-cr*cos(i*a)-rad, 2*rad, 2*rad));
            }
            else if (i != j && matrix.get_matrix()[i][j] == 1)
            {

                angle = atan2((t[j].center().y() - t[i].center().y()), t[j].center().x() - t[i].center().x());
                QLineF line(t[i].center() + QPointF(rad*cos(angle), rad*sin(angle)), t[j].center() - QPoint(rad*cos(angle), rad*sin(angle)));
                p->drawLine(line);

                f1x2 = line.p2().x() - arrow_len * cos(angle - arrow_acuity);
                f1y2 = line.p2().y() - arrow_len * sin(angle - arrow_acuity);

                p -> drawLine(line.p2().x(), line.p2().y(), f1x2, f1y2);

                f1x2 = line.p2().x() - arrow_len * cos(angle + arrow_acuity);
                f1y2 = line.p2().y() - arrow_len * sin(angle + arrow_acuity);

                p -> drawLine(line.p2().x(), line.p2().y(), f1x2, f1y2);
            }

        }
    }

    for (int i=0; i<tops_count; i++)
    {
        p->drawEllipse(t[i]);
        p->drawText(t[i], QString().setNum(i+1), QTextOption(Qt::AlignCenter));
    }

    delete [] t;
}
