#include <iostream>
using namespace std;
// Created by schro on 11/18/2022.

#include "GameObject.h"
#include "Point2D.h"
#include "Vector2D.h"
#include "PokemonGym.h"
#include "PokemonCenter.h"
#include "Trainer.h"
#include "Model.h"
#include "GameCommand.h"
#include "View.h"


//please have mercy
//i tried my hardest :((((((((((
View V = View(); //initialize view
int main(){
    cout<<"EC327: Introduction to Software Engineering"<<endl;
    cout<<"Fall 2022"<<endl<<"Programming Assignment 3"<<endl;
    cout<<"Sadman Kabir" << endl;


    Model* model = new Model(); //initializes new model
    Model M;
    model->ShowStatus();

    M.ShowStatus(); // shows first status'
    View view;
    model->Display(view);
    bool loop_var = true;
    while(loop_var){
        cout<<"Enter command: ";
        char input_char;
        cin>>input_char;

        switch (input_char) {
            case 'm':
                DoMoveCommand(M);
                break;
            case 'c':
                DoMoveToCenterCommand(M);
                break;
            case 'g':
                DoMoveToGymCommand(M);
                break;
            case 's':
                DoStopCommand(M);
                break;
            case 'p':
                DoRecoverInCenterCommand(M);
                break;
            case 'b':
                DoBattleCommand(M);
                break;
            case 'a':
                DoAdvanceCommand(M);
                break;
            case 'r':
                DoRunCommand(M);
            case 'q':
                delete model;
                loop_var = false;
                cout<<"Quit the game"<<endl;
                break;
        }
        M.Update();//updates
        M.ShowStatus();//shows new status'

        if(input_char != 'q')//unless quit
        {
            M.Display(V);//show new grid
        }

    }

    return 0;
}