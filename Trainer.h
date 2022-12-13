#ifndef TRAINER_H
#define TRAINER_H
#include <iostream>
#include <cmath>
#include "PokemonCenter.h"
#include "PokemonGym.h"

using namespace std;

static double GetRandomAmountOfPokeDollars();

class Trainer: public GameObject{

public:
    Trainer();

    Trainer(char in_code);
    Trainer(std::string in_name,int in_id,char in_code,unsigned int in_speed, Point2D in_loc);
    void StartMoving(Point2D dest);
    void StartMovingToGym(PokemonGym* gym);
    void StartMovingToCenter(PokemonCenter* center);
    void StartBattling(unsigned int num_battles);
    void StartRecoveringHealth(unsigned int num_potions);
    void Stop();
    bool HasFainted();
    bool Update();
    bool ShouldBeVisible();
    void ShowStatus();
    void ReduceTrainerHealth(double);
    string GetName();
    Point2D GetDestination();
    PokemonGym* GetCurrentGym();
    PokemonCenter* GetCurrentCenter();
    Point2D getLocation();
    virtual ~Trainer();
private:
    double speed;
    bool is_at_center = false;
    bool is_IN_GYM = false;
    unsigned int health = 20;
    unsigned int experience = 0;
    double PokeDollars = 0;
    unsigned int battles_to_buy = 0;
    unsigned int potions_to_buy = 0;
    string name;
    PokemonCenter* current_center;
    PokemonGym* current_gym;
    Point2D destination;
    Vector2D delta;

protected:
    bool UpdateLocation();

    void SetupDestination(Point2D dest);

};

enum TrainerStates {

    STOPPED = 0,
    MOVING = 1,
    FAINTED = 2,
    AT_CENTER = 3,
    IN_GYM = 4,
    MOVING_TO_CENTER = 5,
    MOVING_TO_GYM = 6,
    BATTLING_IN_GYM = 7,
    RECOVERING_HEALTH = 8,

};

#endif
