#ifndef POKEMONGYM_H
#define POKEMONGYM_H
#include <iostream>
#include "Building.h"

using namespace std;

class PokemonGym: public Building{

    enum PokemonGymStates
    {
        NOT_DEFEATED = 0,
        DEFEATED = 1,
    };

private:
    unsigned int numBattlesRemaining;
    unsigned int maxBattles;
    unsigned int health_cost_per_battle;
    double PokeDollar_cost_per_battle;
    unsigned int XP_perBattle;

public:
    PokemonGym();
    PokemonGym(unsigned int maxBattles, unsigned int healthCost, double pkDollarCost, unsigned int XP, int in_id, Point2D loc);
    bool HasPotions();
    unsigned int GetHealthCostPerBattle(unsigned int numBattles);
    unsigned int GetNumBattlesRemaining();
    bool IsAbleToBattle(unsigned int numBattles, double budget, unsigned int health);
    double GetPokeDollarCost(unsigned int numBattles);
    unsigned int TrainPokemon(unsigned int battle_units);
    void setCode(char c);
    bool ShouldBeVisible();
    bool Update();
    bool passed();
    void ShowStatus();
    ~PokemonGym();

};


#endif
