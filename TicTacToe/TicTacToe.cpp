#include <iostream>
#include <climits>
#include <string>

using namespace std;

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

int main()
{
    char sheet[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    display_sheet(sheet);

    for (int i = 0; i < 9; i++)
    {
        int move;
        switch (i % 2)
        {
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

    }


}
