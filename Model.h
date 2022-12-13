//
// Created by schro on 11/18/2022.
//

#ifndef PA3_CORNDOG_OVERFLOW_MODEL_H
#define PA3_CORNDOG_OVERFLOW_MODEL_H

#include <list>
#include "GameObject.h"
#include "Trainer.h"
#include "View.h"
#include "map"
#include "WildPokemon.h"

class Model {

private:
    Model(const Model&);
    list<GameObject*> object_ptrs;
    list<GameObject*> active_ptrs;
    list<GameObject*>::iterator objecti;

    list<Trainer*> trainer_ptrs;
    list<Trainer*>::iterator traineri;

    list<PokemonGym*> gym_ptrs;
    list<PokemonGym*>::iterator gymi;

    list<PokemonCenter*> center_ptrs;
    list<PokemonCenter*>::iterator centeri;

    list<WildPokemon*> wild_ptrs;
    list<WildPokemon*>::iterator wildpokemoni;
//    int time;
//    GameObject* object_ptrs[10];
//    int num_objects;
//    Trainer* trainer_ptrs[10];
//    int num_trainers;
//    PokemonCenter* center_ptrs[10];
//    int num_centers;
//    PokemonGym* gym_ptrs[10];
//    int num_gyms;
public:
    Model();
    ~Model();
    GameObject* GetGameObjectPtr(int id);

    GameObject* GetActiveGameObjectPtr(int id);
    Trainer* GetTrainerPtr(int d);
    PokemonCenter* GetPokemonCenterPtr(int id);
    PokemonGym* GetPokemonGymPtr(int id);
    WildPokemon* GetWildPokemonPtr(int id);
    bool Update();
    void Display(View& view);
    void ShowStatus();
    bool IsValidId(int id, char c);
    void destroy();
    void NewCommand(char type, int id, Point2D p);




};


#endif //PA3_CORNDOG_OVERFLOW_MODEL_H
