#include "GameObject.h"

using namespace std;


GameObject::GameObject(char in_code){
    state = 0;
    displayCode = in_code;
    id_num = 1;
    cout << "GameObject Constructed";


}

GameObject::GameObject(Point2D in_loc, int in_id, char in_code) {
    state = 0;
    displayCode = in_code;
    id_num = in_id;
    location = in_loc;
    cout << "GameObject Constructed";


}

Point2D GameObject::getLocation() {
    return location;
}

int GameObject::getId() {
    return id_num;
}

char GameObject::getState() {
    return state;
}

char GameObject::getCode() {
    return displayCode;
}

void GameObject::DrawSelf(char *ptr) {
    *ptr = displayCode;
    *(ptr+1) = ('0' + id_num);
}

void GameObject::ShowStatus() {
    cout << displayCode << " " << id_num << " at " << location << endl;
}

GameObject::~GameObject() {
    cout << "GameObject Destructed" << endl;
}
