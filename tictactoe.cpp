
//aminemahiddine.code@gmail.com

// 2 players tic tac toe game
// 1 player comming soon

#include <iostream>
using namespace std;

char grid[9];
char tour = 'o';

void choice(int line, int number)
{

    if (grid[number] == 'x')
    {
        switch (line)
        {
        case 1:
            cout << "     *   *  ";

            break;
        case 2:
            cout << "       *    ";

            break;
        case 3:
            cout << "     *   *  ";
            break;
        default:
            break;
        }
    }
    else if (grid[number] == 'o')
    {
        switch (line)
        {
        case 1:
            cout << "     ****   ";

            break;
        case 2:
            cout << "    *    *  ";

            break;
        case 3:
            cout << "     ****   ";

            break;
        default:
            break;
        }
    }
    else
    {
        switch (line)
        {
        case 1:
            cout << "            ";

            break;
        case 2:
            cout << "            ";

            break;
        case 3:
            cout << "            ";

            break;
        default:
            break;
        }
    }
}
void creatCanvas()
{
    choice(1, 7);
    cout << "|";
    choice(1, 8);
    cout << "|";
    choice(1, 9);
    cout << "\n";
    choice(2, 7);
    cout << "|";
    choice(2, 8);
    cout << "|";
    choice(2, 9);
    cout << "\n";
    choice(3, 7);
    cout << "|";
    choice(3, 8);
    cout << "|";
    choice(3, 9);
    cout << "\n";
    cout << "----------------------------------------\n";
    choice(1, 4);
    cout << "|";
    choice(1, 5);
    cout << "|";
    choice(1, 6);
    cout << "\n";
    choice(2, 4);
    cout << "|";
    choice(2, 5);
    cout << "|";
    choice(2, 6);
    cout << "\n";
    choice(3, 4);
    cout << "|";
    choice(3, 5);
    cout << "|";
    choice(3, 6);
    cout << "\n";
    cout << "----------------------------------------\n";
    choice(1, 1);
    cout << "|";
    choice(1, 2);
    cout << "|";
    choice(1, 3);
    cout << "\n";
    choice(2, 1);
    cout << "|";
    choice(2, 2);
    cout << "|";
    choice(2, 3);
    cout << "\n";
    choice(3, 1);
    cout << "|";
    choice(3, 2);
    cout << "|";
    choice(3, 3);
    cout << "\n";
}

int checkwin()
{

    if (grid[1] != 0 && grid[1] == grid[2] && grid[2] == grid[3])

        return 1;
    else if (grid[4] != 0 && grid[4] == grid[5] && grid[5] == grid[6])

        return 1;
    else if (grid[7] != 0 && grid[7] == grid[8] && grid[8] == grid[9])

        return 1;
    else if (grid[1] != 0 && grid[1] == grid[4] && grid[4] == grid[7])

        return 1;
    else if (grid[2] != 0 && grid[2] == grid[5] && grid[5] == grid[8])

        return 1;
    else if (grid[3] != 0 && grid[3] == grid[6] && grid[6] == grid[9])

        return 1;
    else if (grid[1] != 0 && grid[1] == grid[5] && grid[5] == grid[9])

        return 1;
    else if (grid[3] != 0 && grid[3] == grid[5] && grid[5] == grid[7])

        return 1;

    else
        return 0;
}
int checkdraw()
{
    for (int i = 1; i < 10; i++)
    {
        if (grid[i] != 0)
            continue;
        else
            return 0;
    }
    return 1;
}
void update()
{
    if (tour == 'x')
        tour = 'o';
    else if (tour == 'o')
        tour = 'x';
}
bool select()
{
    cout << "\n\t\tselect a number\n\n\t\t 7 8 9\n\t\t 4 5 6\n\t\t 1 2 3\n";
    int number;
    cout << "\n";
    cin >> number;
    cout << "\n";
    if (grid[number] != 'x' && grid[number] != 'o')
    {
        grid[number] = tour;
        return 1;
    }
    else
        return 0;
}
void draw()
{
    creatCanvas();
}
void setup()
{
    for (int i = 1; i < 10; i++)
    {
        grid[i] = 0;
    }
    while (1)
    {
        int a;
        a = select();
        if (a)
        {
            system("cls");
            cout << "\n\n";
            draw();
        }
        else
        {
            // system("cls");
            cout << "\n\t\t\talready taken chose anouther number !!\n\n\n\n";
            draw();
            continue;
        }
        if (checkwin() || checkdraw())
        {
            if (checkwin())
            {
                cout << "\n\t\t" << tour << "'s win!!";
                exit(-1);
            }
            if (checkdraw())
            {
                cout << "\n\t\tdraw!!";
                exit(-1);
            }
        }
        update();
    }
}

int main()
{
    setup();

    return 0;
}
