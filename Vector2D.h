#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <iostream>
#include "Point2D.h"

using namespace std;

class Vector2D {
public:
    double x;
    double y;

    Vector2D();

    Vector2D(double in_x, double in_y);

    friend ostream& operator<< (ostream & os, Vector2D vc);
};

ostream& operator<< (ostream & os, const Vector2D vc);

Vector2D operator* (Vector2D v1, double d);

Vector2D operator/ (Vector2D v1, double d);

#endif
