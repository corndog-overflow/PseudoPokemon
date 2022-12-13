#ifndef GAMECOMMAND_H
#define GAMECOMMAND_H

#include <iostream>
#include "Point2D.h"
#include "Vector2D.h"
#include "Model.h"
#include "Input_Handling.h"


void DoStopCommand(Model &model, int t_id);
void DoBattleCommand(Model &model, int t_id, unsigned int battles);
void DoRecoverInCenterCommand(Model &model, int t_id, unsigned int potions_needed);
void DoAdvanceCommand(Model &model, View &view);
void DoRunCommand(Model &model, View &view);
char get_char();
unsigned int getUnInt();
int getInteger();
void DoMoveCommand(Model &model, int inputID, Point2D destination);
void DoMoveToCenterCommand(Model &model, int t_id, int center_id);
void DoMoveToGymCommand(Model &model, int t_id, int gym_id);
int get_valid_Int(Model &model, char c);
int get_Int_For_ID(Model &model, char c);
void DoCreateCommand(Model &model, char type, int id, Point2D p);

#endif
