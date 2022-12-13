//
// Created by schro on 11/18/2022.
//

#ifndef PA3_CORNDOG_OVERFLOW_POKEMONGYM_H
#define PA3_CORNDOG_OVERFLOW_POKEMONGYM_H
#include "Building.h"

using namespace std;

enum PokemonGymStates
{
    NOT_DEFEATED = 0,
    DEFEATED = 1,
};

class PokemonGym: public Building
{
private:
    unsigned int num_battle_remaining;
    unsigned int max_number_of_battles;
    unsigned int health_cost_per_battle;
    unsigned int PokeDollar_cost_per_battle;
    unsigned int experience_per_battle;
public:
    PokemonGym();
    PokemonGym(unsigned int max_battles, unsigned int health_cost, double dollar_cost, unsigned int XP, int in_id, Point2D in_loc);
    ~PokemonGym();
    double GetPokeDollarCost(unsigned int);
    unsigned int GetHealthCost(unsigned int);
    unsigned int GetNumBattlesRemaining();
    bool IsAbleToBattle(unsigned int, double, unsigned int);
    unsigned int TrainPokemon(unsigned int);
    bool Update();
    bool passed();
    void ShowStatus();
};

#endif //PA3_CORNDOG_OVERFLOW_POKEMONGYM_H
