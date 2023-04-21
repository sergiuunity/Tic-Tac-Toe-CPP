#include <iostream>

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
    cout << "   |   |" << endl;

}

int main()
{
    char sheet[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    display_sheet(sheet);
}
