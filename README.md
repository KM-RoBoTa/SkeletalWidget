# Skeletal Widget
_**To create the skeletal framework of robotic systems for visualization and graphics**_

This program offers:
- DSkeleton and DJoint classes, which serves as the basis for creating the skeletal framework, which may be subsequently used in robotic visualization
- A preliminary interface for the visualization of a 16-DOF snake robot (based on Lola-OP), projected on XY/XZ/YZ planes (note: the z-ordering of the nodes [DJoints] may not be accurate)

The rotation within DSkeleton/DJoint is performed using quaternions (with translation) through the Qt framework.