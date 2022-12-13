//
// Created by schro on 11/18/2022.
//

#include "GameCommand.h"
#include "Model.h"


void DoMoveCommand(Model& model){
    int input_id;
    double input_x;
    double input_y;
    cin >> input_id>> input_x >> input_y; //gets inputs from 1 line
    if ((input_id == 1 || input_id == 2) && (input_x > 0) && (input_x < 20) && (input_y > 0) && (input_y < 20)){
        //error checking.
        Point2D p1(input_x, input_y);
        Trainer* P = model.GetTrainerPtr(input_id);
        P->StartMoving(p1);
        cout << "Moving" << " " << P -> GetName() << "to" << " " << p1;
    }
    else{
        cout << "“Error: Please enter a valid command!”";
        exit(0);
    }

}

void DoMoveToCenterCommand(Model& model){
    int input_id1;
    int input_id2;
    cin>>input_id1>>input_id2;
    if ((input_id1 == 1 || input_id1 == 2) && (input_id2 == 1 || input_id2 == 2)) {
        //must be one of two trainers, one of two gyms
        (model.GetTrainerPtr(input_id1))->StartMovingToCenter(model.GetPokemonCenterPtr(input_id2));
    }
    else{
        cout << "“Error: Please enter a valid command!”";
        exit(0);
    }
}

void DoMoveToGymCommand(Model& model){
    int input_id1;
    int input_id2;
    cin>>input_id1>>input_id2;
    if ((input_id1 == 1 || input_id1 == 2) && (input_id2 == 1 || input_id2 == 2)) {

        (model.GetTrainerPtr(input_id1))->StartMovingToGym(model.GetPokemonGymPtr(input_id2));
    }
    else{
        cout << "“Error: Please enter a valid command!”";
        exit(0);
    }
}

void DoStopCommand(Model& model){
    int inID;
    cin>> inID;
    Trainer* X = model.GetTrainerPtr(inID);
    X->Stop();
    cout << "Stopping" << model.GetTrainerPtr(inID)->GetName() << " T" << X->getId() << endl;
}

void DoBattleCommand(Model& model){
    int inID;
    unsigned int battles;
    cin>>inID>> battles;
    Trainer* P = model.GetTrainerPtr(inID);
    P->StartBattling(battles);
    cout << P->GetName()<<" is battling in:" << " " << P->getLocation() << endl;
}


void DoRecoverInCenterCommand(Model& model)
{
    int pkID;
    unsigned int HP;

    cin>>pkID >> HP;
    Trainer* P = model.GetTrainerPtr(pkID);//gets target trainer
    P->StartRecoveringHealth(HP);
    //calls recover func
}


void DoAdvanceCommand(Model& model)
{
    model.Update();
    model.ShowStatus();
    cout << "Advancing One Tick..." << endl;
}

void DoRunCommand(Model& model){
    cout<<"Advancing to next event or 5 ticks"<<endl;
    int count = 0;
    while((model.Update()==false) && count < 5){//if no update, and below 5 counts
        count++;
    }
    model.ShowStatus();
}

