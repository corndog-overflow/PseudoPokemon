#include "Building.h"

using namespace std;

Building::Building()
        :GameObject('B') {

    cout << "Building default constructed" << endl;

}

Building::Building(char in_code, int in_Id, Point2D in_loc)
        :GameObject(in_loc,in_Id,in_code) {

    cout << "Building constructed" << endl;

}

void Building::RemoveOneTrainer()
{
    trainer_count = trainer_count-1;
}

void Building::AddOneTrainer()
{
    trainer_count = trainer_count+1;
}

void Building::ShowStatus() {
    if (trainer_count == 1) {
        cout << displayCode << " " << getId() << ": " << location << endl;
        cout << trainer_count << " trainer is in this building!" << endl;
    }
    else {
        cout << displayCode << " " << getId() << ": " << location << endl;
        cout << trainer_count << " trainers are in this building!" << endl;

    }

}

bool Building::ShouldBeVisible() {
    return true;
}

bool Building::Update() {
    return true;
}


Building::~Building() {
}
