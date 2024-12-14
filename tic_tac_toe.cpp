#include <iostream>

#include "tic_tac_toe.hpp"
extern string playerOneMark;
extern string playerTwoMark;

TicTacToe::TicTacToe(Rules *rules, Board *board, BoardPrinter *boardPrinter)
{
  this->rules = rules;
  this->board = board;
  this->boardPrinter = boardPrinter;
}

void TicTacToe::start()
{
  int userInput;
  playerOneMark = "X";
  playerTwoMark = "O";
  
  cout << boardPrinter->print() << endl;
  while (this->rules->inProgress())
  {
    cout << "Make your move!" << endl;
    cin >> userInput;
    int validInput = rules->validator(userInput);
    board->move(validInput, this->getCurrentMark());
    cout << boardPrinter->print() << endl;
    this->toggleMark();
  }

  cout << rules->status() << endl;
}

void TicTacToe::toggleMark()
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

string TicTacToe::getCurrentMark()
{
  return this->currentMark;
}
