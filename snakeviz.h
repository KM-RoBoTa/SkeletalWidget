#ifndef SNAKEVIZ_H
#define SNAKEVIZ_H

#include <QWidget>

namespace Ui {
class SnakeViz;
}

class SnakeViz : public QWidget
{
    Q_OBJECT

public:
    explicit SnakeViz(QWidget *parent = 0);
    ~SnakeViz();

private slots:
    void refresh();

private:
    Ui::SnakeViz *ui;
};

#endif // SNAKEVIZ_H
