#include <iostream>
#include <climits>
#include <string>
#include <cmath>
#include <map>

using namespace std;

map<char, int> status_dictionary = { {'X',-1}, {'0', 1} };

//displays the current sheet
void display_sheet(char sheet[])
{
    cout << "   |   |" << endl;
    cout << " " << sheet[0] << " | "<< sheet[1] << " | " << sheet[2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |" << endl;
    cout << " " << sheet[3] << " | " << sheet[4] << " | " << sheet[5] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |" << endl;
    cout << " " << sheet[6] << " | " << sheet[7] << " | " << sheet[8] << endl;
    cout << "   |   |" << endl << endl;

}

//checks the game status given the current sheet
//returns:   -1 if 1st player(X) won
//            1 if 2nd player(0) won
//            0 if the game is a draw
//            2 if the game isn't over
int game_status(char sheet[])
{
    //check diagonals
    if ((sheet[0] == sheet[4] && sheet[4] == sheet[8]) || (sheet[2] == sheet[4] && sheet[4] == sheet[6]))
        return status_dictionary[sheet[4]];
    
    //check horizontal lines
    for (int i = 0; i <= 6; i = i + 3)
        if (sheet[i] == sheet[i + 1] && sheet[i] == sheet[i + 2])
            return status_dictionary[sheet[i]];
    
    //check vertical lines
    for (int i = 0; i <= 2; i++)
        if (sheet[i] == sheet[i + 3] && sheet[i] == sheet[i + 6])
            return status_dictionary[sheet[i]];

    //check if there are available positions remaining
    for (int i = 0; i < 9; i++)
        if (sheet[i] != 'X' && sheet[i] != '0')
            return 2;

    return 0;
}

int main()
{
    //initial sheet
    char sheet[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    display_sheet(sheet);

    for (int i = 0; i < 9; i++)
    {
        int move;
        switch (i % 2)
        {
        //1st player turn
        case 0:
            cout << "First Player(X); Insert your next move...";
            while (!(cin >> move) || sheet[move - 1] == 'X' || sheet[move - 1] == '0')
            {
                cout << "Insert a valid value...";
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
            sheet[move - 1] = 'X';
            break;

        //2nd player turn
        case 1:
            cout << "Second Player(0); Insert your next move...";
            while (!(cin >> move) || sheet[move - 1] == 'X' || sheet[move - 1] == '0')
            {
                cout << "Insert a valid value...";
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
            sheet[move - 1] = '0';
            break;
        }
        cout << endl;

        display_sheet(sheet);

        //check if someone won
        int crt_status = game_status(sheet);
        if (game_status(sheet) == -1)
        {
            cout << "First Player(X) WON!" << endl;
            break;
        }
        else
            if (game_status(sheet) == 1)
            {
                cout << "Second Player(0) WON!" << endl;
                break;
            }
    }

    //check if draw
    if (game_status(sheet) == 0)
        cout << "The Game Is A DRAW!" << endl;

}
