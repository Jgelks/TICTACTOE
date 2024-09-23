#include <iostream>

#include "game.hpp"

Game::Game(Rules *rules, Board *board, BoardPrinter *boardPrinter)
{
    this->rules = rules;
    this->board = board;
    this->boardPrinter = boardPrinter;
}

void Game::start()
{
    int userInput;
    int turn = 1;
    bool valid = false;
    cout << boardPrinter->print() << endl;
    while (this->rules->inProgress())
    {
        if (turn == 10)
        {
            turn++;
            cout << "Cat's game!";
            break;
        }
        cout << "Make your move!" << endl;
        while (!valid)
        {
            cin >> userInput;
            if (Board::getValue(userInput) == "X" || Board::getValue(userInput) == "O")
            {
                cout << "That space is already taken!\n";
            }
            else if (userInput > 9 || userInput < 1)
            {
                cout << "That is out of range!\n";
            }
            else
            {
                break;
            }
        }
        board->move(userInput, this->getCurrentMark());
        cout << boardPrinter->print() << endl;
        this->toggleMark();
        turn++;
    }

    if (turn != 11)
    {
        cout << rules->status() << " wins the game!" << endl;
    }
}

void Game::toggleMark()
{
    if (this->currentMark == "X")
    {
        this->currentMark = "O";
    }
    else
    {
        this->currentMark = "X";
    }
}

string Game::getCurrentMark()
{
    return this->currentMark;
}