#include "View.h"
#include "Trainer.h"

View::View()
{
    origin = Point2D();
    size = 11;
    scale = 2;
}

void View::Clear()
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            grid[i][j][0] = '.';
            grid[i][j][1] = ' ';
        }
    }
}

bool View::GetSubscripts(int &ox, int &oy, Point2D location)
{
    Vector2D subscripts;
    subscripts.x = int(location.x) - int(origin.x);
    subscripts.y = int(location.y) - int(origin.y);

    subscripts = subscripts/scale;

    subscripts.x = int(subscripts.x);
    subscripts.y = int(subscripts.y);

    ox = int(subscripts.x);
    oy = int(subscripts.y);

    if(subscripts.x < size*scale && subscripts.y < size*scale)
    {
        return true;
    }
    else
    {
        cout << "an object is out of bounds!!" << endl;
        return false;
    }

}

void View::Plot(GameObject *ptr) {
    int ix, iy;
    bool valid;
    valid = GetSubscripts(ix, iy, ptr->getLocation());
    if (valid && grid[ix][iy][0] == '.') {
        ptr->DrawSelf(grid[ix][iy]);
    }
    else if (valid) {
        grid[ix][iy][0] = '*';
        grid[ix][iy][1] = ' ';
    }
}

void View::Draw()
{
    for (int i = size - 1; i >= 0; i--)
    {
        for (int j = -1; j < size; j++)
        {
            if (j == -1)
            {
                if (i % 2 == 0)
                {
                    if (i * scale < 10) {

                        cout << i * scale << " ";
                    }
                    else
                    {
                        cout << i * scale;
                    }
                }
                else
                {
                    cout << "  ";
                }
            }
            else
            {
                cout << grid[j][i][0] << grid[j][i][1];
            }
        }

        cout << " " << endl;
    }

    cout << " ";

    for (int j = -1; j < size; j++)
    {
        if (j % 2 == 0)
        {
            if (j * scale < 10) {

                cout << j * scale << " ";
            }
            else
            {
                cout << j * scale;
            }
        }
        else
        {
            cout << "  ";
        }
    }
}