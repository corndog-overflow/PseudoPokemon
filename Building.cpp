//
// Created by schro on 11/18/2022.
//
#include "Building.h"

Building::Building()
{
    display_code = 'B';
    cout << "Building default constructed." << endl;
}

Building::Building(char in_code, int in_id, Point2D in_loc)
{
    id_num = in_id;
    location = in_loc;
    display_code = in_code;
    cout << "Building constructed.";
}

void Building::RemoveOneTrainer()
{
    trainer_count = trainer_count-1;
}

void Building::AddOneTrainer()
{
    trainer_count = trainer_count+1;
}

bool Building::ShouldBeVisible()
{
    return true;
}

void Building::ShowStatus(){
    if(trainer_count == 1)
        cout << "\t" << this -> trainer_count << "TRAINER IS IN HERE!" << endl;
    else if (trainer_count > 1)
        cout << "\t" << this -> trainer_count << "TRAINERS ARE IN HERE!" << endl;
}
