#include <iostream>
#include "Vector2D.h"

using namespace std;

Vector2D :: Vector2D() {
    x = 0;
    y = 0;
}

Vector2D :: Vector2D(double in_x, double in_y) {
    x = in_x;
    y = in_y;
}

ostream& operator<< (ostream & os, Vector2D vc) {
    os << "<" << vc.x << "," << vc.y << ">";
    return os;
}

Vector2D operator* (Vector2D v1, double d) {
    return Vector2D(v1.x * d, v1.y * d);
}

Vector2D operator/ (Vector2D v1, double d) {
    return Vector2D(v1.x / d, v1.y / d);
}
