//
// Created by schro on 11/18/2022.
//

#include "PokemonCenter.h"


PokemonCenter::PokemonCenter()
{
    this -> num_potions_remaining = potion_capacity;
    this -> pokedollar_cost_per_potion = 5;
    this -> state = POTIONS_AVAILABLE;
    this -> display_code = 'C';
    this -> potion_capacity = 100;
    cout << "PokemonCenter default constructed"<< endl;
}

PokemonCenter::PokemonCenter(int in_id, double potion_cost, unsigned int potion_cap, Point2D in_loc)
{
    this -> pokedollar_cost_per_potion = potion_cost;
    this -> potion_capacity = potion_cap;
    this -> num_potions_remaining = potion_capacity;
    this -> display_code = 'C';
    this -> id_num = in_id;
    this -> location = in_loc;
    this -> state = POTIONS_AVAILABLE;
    cout << "PokemonCenter constructed"<< endl;
}

PokemonCenter::~PokemonCenter()
{
    cout << "PokemonCenter Destroyed." << endl;
}

bool PokemonCenter::canAffordPotions(unsigned int potions, double budget)
{
    if(budget - (potions * (this -> pokedollar_cost_per_potion)) >= 0)
        return true;
    else
        return false;
}

double PokemonCenter::GetPokeDollarCost(unsigned int potions)
{
    return ((this -> pokedollar_cost_per_potion) * potions);
}
bool PokemonCenter::hasPotions()
{
    if((this -> num_potions_remaining >= 1 ))
        return true;
    else
        return false;
}

unsigned int PokemonCenter::getNumPotionsRemaining()
{
    return this -> num_potions_remaining;
}


void PokemonCenter::ShowStatus()
{
    cout << "PokemonCenter "<<this->getId()<<" status: \n";
    Building::ShowStatus();
    cout << "\t PokeDollars per potion: " << this -> pokedollar_cost_per_potion << endl;
    cout << "\t has " << this -> num_potions_remaining << " potions left: " << endl;

}


unsigned int PokemonCenter::DistributePotion(unsigned int points_needed)
{
    unsigned int KD = 0;

    if((this -> num_potions_remaining) >= points_needed)
    {
        (this -> num_potions_remaining) -= points_needed;
        KD = points_needed;
    }
    else if(num_potions_remaining < points_needed)
    {
        KD = (this -> num_potions_remaining);
        num_potions_remaining = 0;
    }

    return KD;
}



bool PokemonCenter::Update()
{
    bool val;
    if(this -> num_potions_remaining == 0)
    {
        this -> state = NO_POTIONS_AVAILABLE;
        this -> display_code = 'c';
        cout << "PokemonCenter" << this -> id_num << " has ran out of stamina points." << endl;
        val = true;
    }
    else if (this -> num_potions_remaining > 0){
        val = false;
    }

    return val;
}

