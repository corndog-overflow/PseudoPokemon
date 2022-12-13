#include <iostream>
#include <cmath>
#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonCenter.h"
#include "Model.h"
#include "GameCommand.h"
#include "View.h"
#include "Input_Handling.h"

using namespace std;

int main() {
    View view;
    Model model;
    char input, inp_code;
    int ID;
    int x, y;
    int id1, id2;
    unsigned int numpotions;
    unsigned int numbattles;

    while(true) {
        try {
            model.Display(view);
            cout << "Enter a game command: " << endl;
            input = get_char();

            switch(input) {
                case 'm':
                    ID = get_valid_Int(model, 'T');
                    x = getInteger();
                    y = getInteger();
                    DoMoveCommand(model, ID, Point2D(x, y));
                    break;

                case 'c':
                    id1 = get_valid_Int(model, 'T');
                    id2 = get_valid_Int(model, 'C');
                    DoMoveToCenterCommand(model, id1, id2);
                    break;

                case 'g':
                    id1 = get_valid_Int(model, 'T');
                    id2 = get_valid_Int(model, 'G');
                    DoMoveToGymCommand(model, id1, id2);
                    break;

                case 's':
                    ID = get_valid_Int(model, 'T');
                    DoStopCommand(model, ID);
                    break;

                case 'b':
                    ID = get_valid_Int(model, 'T');
                    numpotions = getUnInt();
                    DoBattleCommand(model, ID, numpotions);
                    break;

                case 'p':
                    ID = get_valid_Int(model, 'T');
                    numbattles = getUnInt();
                    DoRecoverInCenterCommand(model, ID, numbattles);
                    break;

                case 'a':
                    DoAdvanceCommand(model, view);
                    break;

                case 'r':
                    DoRunCommand(model, view);
                    break;

                case 'q':
                    model.destructObject();
                    exit(0);
                case 'n':
                    inp_code = get_char();
                    ID = get_Int_For_ID(model, inp_code);
                    x = getInteger();
                    y = getInteger();
                    DoCreateCommand(model, tolower(inp_code, locale()), ID, Point2D(x, y));
                    break;

            }

        }

        catch (Invalid_Input& except) {

            cout << "Invalid input: " << except.msg_ptr << endl;

        }

    }
    return 0;
}
