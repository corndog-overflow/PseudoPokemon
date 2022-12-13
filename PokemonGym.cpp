//
// Created by schro on 11/18/2022.
//

#include "PokemonGym.h"

using namespace std;

PokemonGym::PokemonGym() {
    display_code = 'G';
    state = NOT_DEFEATED;
    max_number_of_battles = 10;
    num_battle_remaining = max_number_of_battles;
    health_cost_per_battle = 1;
    PokeDollar_cost_per_battle = 1.0;
    experience_per_battle = 2;
    cout << "PokemonGym default constructed." << endl;
}

PokemonGym::PokemonGym(unsigned int max_battles, unsigned int stamina_cost, double dollar_cost,
                       unsigned int exp_points_per_unit, int in_id, Point2D in_loc) {
    display_code = 'G';
    state = NOT_DEFEATED;
    id_num = in_id;
    max_number_of_battles = max_battles;
    num_battle_remaining = max_number_of_battles;
    health_cost_per_battle = stamina_cost;
    experience_per_battle = exp_points_per_unit;
    PokeDollar_cost_per_battle = dollar_cost;
    location = in_loc;
    cout << "PokemonGym Constructed" << endl;
}

PokemonGym::~PokemonGym() {
    cout << "PokemonGym Destructed." << endl;
}

double PokemonGym::GetPokeDollarCost(unsigned int unit_qty) {
    return (PokeDollar_cost_per_battle * unit_qty);
}

unsigned int PokemonGym::GetHealthCost(unsigned int unit_qty) {
    return (health_cost_per_battle * unit_qty);
}

unsigned int PokemonGym::GetNumBattlesRemaining() {
    return (num_battle_remaining);
}

bool PokemonGym::IsAbleToBattle(unsigned int unit_qty, double budget, unsigned int stamina) {
    if ((budget - (unit_qty * PokeDollar_cost_per_battle) >= 0) && (stamina - (unit_qty * health_cost_per_battle) >= 0)){
        return true;
    }
    else{
        return false;
    }
}

unsigned int PokemonGym::TrainPokemon(unsigned int battles) {
    unsigned int val = 0;

    if (num_battle_remaining >= battles) {
        num_battle_remaining -= battles;
        unsigned int XP = battles * experience_per_battle;
        val = (XP);
    } else if (num_battle_remaining < battles) {
        unsigned int XP = num_battle_remaining * XP;
        val = XP;
    }

    return val;
}

bool PokemonGym::Update() {
    bool val = false;

    if (num_battle_remaining == 0) {
        state = DEFEATED;
        display_code = 'g';
        cout << display_code << " " << id_num << "has been DEFEATED." << endl;
        val = true;
    } else if (num_battle_remaining > 0) {
        val = false;
    }

    return val;
}

bool PokemonGym::passed() {
    bool val = false;

    if (num_battle_remaining == 0)
        val = true;

    return val;
}

void PokemonGym::ShowStatus() {
    cout << " " << endl;
    cout << "PokemonGym" << this->getId()<<" status: \n";
    Building::ShowStatus();
    cout << "\n Max number of Battles: " << max_number_of_battles << endl;
    cout << "\n Health cost per Battles: " << health_cost_per_battle << endl;
    cout << "\n PokeDollar per Battle: " << PokeDollar_cost_per_battle << endl;
    cout << "\n Experience per Battle: " << experience_per_battle << endl;
    cout << "\n " << num_battle_remaining << " Battle(s) are remaining for this PokemonGym." << endl;
}