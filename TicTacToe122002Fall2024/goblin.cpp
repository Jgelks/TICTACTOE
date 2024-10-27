#include <iostream>

#include "goblin.hpp"

Goblin::Goblin(Board *board, std::string mark)
{
  this->board = board;
  this->mark = mark;
}

std::string Goblin::getMark()
{
  return mark;
}

void Goblin::prompt()
{
  std::cout << "I am a goblin! Rawr!" << std::endl;
  std::cout << "You think you can beat me? Unlikely!" << std::endl;
  std::cout << "Enter a move!" << std::endl;
}

void Goblin::move()
{
  int userInput;
  std::cin >> userInput;
  int validInput = this->validator(userInput);
  board->move(validInput, this->mark);
}

int Goblin::validator(int potentiallyInvalidInput)
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
