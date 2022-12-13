#include <iostream>
#include "PokemonCenter.h"

using namespace std;

PokemonCenter::PokemonCenter()
        :Building() {

    displayCode = 'C';
    potionsCap = 100;
    numPotionsRemaining = potionsCap;
    pkDollarCostPerPotion = 5;

    GameObject::state = POTIONS_AVAILABLE;
    cout << "PokemonCenter default constructed" << endl;

}

PokemonCenter::PokemonCenter(int in_id, double potion_cost, unsigned int potion_cap, Point2D in_loc)
        :Building('C', in_id, in_loc) {

    pkDollarCostPerPotion = potion_cost;
    potionsCap = potion_cap;
    numPotionsRemaining = potionsCap;

    GameObject::state = POTIONS_AVAILABLE;
    cout << "Building constructed" << endl;

}

bool PokemonCenter::HasPotions() {

    if (numPotionsRemaining > 0) {

        return true;

    }

    else {

        return false;

    }

}

unsigned int PokemonCenter::GetNumPotionRemaining() {

    return numPotionsRemaining;

}

bool PokemonCenter::CanAffordPotion(unsigned int potion, double budget) {

    if (pkDollarCostPerPotion * potion <= budget) {

        return true;

    }

    else {

        return false;

    }

}

double PokemonCenter::GetPokeDollarCost(unsigned int potion) {

    return potion * pkDollarCostPerPotion;

}

unsigned int PokemonCenter::DistributePotion(unsigned int potion_needed) {

    if (numPotionsRemaining >= potion_needed) {

        numPotionsRemaining = numPotionsRemaining - potion_needed;
        return potion_needed;

    }

    else {

        potion_needed = numPotionsRemaining;
        numPotionsRemaining = 0;
        return potion_needed;

    }

}

bool PokemonCenter::Update() {

    if (state == POTIONS_AVAILABLE) {

        if (numPotionsRemaining == 0) {

            GameObject::state = NO_POTIONS_AVAILABLE;
            GameObject::displayCode = 'c';

            cout << "PokemonCenter: " << getId() << " has ran out of potions!" << endl;
            return true;

        }

        else {

            GameObject::state = POTIONS_AVAILABLE;
            return false;

        }

    }

    return false;

}

void PokemonCenter::ShowStatus() {

    cout << "PokemonCenter Status: " << endl;
    Building::ShowStatus();
    cout << "PokeDollars per potion: " << pkDollarCostPerPotion << endl;
    cout << "has " << numPotionsRemaining << " potion(s) remaining\n" << endl;

}

PokemonCenter::~PokemonCenter() {

    cout << "PokemonCneter Destructed" << endl;

}

bool PokemonCenter::ShouldBeVisible() {

    return true;

}


