#include "djoint.h"
#include <QQuaternion>

#include <iostream>
using namespace std;

DJoint::DJoint(float x, float y, float z, float axisx, float axisy, float axisz)
{
    position = new QVector3D(x,y,z);
    defaultPosition = new QVector3D(x,y,z);
    axis = new QVector3D(axisx, axisy, axisz);
    axis->normalize();
    defaultAxis = new QVector3D(axisx, axisy, axisz);
    defaultAxis->normalize();
}

QPoint DJoint::getPoint(int mode)
{
    switch(mode)
    {
    case 1:
        return QPoint(position->x(),position->z());
    case 2:
        return QPoint(position->y(),position->z());
    case 0:
    default:
        return QPoint(position->x(),position->y());
    }
}

QVector3D DJoint::getPosition()
{
    return *position;
}

QVector3D DJoint::getAxis()
{
    return *axis;
}

void DJoint::setPosition(float x, float y, float z)
{
    position = new QVector3D(x,y,z);
}

void DJoint::rotateJoint(float degrees)
{
    rotateJoint(parent, degrees);
}

void DJoint::rotateJoint(DJoint *jointAxis, float degrees)
{
    QQuaternion q = QQuaternion::fromAxisAndAngle(jointAxis->getAxis(), degrees);
    for (std::set<DJoint*>::iterator it=children.begin(); it!=children.end(); ++it)
    {
        (*it)->rotateJoint(jointAxis, degrees);
    }
    *axis = q.rotatedVector(*axis);
    *position = q.rotatedVector(*position-*(jointAxis->position));
    *position += *(jointAxis->position);
}

void DJoint::addChildren(DJoint *child)
{
    children.insert(child);
    child->parent = this;
}

void DJoint::resetPosition()
{
    *position = *defaultPosition;
    *axis = *defaultAxis;
}
