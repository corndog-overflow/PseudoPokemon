//
// Created by schro on 11/18/2022.
//
#include "GameObject.h"
#include <iostream>
using namespace std;

GameObject::GameObject() {
    display_code = ' ';
}

GameObject::GameObject(char in_code){
    state = 0;
    display_code = in_code;
    id_num = 1;
    cout << "GameObject Constructed";


}

GameObject::GameObject(Point2D in_loc, int in_id, char in_code) {
    state = 0;
    display_code = in_code;
    id_num = in_id;
    location = in_loc;
    cout << "GameObject Constructed";


}

int GameObject::getId()
{
    return id_num;
}

Point2D GameObject::getLocation()
{
    return location;
}

bool GameObject::Update()
{
    return false;
}
void GameObject::ShowStatus()
{
    cout << this -> display_code << " " << this -> id_num << " at" << this -> location;
}

char GameObject::getState()
{
    return state;
}

void GameObject::DrawSelf(char *ptr) {
    *ptr = display_code;
    *(ptr+1) = ('0' + id_num);

}
