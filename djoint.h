#ifndef DJOINT_H
#define DJOINT_H

#include <QVector3D>
#include <QPoint>
#include <set>

class DJoint
{
public:
    DJoint(float x, float y, float z, float axisx, float axisy, float axisz);
    void setPosition(float x, float y, float z);
    QVector3D getPosition();
    QVector3D getAxis();
    void rotateJoint(float degrees);
    void rotateJoint(DJoint *jointAxis, float degrees);
    QPoint getPoint(int mode = 0);
    void addChildren(DJoint* child);
    void resetPosition();

private:
    QVector3D* position;
    QVector3D* axis;
    QVector3D* defaultPosition;
    QVector3D* defaultAxis;
    std::set<DJoint*> children;
    DJoint* parent;
};

#endif // DJOINT_H
