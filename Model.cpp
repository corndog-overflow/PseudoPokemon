#include "Model.h"

using namespace std;

int t = 0;

Model::Model() {

    gym_ptrs = {new PokemonGym(10, 5, 2, 3, 1, Point2D(0, 0)), new PokemonGym(20, 5, 7.5, 4, 2, Point2D(5, 5))};
    object_ptrs.insert(object_ptrs.begin(), gym_ptrs.begin(), gym_ptrs.end());
    center_ptrs = {new PokemonCenter(1, 1, 100, Point2D(1, 20)), new PokemonCenter(2, 1, 100, Point2D(10, 20))};
    object_ptrs.insert(object_ptrs.begin(), center_ptrs.begin(), center_ptrs.end());
    wild_ptrs = {new WildPokemon("Rapidash", 5, 2, false, 1, Point2D(10, 12)),
                 new WildPokemon("Nidoking", 5, 2, false, 2, Point2D(15, 5))};
    object_ptrs.insert(object_ptrs.begin(), wild_ptrs.begin(), wild_ptrs.end());
    trainer_ptrs = {new Trainer("Ash", 1, 'T', 1, Point2D(5, 1)), new Trainer("Misty", 2, 'T', 2, Point2D(10, 1))};
    object_ptrs.insert(object_ptrs.begin(), trainer_ptrs.begin(), trainer_ptrs.end());
    active_ptrs.insert(active_ptrs.begin(), object_ptrs.begin(), object_ptrs.end());
    cout << "Model default constructed" << endl;

}

Model::~Model() {
    for (auto it = object_ptrs.begin(); it != object_ptrs.end(); ++it) {
        delete *it;
    }
    cout << "Model destructed" << endl;

}

GameObject *Model::GetGameObjectPtr(int id) {
    objitr = next(object_ptrs.begin(), id);
    return *objitr;
}

GameObject *Model::GetActiveGameObjectPtr(int id) {
    objitr = next(active_ptrs.begin(), id);
    return *objitr;
}

PokemonGym *Model::GetPokemonGymPtr(int id) {
    gym_itr = next(gym_ptrs.begin(), id);
    return *gym_itr;
}

PokemonCenter *Model::GetPokemonCenterPtr(int id) {
    center_itr = next(center_ptrs.begin(), id);
    return *center_itr;
}

Trainer *Model::GetTrainerPtr(int id) {
    trainer_itr = next(trainer_ptrs.begin(), id);
    return *trainer_itr;
}

WildPokemon *Model::GetWildPokemonPtr(int id) {

    wpitr = next(wild_ptrs.begin(), id);
    return *wpitr;

}

bool Model::IsValidId(int id, char c) {
    for (int i = 0; i < object_ptrs.size(); i++) {
        if (GetGameObjectPtr(i)->getId() == id &&
            tolower(GetGameObjectPtr(i)->getCode(), locale()) == tolower(c, locale())) {
            return true;
        }
    }
    return false;
}


bool Model::Update() {
    t++;//inc time
    int num_gyms_defeated = 0;
    int trainersDefeated = 0;
    bool test = false;

    for (int i = 0; i < wild_ptrs.size(); i++) {

        for (int j = 0; j < trainer_ptrs.size(); j++) {

            if (GetWildPokemonPtr(i)->getLocation().x == GetTrainerPtr(j)->getLocation().x &&
                GetWildPokemonPtr(i)->getLocation().y ==
                GetTrainerPtr(j)->getLocation().y) {

                GetWildPokemonPtr(i)->follow(GetTrainerPtr(j));
            }
        }
    }

    for (int i = 0; i < active_ptrs.size(); i++) {

        if (GetActiveGameObjectPtr(i)->Update()) {

            test = true;

        } else {

            test = false;

        }

    }

    for (int i = 0; i < gym_ptrs.size(); i++) {

        if (GetPokemonGymPtr(i)->passed()) {
            GetPokemonGymPtr(i)->setCode('g');
            num_gyms_defeated++;//inc num gyms defeated

        }

    }

    if (num_gyms_defeated >= gym_ptrs.size()) {//if num gyms deafeated is equal to number of gyms to begin with

        cout << "GAME OVER: You win! All battles done!" << endl;
        destructObject();//destructObject
        exit(0);//exit game
    }
    for (int i = 0; i < trainer_ptrs.size(); i++) {
        if (GetTrainerPtr(i)->HasFainted()) {
            trainersDefeated++;

        }

    }
    if (trainersDefeated >= trainer_ptrs.size()) {
        cout << "GAME OVER: You lose! All of your Trainers' pokemon have fainted!" << endl;
        destructObject();
        exit(0);
    }
    for (int i = 0; i < active_ptrs.size(); i++) {
        if (GetActiveGameObjectPtr(i)->getState() == FAINTED) {
            objitr = next(active_ptrs.begin(), i);
            cout << "Removing fainted " << GetActiveGameObjectPtr(i)->getId() << endl;
            active_ptrs.erase(objitr);
        }
    }
    return test;
}

void Model::ShowStatus() {

    for (int i = 0; i < object_ptrs.size(); i++) {
        GetGameObjectPtr(i)->ShowStatus();
    }
}

void Model::destructObject() {
    this->Model::~Model();
}

void Model::Display(View &View) {
    ShowStatus();
    cout << "t: " << t << endl;
    View.Clear();
    for (int i = 0; i < active_ptrs.size(); i++) {
        View.Plot(GetActiveGameObjectPtr(i));
    }
    View.Draw();
}

void Model::NewCommand(char type, int id, Point2D p) {

    switch (type) {

        case ('c'):
            center_ptrs.push_back(new PokemonCenter(id + 1, 1, 100, p));
            center_itr = next(center_ptrs.end(), -1);
            object_ptrs.insert(object_ptrs.end(), center_itr, center_ptrs.end());
            active_ptrs.insert(active_ptrs.end(), center_itr, center_ptrs.end());
            break;

        case ('g'):
            gym_ptrs.push_back(new PokemonGym(10, 1, 2, 3, id + 1, p));
            gym_itr = next(gym_ptrs.end(), -1);
            object_ptrs.insert(object_ptrs.end(), gym_itr, gym_ptrs.end());
            active_ptrs.insert(active_ptrs.end(), gym_itr, gym_ptrs.end());
            break;

        case ('t'):
            trainer_ptrs.push_back(new Trainer("New Trainer!", id + 1, 'T', 2, p));
            trainer_itr = next(trainer_ptrs.end(), -1);
            object_ptrs.insert(object_ptrs.end(), trainer_itr, trainer_ptrs.end());
            active_ptrs.insert(active_ptrs.end(), trainer_itr, trainer_ptrs.end());
            break;

        case ('w'):
            wild_ptrs.push_back(new WildPokemon("New WildPokemon!", 5, 50, false, id + 1, p));
            wpitr = next(wild_ptrs.end(), -1);
            object_ptrs.insert(object_ptrs.end(), wpitr, wild_ptrs.end());
            active_ptrs.insert(active_ptrs.end(), wpitr, wild_ptrs.end());
            break;

        default:
            break;

    }

}
