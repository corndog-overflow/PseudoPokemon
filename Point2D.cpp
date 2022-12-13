//
// Created by schro on 11/18/2022.
//

#include "Point2D.h"
#include "Vector2D.h"
#include <cmath>
#include <iostream>

using namespace std;

Point2D::Point2D()
{
    x = 0;
    y = 0;
}

Point2D::Point2D(double in_x, double in_y)
{
    x = in_x;
    y = in_y;
}

double GetDistanceBetween(Point2D p1, Point2D p2){
    double d = 0;
    double a = p1.x - p2.x;
    double b = p1.y - p2.y;

    a = pow(a,2);
    b = pow(b,2);

    d = a+b;
    d = sqrt(d);

    return d;

}

ostream& operator<<(ostream& print, Point2D p1)
{
    print << "(" << p1.x << "," << p1.y << " )";

    return print;
}


Point2D operator+(Point2D p1, Vector2D v1)
{
    Point2D pos = Point2D();
    pos.x = p1.x + v1.x;
    pos.y = p1.y + v1.y;

    return pos;
}

Vector2D operator-(Point2D p1, Point2D p2)
{
    Vector2D vec = Vector2D();
    vec.x = p1.x - p2.x;
    vec.y = p1.y - p2.y;

    return vec;
}