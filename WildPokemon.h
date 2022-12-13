//
// Created by schro on 12/12/2022.
//

#ifndef PA3_CORNDOG_OVERFLOW_WILDPOKEMON_H
#define PA3_CORNDOG_OVERFLOW_WILDPOKEMON_H
#ifndef WILDPOKEMON_H
#define WILDPOKEMON_H
#include <iostream>
#include <cmath>
#include <string>
#include "Trainer.h"

using namespace std;

class WildPokemon: public GameObject {

public:
    WildPokemon(string name, double attack, double health, bool variant, int id, Point2D in_loc);

    void follow(Trainer* t);

    bool get_variant();

    double get_attack();

    double get_health();

    bool get_in_combat();

    bool Update();

    void ShowStatus();

    bool ShouldBeVisible();

    bool IsAlive();

    virtual ~WildPokemon();

protected:
    double attack = 5;
    double health = 2;
    bool in_combat = false;
    bool variant = false;
    string name;
    Trainer* current_trainer;

};

enum WildPokemonStates {

    DEAD = 0,
    IN_ENVIRONMENT = 1,
    IN_TRAINER = 2,

};

#endif






#endif //PA3_CORNDOG_OVERFLOW_WILDPOKEMON_H
