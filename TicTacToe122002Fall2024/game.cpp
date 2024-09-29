#include <iostream>

#include <cctype>

#include "game.hpp"

Game::Game(Rules *rules, Board *board, BoardPrinter *boardPrinter)
{
    this->rules = rules;
    this->board = board;
    this->boardPrinter = boardPrinter;
}

void Game::start()
{
    string userInput;
    int turn = 1;
    bool valid = false;
    bool draw = false;
    cout << boardPrinter->print() << endl;
    while (this->rules->inProgress())
    {
        if (turn == 10)                         //this breaks the gameloop if the whole board is filled
        {                                       //and no win was found. logically this must be a draw.
            draw = true;                        //the bool draw is then set to true so the win message is not displayed 
            cout << "Cat's game!" << endl;
            break;
        }
        cout << "Make your move!" << endl;
        while (!valid)
        {
            cin >> userInput;
            if (userInput.size() > 1){
                cout << "Your input must be a valid integer.\n";
            }
            else if(isdigit(userInput.at(0)) == false){
                cout << "Your input must be a valid integer.\n";
            }
            else if (stoi(userInput) > 9 || stoi(userInput) < 1)
            {
                cout << "That is out of range!\n";
            }
            
            else if (board->getValue(stoi(userInput)) == "X" || board->getValue(stoi(userInput)) == "O")
            {
                cout << "That space is already taken!\n";
            }
            
            
            else
            {
                break;
            }
        }
        board->move(stoi(userInput), this->getCurrentMark());
        cout << boardPrinter->print() << endl;
        this->toggleMark();
        turn++;
    }

    if (!draw)
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