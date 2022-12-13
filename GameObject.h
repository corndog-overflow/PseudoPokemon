//
// Created by schro on 11/18/2022.
//

#ifndef PA3_CORNDOG_OVERFLOW_GAMEOBJECT_H
#define PA3_CORNDOG_OVERFLOW_GAMEOBJECT_H

#include "Point2D.h"

class GameObject{

protected:
    Point2D location;
    int id_num{};
    char display_code;
    char state{};
public:
    GameObject();
    GameObject(char in_code);
    GameObject(Point2D in_loc, int in_id, char in_code);
    virtual bool Update() = 0;
    virtual bool ShouldBeVisible() = 0;
    Point2D getLocation();
    void DrawSelf(char* ptr);
    int getId();
    char getState();
    virtual void ShowStatus();





};




#endif //PA3_CORNDOG_OVERFLOW_GAMEOBJECT_H
