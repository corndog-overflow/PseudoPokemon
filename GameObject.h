#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <iostream>
#include "Point2D.h"
#include "Vector2D.h"
using namespace std;


class GameObject {
protected:
    Point2D location;
    int id_num;
    char displayCode;
    char state;

public:
    GameObject(char in_code);
    GameObject(Point2D in_loc, int in_id, char in_code);
    Point2D getLocation();
    int getId();
    char getState();
    char getCode();
    virtual void ShowStatus();
    void DrawSelf(char * ptr);
    virtual bool Update() = 0;
    virtual bool ShouldBeVisible() = 0;
    virtual ~GameObject();

};

#endif
