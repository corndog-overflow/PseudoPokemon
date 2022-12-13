#include "Trainer.h"
#include <time.h>
#include <cmath>

using namespace std;

Trainer::Trainer()
        :GameObject('T') {

    speed = 5;
    cout << "Trainer default constructed" << endl;

}

Trainer::Trainer(char in_code)
        :GameObject(in_code) {

    speed = 5;
    state = STOPPED;
    cout << "Trainer constructed" << endl;

}

Trainer::Trainer(std::string in_name,int in_id,char in_code,unsigned int in_speed, Point2D in_loc)
        :GameObject(in_loc, in_id, in_code) {

    speed = in_speed;
    name = in_name;
    //  cout << "ID: " << getId() << endl;
    cout << "Trainer constructed" << endl;

}

void Trainer::ReduceTrainerHealth(double attack) {

    health -= attack;

}

static double GetRandomAmountOfPokeDollars() {

    double f = (double) (rand()%3);
    return f;

}

Point2D Trainer::getLocation() {

    return location;

}

string Trainer::GetName() {

    return name;

}

PokemonGym* Trainer::GetCurrentGym() {

    return current_gym;

}

PokemonCenter* Trainer::GetCurrentCenter() {

    return current_center;

}

Point2D Trainer::GetDestination() {

    return destination;

}

Trainer::~Trainer() {

    cout << "Trainer Destructed" << endl;

}


bool Trainer::UpdateLocation() {

    Vector2D current_dist  = destination - location;

    if (location.x == destination.x &&  location.y == destination.y) {

        cout << displayCode << " " << getId() << ": I'm there!" << endl;
        return true;

    }

    if (fabs(current_dist.x) <= fabs(delta.x) && location.x != destination.x) {

        location.x = destination.x;

    }

    else {

        location.x = location.x + delta.x;

    }

    if (fabs(current_dist.y) <= fabs(delta.y) && location.y != destination.y) {

        location.y = destination.y;

    }

    else {

        location.y = location.y + delta.y;

    }

    cout << displayCode << " " << getId() << ": step..." << endl;
    return false;

}

void Trainer::SetupDestination(Point2D dest) {

    destination = dest;
    delta = (destination - location) * (speed / GetDistanceBetween(destination, location));

}

void Trainer::StartMoving(Point2D dest) {

    SetupDestination(dest);

    if (location.x == dest.x && location.y == dest.y) {

        cout << displayCode << " " << getId() << ": I’m already there. See?" << endl;

    }

    else if (state == FAINTED) {

        cout << "(" << name << "): " << " is out of health and can't move" << endl;

    }

    else {

        if (state == IN_GYM) {

            current_gym->RemoveOneTrainer();

        }

        if (state == AT_CENTER) {

            current_center->RemoveOneTrainer();

        }

        state = MOVING;
        cout << displayCode << " " << getId() << " " << " On my way." << endl;

    }

}

void Trainer::StartMovingToGym(PokemonGym * gym) {

    Point2D dest = (*gym).getLocation();

    if (state == IN_GYM) {

        current_gym->RemoveOneTrainer();

    }

    if (state == AT_CENTER) {

        current_center->RemoveOneTrainer();

    }

    SetupDestination(dest);
    current_gym = gym;

    if (location.x == dest.x && location.y == dest.y) {

        cout << displayCode << " " << getId() << ": I’m already at the PokemonGym!" << endl;

    }

    else if (state == FAINTED) {

        cout << "(" << name << "): " << " is out of health and can't move" << endl;

    }

    else {

        state = MOVING_TO_GYM;
        cout << displayCode << " " << getId() << ": On my way to gym" << (*gym).getId() <<""<< endl;

    }

}

void Trainer::StartMovingToCenter(PokemonCenter* center) {

    Point2D dest = (*center).getLocation();

    if (state == IN_GYM) {

        current_gym->RemoveOneTrainer();

    }

    if (state == AT_CENTER) {

        current_center->RemoveOneTrainer();

    }

    current_center = center;
    SetupDestination(dest);

    if (location.x == dest.x && location.y == dest.y) {

        cout << "(" << displayCode << "): " << " I’m already at Center: "<<(*center).getId() << endl;

    }

    else if (state == FAINTED) {

        cout << "(" << name << "): " << " is out of health and can't move " << endl;

    }

    else {

        state = MOVING_TO_CENTER;
        cout << "(" << displayCode << "): " << " On my way to Center:" << (*center).getId() << "" << endl;

    }

}

bool Trainer::HasFainted() {

    if (health == 0) {

        return true;

    }

    return false;

}

bool Trainer::ShouldBeVisible() {

    if (state == FAINTED) {

        return false;

    }

    return true;

}

void Trainer::StartBattling(unsigned int num_battles) {



    if (HasFainted()) {

        cout << displayCode << id_num << ": " << "My Pokemon have fainted so no more battles for me..." << endl;
    }
    if (state != IN_GYM) {

        cout << displayCode << id_num << ": " << "I can only battle in a PokemonGym!" << endl;
    }
    else if (PokeDollars < (*current_gym).GetPokeDollarCost(num_battles)) {
        cout << displayCode << id_num << ": " << "Not enough money for battles!" << endl;
    }
    else if((*current_gym).passed()) {
        cout << displayCode << id_num << ": " << "Cannot battle! This PokemonGym has no more trainers to battle!" << endl;
    }
    else {
        if (num_battles > (*current_gym).GetNumBattlesRemaining()) {
            num_battles = (*current_gym).GetNumBattlesRemaining();
        }
        state = BATTLING_IN_GYM;
        battles_to_buy = num_battles;
        cout << displayCode << id_num << ": " << "started battling at PokemonGym " << (*current_gym).getId() << " with " << (*current_gym).GetNumBattlesRemaining();
        cout << " battles!" << endl;

    }

}

void Trainer::ShowStatus() {

    cout << name << " status: " << endl;
    GameObject::ShowStatus();

    //  cout << name << " status:" << endl;
    cout << "Health: " << health << endl;
    cout << "PokeDollars: " << PokeDollars << endl;
    cout << "Experience: " << experience << endl;

    switch(state) {

        case (STOPPED):

            cout << " stopped\n" << endl;
            break;

        case (MOVING):

            cout << " moving at a speed of " << speed << " to destination " << destination << " at each step of delta " << delta << ".\n" << endl;
            break;

        case (MOVING_TO_GYM):

            cout << " heading to Gym" << (*current_gym).getId() << " at a speed of " << speed << " at each step of " << delta << ".\n" << endl;
            break;

        case (MOVING_TO_CENTER):

            cout << " heading to PokemonCenter " << (*current_center).getId() << " at a speed of " << speed << " at each step of " << delta << ".\n" << endl;
            break;

        case (IN_GYM):

            cout << " inside Gym" << (*current_gym).getId() << ".\n" << endl;
            break;

        case (AT_CENTER):

            cout << " inside PokemonCenter " << (*current_center).getId() << ".\n" << endl;
            break;

        case (BATTLING_IN_GYM):

            cout << " battling in PokemonGym " << (*current_gym).getId() << ".\n" << endl;
            break;

        case (RECOVERING_HEALTH):

            cout << " recovering health in PokemonCenter " << (*current_center).getId() << ".\n" << endl;
            break;

        case (FAINTED):

            cout << name << ": " << " is out of health and can't move!\n" << endl;
            break;

        default:

            break;

    }

}

bool Trainer::Update() {

    unsigned int exp;
    unsigned int healpoints;
    unsigned int health_loss;
    bool flag;

    switch(state) {

        case (STOPPED):

            flag = false;
            return false;

        case ( MOVING):
            health -= 1;
            if (health == 0) {
                state = FAINTED;
            }
            PokeDollars += GetRandomAmountOfPokeDollars();
            if (UpdateLocation()) {

                state = STOPPED;

                flag = true;
                return true;

            }

            break;

        case (MOVING_TO_GYM):

            health -= 1;

            if (health == 0) {

                state = FAINTED;

            }

            PokeDollars += GetRandomAmountOfPokeDollars();

            if (UpdateLocation()) {

                state = IN_GYM;
                current_gym->AddOneTrainer();

                flag = true;
                return true;

            }

            break;

        case (MOVING_TO_CENTER):
            health -= 1;
            PokeDollars += GetRandomAmountOfPokeDollars();

            if (health == 0) {

                state = FAINTED;

            }

            if (UpdateLocation()) {

                state = AT_CENTER;
                current_center->AddOneTrainer();

                return true;

            }

            break;

        case (IN_GYM):
            return false;


        case (AT_CENTER):

            return false;

        case (BATTLING_IN_GYM):
            

            health_loss = (*current_gym).GetHealthCostPerBattle(battles_to_buy);

            if (health_loss > health) {

                health = 0;

            }

            else {

                health = health - health_loss;

            }

            PokeDollars -=(*current_gym).GetPokeDollarCost(battles_to_buy);
            exp = (*current_gym).TrainPokemon(battles_to_buy);

            experience += exp;

            cout << "**" << name << " completed " << battles_to_buy << " battle(s)!**" << endl;
            cout << "**" << name << " gained " << exp << " experience!**" << endl;

            state = IN_GYM;

            if(health == 0) {

                state = FAINTED;

            }

            flag = true;
            return true;


        case ( RECOVERING_HEALTH):
            healpoints = 5 * potions_to_buy;
            
            health += healpoints;
            PokeDollars -= (*current_center).GetPokeDollarCost(potions_to_buy);
            potions_to_buy = (*current_center).DistributePotion(potions_to_buy); // added for fixes

            cout << "**" << name << " recovered " << healpoints << " health!**" << endl;
            cout << "**" << name << " bought " << potions_to_buy << " Potion(s)!**" << endl;

            state = AT_CENTER;
            return true;

    }

    return flag;

}

void Trainer::Stop() {

    state = STOPPED;
    cout << "(" << displayCode << ")(" << id_num << "): Stopping" << endl;

}

void Trainer::StartRecoveringHealth(unsigned int num_potions) {

    if (state != AT_CENTER) {

        cout << displayCode << id_num << ": I can only recover at a Pokemon Center!" << endl;

    }

    else if (PokeDollars < (*current_center).GetPokeDollarCost(num_potions)) {

        cout << displayCode << id_num << ": Not enough money to recover health." << endl;

    }

    else if (current_center->GetNumPotionRemaining() < 1) {

        cout << displayCode << id_num << ": Cannot recover! No potion remaining in this Pokemon Center" << endl;

    }

    else {

        if (num_potions > (*current_center).GetNumPotionRemaining()) {

            num_potions = (*current_center).GetNumPotionRemaining();

        }

        state = RECOVERING_HEALTH;
        cout << displayCode << id_num << ": " << "Started recovering " << num_potions << " potions at Pokemon Center " << current_center->getId() << " " << endl;
        potions_to_buy = num_potions;

    }

}

