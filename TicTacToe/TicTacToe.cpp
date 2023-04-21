#include <iostream>
#include <climits>
#include <string>
#include <cmath>
#include <map>

std::map<char, int> status_dictionary = { {'X',-1}, {'0', 1} };

//displays the current sheet
void display_sheet(char sheet[])
{
    std::cout << "   |   |" << std::endl;
    std::cout << " " << sheet[0] << " | "<< sheet[1] << " | " << sheet[2] << std::endl;
    std::cout << "___|___|___" << std::endl;
    std::cout << "   |   |" << std::endl;
    std::cout << " " << sheet[3] << " | " << sheet[4] << " | " << sheet[5] << std::endl;
    std::cout << "___|___|___" << std::endl;
    std::cout << "   |   |" << std::endl;
    std::cout << " " << sheet[6] << " | " << sheet[7] << " | " << sheet[8] << std::endl;
    std::cout << "   |   |" << std::endl << std::endl;

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

//display current score
void display_current_score(float score_X, float score_0, bool is_final)
{
    std::cout << std::endl;
    std::cout << "----------------------" << std::endl;
    if (!is_final)
        std::cout << "CURRENT SCORE" << std::endl;
    else
        std::cout << "FINAL SCORE" << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << score_X << " - " << score_0 << std::endl;
    std::cout << "----------------------" << std::endl << std::endl;
    if (is_final)
        if (score_X > score_0)
            std::cout << "First Player(X) is the OVERALL WINNER!" << std::endl;
        else
            if (score_X < score_0)
                std::cout << "Second Player(X) is the OVERALL WINNER!" << std::endl;
            else
                std::cout << "The final result is a DRAW!" << std::endl;
}

int main()
{
    char continue_playing[11];

    float score_X = 0;
    float score_0 = 0;

    char empty_char_array[2]{};
    char end_line[2]{ '\n' };

    int round_number = 1;

    do
    {

        //initial("empty") sheet
        char sheet[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

        std::cout << "~ROUND " << round_number << "~" << std::endl << std::endl;

        display_sheet(sheet);


        for (int i = 0; i < 9; i++)
        {
            int move;
            switch (i % 2)
            {
            //1st player turn
            case 0:
                std::cout << "First Player(X); Insert your next move...";
                while (!(std::cin >> move) || sheet[move - 1] == 'X' || sheet[move - 1] == '0' || move > 9)
                {
                    std::cout << "Insert a valid value...";
                    std::cin.clear();
                    std::cin.ignore(INT_MAX, '\n');
                }
                sheet[move - 1] = 'X';
                break;

            //2nd player turn
            case 1:
                std::cout << "Second Player(0); Insert your next move...";
                while (!(std::cin >> move) || sheet[move - 1] == 'X' || sheet[move - 1] == '0' || move > 9)
                {
                    std::cout << "Insert a valid value...";
                    std::cin.clear();
                    std::cin.ignore(INT_MAX, '\n');
                }
                sheet[move - 1] = '0';
                break;
            }
            std::cout << std::endl;

            display_sheet(sheet);

            //check if someone won
            int crt_status = game_status(sheet);
            if (game_status(sheet) == -1)
            {
                score_X += 1;
                std::cout << "First Player(X) WON!" << std::endl;
                break;
            }
            else
                if (game_status(sheet) == 1)
                {
                    score_0 += 1;
                    std::cout << "Second Player(0) WON!" << std::endl;
                    break;
                }
        }


        //check if draw
        if (game_status(sheet) == 0)
        {
            std::cout << "The Game Is A DRAW!" << std::endl;
            score_X += 0.5f;
            score_0 += 0.5f;
        }

        display_current_score(score_X, score_0, false);


        std::cout << "Play another round(y/n)?" << std::endl;
        std::cin.ignore(INT_MAX, '\n');
        std::cin.get(continue_playing, 10);
       
        while (strcmp(continue_playing, "y") != 0 && strcmp(continue_playing, "n") != 0 && strcmp(continue_playing, "Y") != 0 && strcmp(continue_playing, "N") != 0)
        {
            std::cout << "Input a valid value(y/n)...";
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cin.get(continue_playing, 10);
        }
        round_number++;
        std::cout << std::endl;
    } while (strcmp(continue_playing, "y") == 0 || strcmp(continue_playing, "Y") == 0);


    display_current_score(score_X, score_0, true);

    system("pause");
}

//56