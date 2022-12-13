//
// Created by schro on 11/25/2022.
//

#ifndef PA3_CORNDOG_OVERFLOW_TRAINER_H
#define PA3_CORNDOG_OVERFLOW_TRAINER_H
#include "GameObject.h"
#include "PokemonGym.h"
#include "PokemonCenter.h"


enum TrainerStates {
    STOPPED = 0,
    MOVING = 1,
    FAINTED = 2,
    AT_CENTER = 3,
    IN_GYM = 4,
    MOVING_TO_CENTER = 5,
    MOVING_TO_GYM = 6,
    BATTLING_IN_GYM = 7,
    RECOVERING_HEALTH = 8
};
class Trainer : public GameObject{
public:
    Trainer();
    Trainer(char in_code);
    Trainer(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc);
    ~Trainer();
    string GetName();
    void StartMoving(Point2D dest);
    void StartMovingToGym(PokemonGym* gym);
    void StartMovingToCenter(PokemonCenter* center);
    void StartBattling(unsigned int num_battles);
    void StartRecoveringHealth(unsigned int num_potions);
    void Stop();
    bool HasFainted();
    bool ShouldBeVisible();
    void ShowStatus();
    char GetCode();
    void ReduceTrainerHealth(double);
    bool Update();
protected:
    bool UpdateLocation();
    void SetupDestination(Point2D dest);
private:
    double speed;
    bool is_IN_GYM = false;
    bool is_at_center = false;
    unsigned int health;
    unsigned int experience;
    double PokeDollars;
    unsigned int battles_to_buy;
    unsigned int potions_to_buy;
    string name;
    PokemonCenter* current_center = NULL;
    PokemonGym* current_gym = NULL;
    Point2D destination;
    Vector2D delta;


};

static double GetRandomAmountOfPokeDollars();


#endif //PA3_CORNDOG_OVERFLOW_TRAINER_H
