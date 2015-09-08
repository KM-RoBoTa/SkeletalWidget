#ifndef DSKELETON_H
#define DSKELETON_H

#include <vector>

#include "djoint.h"

class DSkeleton
{

public:
    DSkeleton(int numDOFSnake);
    ~DSkeleton();
    void setAngles(std::vector<double> input);
    void setMode(int input);
    std::vector<QPoint> getPoints();

private:
    int numJoints;

    std::vector<double> angles;
    std::vector<DJoint*> allJoints;
    std::vector<DJoint*> defaultPosition;

    int mode;
};

#endif // DSkeleton_H
