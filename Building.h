#ifndef BUILDING_H
#define BUILDING_H
#include <iostream>
#include "GameObject.h"

using namespace std;

class Building : public GameObject {
private:
    unsigned int trainer_count = 0;

public:
    Building();
    void ShowStatus();
    bool ShouldBeVisible();
    double GetTrainerCount();
    bool Update();
    Building(char in_code, int in_Id, Point2D in_loc);
    void AddOneTrainer();
    void RemoveOneTrainer();
    ~Building();
};

#endif
