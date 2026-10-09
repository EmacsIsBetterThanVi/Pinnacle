#ifndef ANGLE_H
#include <math.h>
#define ANGLE_H
const double PI = 3.141592653587932384;
inline double radToDeg(double radians) {return 180*radians/PI}
inline double degToRad(double degrees) {return degrees*PI/180}
#endif