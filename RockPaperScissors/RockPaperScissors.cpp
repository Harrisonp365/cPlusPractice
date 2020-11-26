#include <iostream>
#include <string>
#include <ctime>
using namespace std;

enum class Choice {rock, paper, scissors};


Choice playerChoice;
Choice computerChoice;

string words[3] = { "Rock", "Paper", "Scissors" };

Choice getComputerChoice();
void decideWinner();
string getMessage(Choice winner);
int rand0toN1(int n);

int main(int argc, char *argv[])
{
    srand(time(NULL));
    string input_str;
    int c;

    while (true)
    {
        cout << "Enter Rock, Paper, Scissors, or Exit: ";
        getline(cin, input_str);

        if (input_str.size() < 1)
        {
            cout << "Invalid input." << endl;
            continue;
        }

        c = input_str[0];
        if (c == 'R' || c == 'r')
            playerChoice = Choice::rock;
        else if (c == 'P' || c == 'p')
            playerChoice = Choice::paper;
        else if (c == 'S' || c == 's')
            playerChoice = Choice::scissors;
        else if (c == 'E' || c == 'e')
            break;
        else
        {
            cout << "Invalid input." << endl;
            continue;
        }

        computerChoice = getComputerChoice();
        int p = (int)playerChoice;
        int c = (int)computerChoice;
        cout << "You Chose " << words[p];
        cout << "," << endl;
        cout << "I Chose " << words[c];
        cout << "," << endl;
        decideWinner();
    }
    return EXIT_SUCCESS;
}

Choice getComputerChoice()
{
    int n = rand0toN1(3);
    if (n == 0) return Choice::rock;
    if (n == 1) return Choice::paper;
    return Choice::scissors;
}

void decideWinner()
{
    if (playerChoice == computerChoice)
    {
        cout << "Result is a tie." << endl << endl;
        return;
    }

    int p = static_cast<int>(playerChoice);
    int c = static_cast<int>(computerChoice);
    if (p - c == 1 || p - c == -2)
    {
        cout << getMessage(playerChoice);
        cout << "You Win!!!" << endl;
    }
    else
    {
        cout << getMessage(computerChoice);
        cout << "I Win!!!" << endl;
    }
    cout << endl;
}

string getMessage(Choice winner)
{
    if (winner == Choice::rock)
        return string("Rock beats Scissors...");
    else if (winner == Choice::paper)
        return string("Paper beats Rock...");
    else
        return string("Scissors beats Paper...");
}

int rand0toN1(int n)
{
    return rand() % n;
}