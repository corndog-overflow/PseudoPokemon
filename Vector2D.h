//
// Created by schro on 11/20/2022.
//

#ifndef PA3_CORNDOG_OVERFLOW_VECTOR2D_H
#define PA3_CORNDOG_OVERFLOW_VECTOR2D_H
#include <iostream>


class Point2D;
class Vector2D {
public:
    double x;
    double y;
    Vector2D();
    Vector2D(double, double);
};


Vector2D operator*(Vector2D v1, double x);

Vector2D operator/(Vector2D v1, double x);

std::ostream& operator<<(std::ostream& o, Vector2D v1);


#endif //PA3_CORNDOG_OVERFLOW_VECTOR2D_H
