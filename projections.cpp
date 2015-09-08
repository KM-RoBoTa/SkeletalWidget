#include "projections.h"
#include "ui_projections.h"

#include <QPoint>
#include <QPainter>


Projections::Projections(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Projections)
{
    ui->setupUi(this);
    d = new DSkeleton(16);
    d->setMode(0);
}

Projections::~Projections()
{
    delete ui;
}

void Projections::setAngles(std::vector<double> anglesInRadians)
{
    d->setAngles(anglesInRadians);
}

void Projections::setMode(int mode)
{
    d->setMode(mode);
}

void Projections::redraw()
{
//    update();
    repaint();
}

void Projections::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    painter.setBackgroundMode(Qt::OpaqueMode);
    painter.setBackground(Qt::white);

    QPen outline(Qt::red);
    outline.setWidth(10);
    QBrush fill(Qt::gray, Qt::SolidPattern);

    painter.setPen(outline);
    painter.setBrush(fill);

    std::vector<QPoint> allPoints = d->getPoints();

    QPoint start, end;
    start = allPoints[allPoints.size() - 1];

    int szDot = 5;
    for (int i = allPoints.size() - 2; i >= 0; i--)
    {
        end = start;
        painter.drawEllipse(end,szDot,szDot);

        start = allPoints[i];
        painter.drawLine(start,end);
    }

    outline.setColor(Qt::blue);
    painter.setPen(outline);
    painter.drawEllipse(allPoints[0],szDot,szDot);
    painter.end();
}
