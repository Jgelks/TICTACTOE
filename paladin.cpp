#include <iostream>

#include "paladin.hpp"

extern string playerOneMark;
extern string playerTwoMark;

Paladin::Paladin(Board *board, std::string mark)
{
  this->board = board;
  this->mark = mark;
}

std::string Paladin::getMark()
{
  return mark;
}

void Paladin::prompt()
{
  std::cout << "I'm ready to smite my foes!" << std::endl;
  std::cout << "(1) Make a move" << std::endl;
  std::cout << "(2) Use your special power to destroy everything on the board" << std::endl;
}

int Paladin::selectOneOrTwo()
{
  int option;
  std::cin >> option;
  return option;
}

void Paladin::move()
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
    std::cout << "Give me power!" << std::endl;
    board->paladinAbility();
  }
}

int Paladin::validator(string potentiallyInvalidInput)
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
