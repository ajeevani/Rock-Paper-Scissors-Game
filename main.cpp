#include <iostream>
#include <string>
#include <cstring>
#include <conio.h>

using namespace std;

class Player {
    char rock = 'R';
public:
    Player() {}
    virtual char GetMove() = 0;
    virtual string GetName() = 0;
};

class HumanPlayer : public Player {
public:
    // method to get move by human player with error handling
    char GetMove() {
        char move;
        bool pass = false;
        cout << "Enter your move (rock, paper, or scissors): ";

        while (!pass)
        {
            move = _getch();
            move = toupper(move);
            if (move != 'R' && move != 'P' && move != 'S')
            {
                cout << "\nError! Please type 'R', 'S' or 'P' only: ";
            }
            else
            {
                pass = true;
            }
        }
        cout << endl;
        return move;
    }
    //method to return "human" as player name
    std::string GetName() { return "Human"; }
};

class ComputerPlayer : public Player {
public:
    // method to get random move by computer
    char GetMove() {
        
        int random_move = 1 + (rand() % 3);
        if (random_move == 1) {
            return 'R';
        }
        else if (random_move == 2) {
            return 'P';
        }
        else {
            return 'S';
        }
    }
    // method to return "computer" as player name
    std::string GetName() { return "Computer"; }
};

// method to display scoreboard
void Scoreboard(int p1score, int p2score)
{
    cout << "|-----------------------------|" << endl;
    cout << "|  Player 1    |    Player 2  |" << endl;
    cout << "|-----------------------------|" << endl;
    cout << "|              |              |" << endl;
    cout << "|      " << p1score << "       |" << "       " << p2score << "      |" << endl;
    cout << "|              |              |" << endl;
    cout << "|-----------------------------|" << endl << endl;
}

int main() {
    int p1score = 0;
    int p2score = 0;
    cout << "Welcome to Rock Paper Scissors\n\n";
    cout << "Please Select one of the following modes: \n";
    cout << "1. Player vs Player\n";
    cout << "2. Player vs Computer\n";
    cout << "Selection (Type 1 or 2): ";
    int choice;
    cin >> choice;
    
    Player* player1;
    Player* player2;
    if (choice == 1) {
        player1 = new HumanPlayer();
        player2 = new HumanPlayer();
    }
    else {
        player1 = new HumanPlayer();
        player2 = new ComputerPlayer();
    }

    cout << "\nTo ensure a fair game your input will not display on the console \n(Make sure to type the first letter of your move only)\n\n";

    while (true) {
        Scoreboard(p1score, p2score);

        char move1 = player1->GetMove();
        string moveone;
        if (move1 == 'R')
        {
            moveone = "Rock";
        }
        else if (move1 == 'S')
        {
            moveone = "Scissors";
        }
        else if(move1 == 'P')
        {
            moveone = "Paper";
        }

        char move2 = player2->GetMove();
        string movetwo;
        if (move2 == 'R')
        {
            movetwo = "Rock";
        }
        else if (move2 == 'S')
        {
            movetwo = "Scissors";
        }
        else if (move2 == 'P')
        {
            movetwo = "Paper";
        }

        cout << player1->GetName() << "(Player 1) : " << moveone << endl;
        cout << player2->GetName() << "(Player 2) : " << movetwo << endl;

        if (move1 == 'R' && move2 == 'S') {
            cout << "Player 1 wins!" << endl << endl;
            p1score++;
        }
        else if (move1 == 'P' && move2 == 'R') {
            cout << "Player 1 wins!" << endl << endl;
            p1score++;
        }
        else if (move1 == 'S' && move2 == 'P') {
            cout << "Player 1 wins!" << endl << endl;
            p1score++;
        }
        else if (move1 == move2) {
            cout << "It's a tie!" << endl << endl;
        }
        else {
            cout << "Player 2 wins!" << endl << endl;
            p2score++;
        }
    }

    delete player1;
    delete player2;

    return 0;
}
