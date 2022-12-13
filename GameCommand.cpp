#include "GameCommand.h"

using namespace std;

void DoMoveCommand(Model & model, int inputID, Point2D destination) {
    cout << "Moving " << (model.GetTrainerPtr(inputID))->GetName() << " to " << destination << endl;
    (model.GetTrainerPtr(inputID))->StartMoving(destination);
    model.Update();
}

void DoMoveToCenterCommand(Model & model, int trainer_id, int center_id) {

    cout << "Moving " << (model.GetTrainerPtr(trainer_id))->GetName()
         << " to PokemonCenter: " << model.GetPokemonCenterPtr(center_id)->getId() << endl;
    (model.GetTrainerPtr(trainer_id))->
    StartMovingToCenter(model.GetPokemonCenterPtr(center_id));
    model.Update();
}

void DoMoveToGymCommand(Model & model, int trainer_id, int gym_id) {

    cout << "Moving " << (model.GetTrainerPtr(trainer_id))->GetName() << " to gym " <<
                                                                                    model.GetPokemonGymPtr(
                                                                                            gym_id)->getId() << endl;
    (model.GetTrainerPtr(trainer_id))->
    StartMovingToGym(model.GetPokemonGymPtr(gym_id));
    model.Update();

}

void DoStopCommand(Model & model, int trainer_id) {

    cout << "Stopping " << (model.GetTrainerPtr(trainer_id))->GetName() << endl;
    (model.GetTrainerPtr(trainer_id))->Stop();
    model.Update();
}

void DoBattleCommand(Model & model, int trainer_id, unsigned int battles) {
    cout << (model.GetTrainerPtr(trainer_id))->GetName() << " is battling" << endl;
    (model.GetTrainerPtr(trainer_id))->StartBattling(battles);
    model.Update();

}

void DoRecoverInCenterCommand(Model & model, int trainer_id, unsigned int potions_needed) {

    cout << (model.GetTrainerPtr(trainer_id))->GetName() << "'s Pokemon's health" << endl;
    (model.GetTrainerPtr(trainer_id))->StartRecoveringHealth(potions_needed);
    model.Update();
}

void DoAdvanceCommand(Model& model, View& view) {

    cout << "Step..." << endl;
    model.Update();
}

void DoRunCommand(Model& model, View& view) {

    int count;
    cout << "Advancing to next event or 5 ticks" << endl;
    for (count = 0; count < 5; count++) {

        model.Update();

    }

}

char get_char() {

    char c;

    if (!(cin >> c) || ((int)c < 97 && (int)c > 122)) {

        throw Invalid_Input("Invalid character");

    }

    return c;

}

unsigned int getUnInt() {
    unsigned int d;
    if (!(cin >> d)) {//if not expected variety
        throw Invalid_Input("Expecting integer");

    }
    return d;

}

int getInteger() {
    int w;
    if (!(cin >> w) || w < 0) {//cant take negatives
        throw Invalid_Input("Not valid int");
    }
    return w;
}

int get_valid_Int(Model & model, char c) {

    int i;

    if (!(cin >> i) || i > 9 || i < 1 || !(model.IsValidId(i, c))) {

        throw Invalid_Input("Not valid ID");

    }

    i--;

    return i;

}

int get_Int_For_ID(Model & model, char c) {

    int i;

    if (!(cin >> i) || i > 9 || i < 1 || (model.IsValidId(i, c))) {

        throw Invalid_Input("Not valid ID");

    }
    i--;

    return i;

}

void DoCreateCommand(Model & model, char c, int id, Point2D pos) {

    model.NewCommand(c, id, pos);

}
