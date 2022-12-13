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
    list<GameObject*>::iterator objitr;
    list<Trainer*> trainer_ptrs;
    list<Trainer*>::iterator trainer_itr;
    list<PokemonGym*> gym_ptrs;
    list<PokemonGym*>::iterator gym_itr;
    list<PokemonCenter*> center_ptrs;
    list<PokemonCenter*>::iterator center_itr;
    list<WildPokemon*> wild_ptrs;
    list<WildPokemon*>::iterator wpitr;

public:
    Model();
    ~Model();
    GameObject* getGameObjPtr(int id);
    GameObject* getActvGameObjPtr(int id);
    Trainer* GetTrainerPtr(int d);
    PokemonCenter* GetPokemonCenterPtr(int id);
    PokemonGym* GetPokemonGymPtr(int id);
    WildPokemon* GetWildPokemonPtr(int id);
    bool Update();
    void Display(View& view);
    void ShowStatus();
    bool IsValidId(int id, char c);
    void destructObject();
    void NewCommand(char type, int id, Point2D p);




};


#endif //PA3_CORNDOG_OVERFLOW_MODEL_H
