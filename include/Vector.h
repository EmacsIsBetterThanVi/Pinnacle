#ifndef VECTOR_H
#include <math.h>
#include <stdbool.h>
#include <Angle.h>
#define VECTOR_H
typedef struct {
    double theta;
    double mag;
    double x;
    double y;
    } Vector2d;
void Vector2d_update(Vector2d * vec, bool angle){
    if (angle){
        vec->x=cos(vec->theta)*vec->mag;
        vec->y=sin(vec->theta)*vec->mag;
    } else {
        vec->mag=sqrt((vec->x*vec->x)+(vec->y*vec->y));
        vec->theta = atan(vec->x/vec->y);
    }
}
typedef struct {
    double theta;
    double mag;
    double x;
    double y;
    double phi;
    double z;
    } Vector3d;
typedef union {
    Vector2d D2;
    Vector3d D3;
    } Vector;
void Vector3d_update(Vector2d * vec, bool angle){
    if (angle){
        vec->x = vec->mag*sin(vec->phi)*cos(vec->theta);
        vec->y = vec->mag*sin(vec->phi)*sin(vec->theta);
        vec->z = vec->mag*cos(vec->phi);
    } else {
        vec->mag =sqrt((vec->x*vec->x)+(vec->y*vec->y)+(vec->z*vec->z));
        vec->theta = atan(vec->y / vec->x);
        vec->phi = acos(vec->z/vec->mag)
   }
}
#endif