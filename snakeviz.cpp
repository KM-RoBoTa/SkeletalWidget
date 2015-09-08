#include "snakeviz.h"
#include "ui_snakeviz.h"

#include <vector>

SnakeViz::SnakeViz(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SnakeViz)
{
    ui->setupUi(this);
}

SnakeViz::~SnakeViz()
{
    delete ui;
}

#define PI 3.14159
void SnakeViz::refresh()
{
    std::vector<double> angles(16,0);
    angles[0] = ui->doubleSpinBox_1->value() * PI;
    angles[1] = ui->doubleSpinBox_2->value() * PI;
    angles[2] = ui->doubleSpinBox_3->value() * PI;
    angles[3] = ui->doubleSpinBox_4->value() * PI;
    angles[4] = ui->doubleSpinBox_5->value() * PI;
    angles[5] = ui->doubleSpinBox_6->value() * PI;
    angles[6] = ui->doubleSpinBox_7->value() * PI;
    angles[7] = ui->doubleSpinBox_8->value() * PI;
    angles[8] = ui->doubleSpinBox_9->value() * PI;
    angles[9] = ui->doubleSpinBox_10->value() * PI;
    angles[10] = ui->doubleSpinBox_11->value() * PI;
    angles[11] = ui->doubleSpinBox_12->value() * PI;
    angles[12] = ui->doubleSpinBox_13->value() * PI;
    angles[13] = ui->doubleSpinBox_14->value() * PI;
    angles[14] = ui->doubleSpinBox_15->value() * PI;
    angles[15] = ui->doubleSpinBox_16->value() * PI;

    ui->widget->setAngles(angles);
    int mode = 0;
    if(ui->radioButton_2->isChecked())
        mode = 1;
    if(ui->radioButton_3->isChecked())
        mode = 2;
    ui->widget->setMode(mode);
    ui->widget->redraw();
}
