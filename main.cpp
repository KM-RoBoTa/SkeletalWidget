#include "dskeleton.h"
#include "projections.h"
#include "snakeviz.h"
#include <QApplication>

#include <iostream>

#define PI 3.14159

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SnakeViz *sv = new SnakeViz();
    sv->show();

    return a.exec();
}
