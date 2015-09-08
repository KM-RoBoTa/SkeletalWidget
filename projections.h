#ifndef PROJECTIONS_H
#define PROJECTIONS_H

#include <vector>
#include <QWidget>
#include "dskeleton.h"

namespace Ui {
class Projections;
}

class Projections : public QWidget
{
    Q_OBJECT

public:
    explicit Projections(QWidget *parent = 0);
    ~Projections();
    void setAngles(std::vector<double> anglesInRadians);
    void redraw();
    void setMode(int mode);

private slots:
    void paintEvent(QPaintEvent *e);

private:
    Ui::Projections *ui;
    DSkeleton* d;
};

#endif // PROJECTIONS_H
