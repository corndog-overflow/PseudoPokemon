//
// Created by schro on 11/18/2022.
//

#ifndef PA3_CORNDOG_OVERFLOW_BUILDING_H
#define PA3_CORNDOG_OVERFLOW_BUILDING_H

#include "GameObject.h"


class Building: public GameObject{

private:
    unsigned int trainer_count = 0;
public:
    void AddOneTrainer();
    void RemoveOneTrainer();
    void ShowStatus();
    bool ShouldBeVisible();
    Building();
    Building(char in_code, int in_id, Point2D in_loc);


};

#endif //PA3_CORNDOG_OVERFLOW_BUILDING_H
