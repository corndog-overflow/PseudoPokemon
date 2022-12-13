#include "PokemonGym.h"

using namespace std;

PokemonGym::PokemonGym():Building() {
    health_cost_per_battle = 1;
    PokeDollar_cost_per_battle = 1;
    XP_perBattle = 2;
    displayCode = 'G';
    maxBattles = 10;
    numBattlesRemaining = maxBattles;
    GameObject::state = NOT_DEFEATED;
    cout << "PokemonGym default constructed" << endl;

}

PokemonGym::PokemonGym(unsigned int maxBattles, unsigned int healthCost, double pkDollarCost, unsigned int XP, int in_id, Point2D loc)
        :Building('G', in_id, loc) {
    health_cost_per_battle = healthCost;
    PokeDollar_cost_per_battle = pkDollarCost;
    XP_perBattle = XP;
    maxBattles = maxBattles;
    numBattlesRemaining = maxBattles;
    GameObject::state = NOT_DEFEATED;
    cout << "PokemonGym constructed" << endl;

}


bool PokemonGym::IsAbleToBattle(unsigned int numBattles, double budget, unsigned int health) {
    if (numBattles * PokeDollar_cost_per_battle <= budget && health_cost_per_battle * numBattles <= health) {
        return true;
    }
    return false;

}

unsigned int PokemonGym::TrainPokemon(unsigned int battle_units) {
    unsigned int XP;
    if (numBattlesRemaining >= battle_units) {
        XP = battle_units * XP_perBattle;
        numBattlesRemaining = numBattlesRemaining - battle_units;
        return XP;
    }

    else {
        XP = numBattlesRemaining * XP_perBattle;
        numBattlesRemaining = 0;
        return XP;
    }
}

void PokemonGym::setCode(char c) {
    displayCode = c;
}

bool PokemonGym::passed() {
    if(numBattlesRemaining == 0) {
        return true;
    }
    return false;

}

bool PokemonGym::update() {

    if (state == NOT_DEFEATED) {
        if (numBattlesRemaining == 0) {
            GameObject::state = DEFEATED;
            GameObject::displayCode = 'g';
            cout << "Gym " << displayCode << id_num << "has been beaten!";
            return true;
        }
        else {
            GameObject::state = NOT_DEFEATED;
            return false;
        }
    }
    return false;

}

void PokemonGym::ShowStatus() {
    cout << " " << endl;
    cout << "PokemonGym" << this->getId()<<" status: \n";
    Building::ShowStatus();
    cout << "\n Max number of Battles: " << maxBattles << endl;
    cout << "\n Health cost per Battles: " << health_cost_per_battle << endl;
    cout << "\n PokeDollar per Battle: " << PokeDollar_cost_per_battle << endl;
    cout << "\n Experience per Battle: " << XP_perBattle << endl;
    cout << "\n " << numBattlesRemaining << " Battle(s) are remaining for this PokemonGym. \n" << endl;
}

unsigned int PokemonGym::GetHealthCostPerBattle(unsigned int numBattles) {

    return numBattles * health_cost_per_battle;
}
unsigned int PokemonGym::GetNumBattlesRemaining(){

    return numBattlesRemaining;

}
bool PokemonGym::ShouldBeVisible() {
    return true;
}
double PokemonGym::GetPokeDollarCost(unsigned int numBattles) {

    return numBattles * PokeDollar_cost_per_battle;
}


PokemonGym::~PokemonGym() {

    cout << "PokemonGym Destructed" << endl;

}
