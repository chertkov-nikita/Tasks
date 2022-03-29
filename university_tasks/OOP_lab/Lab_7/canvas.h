#ifndef VIEWER_H
#define VIEWER_H

#include <QWidget>
#include <QMouseEvent>
#include "eventgraph.h"

class TCanvas : public QWidget
{
    Q_OBJECT

    TEventGraph* s;
public:
    TCanvas(TEventGraph*,QWidget *parent = 0);
    ~TCanvas();

protected:
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent*);
};

#endif // VIEWER_H
