//
// Created by schro on 11/18/2022.
//
#ifndef PA3_CORNDOG_OVERFLOW_POKEMONCENTER_H
#define PA3_CORNDOG_OVERFLOW_POKEMONCENTER_H
#include "Building.h"


enum PokemonCenterStates
{
    POTIONS_AVAILABLE = 0,
    NO_POTIONS_AVAILABLE = 1
};

class PokemonCenter: public Building
{
private:
    unsigned int potion_capacity;
    unsigned int num_potions_remaining;
    double pokedollar_cost_per_potion;
public:
    PokemonCenter();
    PokemonCenter(int in_id, double potion_cost, unsigned int potion_cap, Point2D in_loc);
    ~PokemonCenter();
    bool hasPotions();
    unsigned int getNumPotionsRemaining();
    bool canAffordPotions(unsigned int potions, double budget);
    double GetPokeDollarCost(unsigned int potions);
    unsigned int DistributePotion(unsigned int points_needed);
    bool Update();
    void ShowStatus();
};

#endif //PA3_CORNDOG_OVERFLOW_POKEMONCENTER_H
