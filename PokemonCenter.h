#ifndef POKEMONCENTER_H
#define POKEMONCENTER_H
#include <iostream>
#include "Building.h"

using namespace std;

class PokemonCenter : public Building {

private:
    unsigned int potionsCap;
    unsigned int numPotionsRemaining;
    double pkDollarCostPerPotion;

public:
    PokemonCenter();

    PokemonCenter(int in_id, double potion_cost, unsigned int potion_cap, Point2D in_loc);

    bool HasPotions();

    unsigned int GetNumPotionRemaining();

    bool CanAffordPotion(unsigned int potion, double budget);

    double GetPokeDollarCost(unsigned int potion);

    unsigned int DistributePotion(unsigned int potion_needed);

    bool Update();

    void ShowStatus();

    bool ShouldBeVisible();

    ~PokemonCenter();
};

enum PokemonCenterStates {

    POTIONS_AVAILABLE = 0,
    NO_POTIONS_AVAILABLE = 1

};

#endif
