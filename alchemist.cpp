#include <iostream>

#include "alchemist.hpp"
#include "battle_tic_tac_toe.hpp"
extern string playerOneMark;
extern string playerTwoMark;

Alchemist::Alchemist(Board *board, std::string mark)
{
  this->board = board;
  this->mark = mark;
}

std::string Alchemist::getMark()
{
  return mark;
}

void Alchemist::prompt()
{
  std::cout << "I am the greatest alchemist to ever live!" << std::endl;
  std::cout << "Do you want to..." << std::endl;
  std::cout << "(1) Make a move" << std::endl;
  std::cout << "(2) Use your special power to transmute two marks" << std::endl;
}

int Alchemist::selectOneOrTwo()
{
  int option;
  std::cin >> option;
  return option;
}

void Alchemist::move()
{
  if (selectOneOrTwo() == 1)
  {
    std::cout << "Enter a move!" << std::endl;
    string userInput;
    std::cin >> userInput;
    int validInput = this->validator(userInput);
    board->move(validInput, this->mark);
  }
  else
  {
    std::cout << "Watch this!" << std::endl;
    board->alchemistAbility(mark);
  }
}


int Alchemist::validator(string potentiallyInvalidInput)
{
 int validInput;
  while (!isdigit(potentiallyInvalidInput.at(0)) || (potentiallyInvalidInput.size() != 1) || (board->getValue(stoi(potentiallyInvalidInput)) == playerOneMark || board->getValue(stoi(potentiallyInvalidInput)) == playerTwoMark) || (stoi(potentiallyInvalidInput) < 1 || stoi(potentiallyInvalidInput) > 9))
  {
    std::cout << "Invalid move, Please try again: ";
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> potentiallyInvalidInput;
  }
  validInput = stoi(potentiallyInvalidInput);
  return validInput;
}