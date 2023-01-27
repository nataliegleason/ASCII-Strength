// Write the code for a game called “ASCII Strength” of a four-letter word selected by Player 1 
// followed by a four-letter word selected by Player 2. The result would be the sum 
//of the ASCII value of each of the letters of the selected words and whoever has higher sum (called ASCII strength) wins. 
//Programming Languages CSC 408
//Natalie Gleason

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;;

int chartoint(char a) {

    switch (a) {
    case 'A':
        return 1;
        break;
    case 'B':
        return 2;
        break;
    case 'C':
        return 3;
        break;
    case 'D':
        return 4;
        break;
        case 'E':
            return 5;
            break;
        case 'F':
            return 6;
            break;
        case 'G':
            return 7;
            break;
        case 'H':
            return 8;
            break;
        case 'I':
            return 9;
            break;
        case 'J':
            return 10;
            break;
        case 'K':
            return 11;
            break;
        case 'L':
            return 12;
            break;
        case 'M':
            return 13;
            break;
        case 'N':
            return 14;
            break;
        case 'O':
            return 15;
            break;
        case 'P':
            return 16;
            break;
        case 'Q':
            return 17;
            break;
        case 'R':
            return 18;
            break;
        case 'S':
            return 19;
            break;
        case 'T':
            return 20;
            break;
        case 'U':
            return 21;
            break;
        case 'V':
            return 22;
            break;
        case 'W':
            return 23;
            break;
        case 'X':
            return 24;
            break;
        case 'Y':
            return 25;
            break;
        case 'Z':
            return 26;
            break;
    }

    return 0;
}

int tovalue(string input) {


    int first = chartoint(input[0]);
    int second = chartoint(input[1]);
    int third = chartoint(input[2]);
    int fourth = chartoint(input[3]);

    int value = first + second + third + fourth;

    return value;
}

string generateword() {

    string arr[500];
    
    ifstream file("words.txt");
    if (file.is_open())
    {
        for (int i = 0; i < 500; i++) {
            string temp;
            getline(file, temp);
            arr[i] = temp;
        }
        file.close();
    }
    else
    {
        cout << "Error: Unable to open file.";
        exit(0);
    }

    srand(time(0));
    int random_index = rand() % 500;
    string random_word = arr[random_index];
    return random_word;

}

int main()
{

    cout << "Welcome to ASCII strength, a game where the strongest word wins!";
    cout << "\nTo play, you must enter a four letter word. The program will calculate the 'ASCII strength' of your word and compare it to your opponent.";
    cout << "\nWhoever has the higher sum will win!";

    char another;
    another = 'y';
    while (another == 'y' || another == 'Y') {

        cout << "\nWould you like to play against a friend, or against a bot? (F/B)";
        char mode;
        cin >> mode;

        if (mode == 'F' || mode == 'f') {

            cout << "\nPlayer 1, please input your four letter word in all caps: ";
            string answer1;
            cin >> answer1;

            int value1;
            value1 = tovalue(answer1);

            cout << "\nPlayer 2, please input your four letter word in all caps: ";
            string answer2;
            cin >> answer2;

            int value2;
            value2 = tovalue(answer2);

            if (value1 > value2) {
                cout << "\nPlayer 1 wins!";
            }
            else if (value2 > value1) {
                cout << "\nPlayer 2 wins!";
            }
            else if (value1 == value2) {
                cout << "\nTie!";
            }
        }
        else if (mode == 'B' || mode == 'b') {

            cout << "\nPlease input your four letter word in all caps: ";
            string answer;
            cin >> answer;

            int valueanswer;
            valueanswer = tovalue(answer);

            string botword;
            botword = generateword();

            cout << "\nThe bot generates a random word based on a list of popular four letter words.";
            cout << "\nThe bot has generated this word: " << botword;

            int valuebot;
            valuebot = tovalue(botword);

            if (valueanswer > valuebot) {
                cout << "\nYou win!";
            }
            else if (valuebot > valueanswer) {
                cout << "\nThe bot wins!";
            }
            else if (valueanswer == valuebot) {
                cout << "\nTie!";
            }
        }

        cout << "\nWould you like to start a new game? (y/n)";
        cin >> another;
    }
}
