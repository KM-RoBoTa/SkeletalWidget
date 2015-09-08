#include <QVector3D>
#include "djoint.h"
#include "dskeleton.h"

#include <iostream>
using namespace std;

DSkeleton::DSkeleton(int numDOFSnake)
{   
    int shiftx = 20;
    int shifty = 0;
    int shiftz = 0;

    numJoints = numDOFSnake;

    int radiusSnake = shiftx*(numJoints+1);

    int headx = radiusSnake;
    int heady = radiusSnake;
    int headz = radiusSnake;

    DJoint* head = new DJoint(headx,heady,headz,0,0,1);
    allJoints.push_back(head);

    for (int i = 0; i < numJoints; i++)
    {
        // alternate between y and z rotational axis
        int axisy = (i%2 == 0) ? 1 : 0;
        int axisz = (i%2 == 0) ? 0 : 1;
        DJoint* d = new DJoint(headx+shiftx*(i+1),heady+shifty*(i+1),headz+shiftz*(i+1),0,axisy,axisz);
        allJoints[i]->addChildren(d); // For snake, this joint (i+1) is the child of the previous one (i)
        allJoints.push_back(d);
    }

    mode = 0;
    angles = vector<double>(numJoints,0);
}

DSkeleton::~DSkeleton()
{
    for (int i = 0; i < allJoints.size(); i++)
    {
        delete allJoints[i];
    }
}

void DSkeleton::setMode(int input)
{
    mode = input;
}

#define PI 3.14159
void DSkeleton::setAngles(std::vector<double> input)
{
    for (int n = 0; n < allJoints.size(); n++)
    {
        allJoints[n]->resetPosition();
    }
    for (int i = 0; i < input.size(); i++)
    {
        angles[i] = input[i]*180/PI;
        allJoints[i+1]->rotateJoint(angles[i]);

//        cout << i+1 << ":" << allJoints[i+1]->getPosition().x() << "," << allJoints[i+1]->getPosition().y() << "," << allJoints[i+1]->getPosition().z() << endl << endl;
    }
}

vector<QPoint> DSkeleton::getPoints()
{
    vector<QPoint> allPoints;
    for (int i = 0; i < allJoints.size(); i++)
    {
        allPoints.push_back(allJoints[i]->getPoint(mode));
    }
    return allPoints;
}
