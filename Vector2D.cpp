//
// Created by schro on 11/20/2022.
//

#include "Vector2D.h"
#include <iostream>
Vector2D::Vector2D() {
    x=0;
    y=0;
}

Vector2D::Vector2D(double in_x, double in_y) {
    x = in_x;
    y = in_y;
}

Vector2D operator*(Vector2D v1, double x)
{
    Vector2D vec;

    vec.x = v1.x * x;
    vec.y = v1.y * x;

    return vec;
}


Vector2D operator/(Vector2D v1, double x)
{
    if(x==0)
    {
        v1.x = v1.x;
        v1.y = v1.y;
        return v1;
    }
    else
    {
        Vector2D vec;
        vec.x = v1.x / x;
        vec.y = v1.y / x;
        return vec;
    }

}

std::ostream& operator<<(std::ostream & o, Vector2D v1)
{
    o <<  "<" << v1.x << ", " << v1.y << ">";
    return o;
}

