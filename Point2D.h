//
// Created by schro on 11/18/2022.
//

#ifndef PA3_CORNDOG_OVERFLOW_POINT2D_H
#define PA3_CORNDOG_OVERFLOW_POINT2D_H
#include "Vector2D.h"
#include <iostream>
#include "ostream"
using namespace std;


class Vector2D;

class Point2D{

public:
    double x;
    double y;
    Point2D();
    Point2D(double, double);
};

double GetDistanceBetween(Point2D p1, Point2D p2);

Point2D operator+(Point2D p1, Vector2D v1);

ostream & operator<<(ostream& out, Point2D p1);

Vector2D operator-(Point2D p1, Point2D p2);

#endif //PA3_CORNDOG_OVERFLOW_POINT2D_H
