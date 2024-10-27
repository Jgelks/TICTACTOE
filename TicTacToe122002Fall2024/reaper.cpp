#include <iostream>

#include "reaper.hpp"

Reaper::Reaper(Board *board, std::string mark)
{
  this->board = board;
  this->mark = mark;
}

std::string Reaper::getMark()
{
  return mark;
}

void Reaper::prompt()
{
  std::cout << "Foolish mortal..." << std::endl;
  std::cout << "I am the destroyer of worlds..." << std::endl;
  std::cout << "Do you want to..." << std::endl;
  std::cout << "(1) Make a move" << std::endl;
  std::cout << "(2) Use your special power to destroy everything on the board" << std::endl;
}

int Reaper::selectOneOrTwo()
{
  int option;
  std::cin >> option;
  return option;
}

void Reaper::move()
{
  if (selectOneOrTwo() == 1)
  {
    std::cout << "Enter a move!" << std::endl;
    int userInput;
    std::cin >> userInput;
    int validInput = this->validator(userInput);
    board->move(validInput, this->mark);
  }
  else
  {
    std::cout << "Behold my power..." << std::endl;
    board->clear();
  }
}

int Reaper::validator(int potentiallyInvalidInput)
{
  int validInput = potentiallyInvalidInput;

  // TODO: Be careful! This will need to change if you are allowing users to select their own marks.
  while ((board->getValue(validInput) == "X" || board->getValue(validInput) == "O") || (validInput < 0 || validInput > 9))
  {
    std::cout << "Invalid move, Please try again: ";
    std::cin >> validInput;
  }
  return validInput;
}
