#include "canvas.h"

TCanvas::TCanvas(TEventGraph* f, QWidget *parent)
    : QWidget(parent)
{
    s = f;
    setFixedSize(400,400);
}

TCanvas::~TCanvas()
{

}

void TCanvas::paintEvent(QPaintEvent*)
{
    QPainter p;
    p.begin(this);
    s->draw(&p,rect(),Qt::white);
    p.end();
}

void TCanvas::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)  s->newEvent(false);
    if (event->button() == Qt::RightButton) s->newEvent(true);
    update();
}
