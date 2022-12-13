//
// Created by schro on 12/12/2022.
//
#include "WildPokemon.h"

using namespace std;

WildPokemon::WildPokemon(string name, double attack, double health, bool variant, int id, Point2D in_loc)
        :GameObject(in_loc, id, 'W') {

    this->name = name;
    this->attack = attack;
    this->health = health;
    this->variant = variant;
    state = IN_ENVIRONMENT;

    cout << "WildPokemon constructed" << endl;
}
void WildPokemon::follow(Trainer* t) {
    if (state == IN_ENVIRONMENT) {
        current_trainer = t;
        state = IN_TRAINER;
    }
}
void WildPokemon::ShowStatus() {

    cout << "WildPokemon Status:" << endl;
    GameObject::ShowStatus();

    switch(state) {

        case ((char) DEAD):

            cout << displayCode << id_num << ": is dead!" << endl;
            break;

        case ((char) IN_ENVIRONMENT):

            cout << displayCode << id_num << ": is in the grass!" << endl;
            break;

        case ((char) IN_TRAINER):

            cout << displayCode << id_num << ": is following " << (*current_trainer).GetName() << endl;
            break;
    }

}


bool WildPokemon::ShouldBeVisible() {
    if (IsAlive() && state == IN_ENVIRONMENT) {
        return true;
    }
    else {

        return false;
    }
}

bool WildPokemon::Update() {
    if (state == DEAD) {
        in_combat = false;
        return false;
    }
    if (!IsAlive()) {
        state = DEAD;
        return true;
    }
    if (state == IN_ENVIRONMENT) {
        return false;
    }
    if (state == IN_TRAINER) {

        health--;
        current_trainer->ReduceTrainerHealth(attack);
        location = current_trainer->getLocation();
        return true;
    }
    return false;
}


bool WildPokemon::IsAlive() {

    if (health <= 0) {

        state = DEAD;
        return false;
    }
    else {

        return true;

    }

}

WildPokemon::~WildPokemon() {
    cout << "WildPokemon Destructed" << endl;
}




