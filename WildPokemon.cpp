//
// Created by schro on 12/12/2022.
//
#include "WildPokemon.h"

using namespace std;

WildPokemon::WildPokemon(string name, double attack, double health, bool var, int id, Point2D in_loc)
        :GameObject(in_loc, id, 'W') {

    this->attack = attack;
    this->health = health;
    this->variant = variant;
    this->name = name;
    state = INGRASS;

    cout << "WildPokemon constructed" << endl;
}
void WildPokemon::follow(Trainer* t) {
    if (state == INGRASS) {
        current_trainer = t;
        state = FOLLOWING_TRAINER;
    }
}
void WildPokemon::ShowStatus() {

    cout << "WildPokemon Status:" << endl;
    GameObject::ShowStatus();

    switch(state) {

        case ((char) DIED):

            cout << displayCode << id_num << ": is dead!" << endl;
            break;

        case ((char) INGRASS):

            cout << displayCode << id_num << ": is in the grass!" << endl;
            break;

        case ((char) FOLLOWING_TRAINER):

            cout << displayCode << id_num << ": is following " << (*current_trainer).GetName() << endl;
            break;
    }

}
double WildPokemon::get_attack() {

    return attack;

}


bool WildPokemon::get_variant() {

    return variant;
}


double WildPokemon::get_health() {

    return health;

}

bool WildPokemon::get_in_combat() {

    if (state == FOLLOWING_TRAINER) {

        in_combat = true;

    }

    else {

        in_combat = false;

    }

    return in_combat;

}

bool WildPokemon::ShouldBeVisible() {
    if (IsAlive() && state == INGRASS) {
        return true;
    }
    else {

        return false;
    }
}

bool WildPokemon::Update() {
    if (state == DIED) {
        in_combat = false;
        return false;
    }
    if (!IsAlive()) {
        state = DIED;
        return true;
    }
    if (state == INGRASS) {
        return false;
    }
    if (state == FOLLOWING_TRAINER) {

        health--;
        current_trainer->ReduceTrainerHealth(attack);
        location = current_trainer->getLocation();
        return true;
    }
    return false;
}


bool WildPokemon::IsAlive() {
    if (health <= 0) {
        state = DIED;
        return false;
    }
    else {
        return true;
    }
}

WildPokemon::~WildPokemon() {
    cout << "WildPokemon Destructed" << endl;
}




