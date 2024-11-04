#include <iostream>

#include "ballista.hpp"
#include "battle_tic_tac_toe.hpp"
extern string playerOneMark;
extern string playerTwoMark;

Ballista::Ballista(Board *board, std::string mark)
{
  this->board = board;
  this->mark = mark;
}

std::string Ballista::getMark()
{
  return mark;
}

void Ballista::prompt()
{
  std::cout << "Foolish mortal..." << std::endl;
  std::cout << "I am the ballister of worlds..." << std::endl;
  std::cout << "Do you want to..." << std::endl;
  std::cout << "(1) Make a move" << std::endl;
  std::cout << "(2) Use your special power to destroy everything on the board" << std::endl;
}

int Ballista::selectOneOrTwo()
{
  int option;
  std::cin >> option;
  return option;
}

void Ballista::move()
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
    std::cout << "Behold my ballisting power..." << std::endl;
    board->ballistaAbility();
  }
}

int Ballista::validator(string potentiallyInvalidInput)
{
 int validInput;
  while (!isdigit(potentiallyInvalidInput.at(0)) || (potentiallyInvalidInput.size() != 1) || (board->getValue(stoi(potentiallyInvalidInput)) == playerOneMark || board->getValue(stoi(potentiallyInvalidInput)) == playerTwoMark) || (stoi(potentiallyInvalidInput) < 1 || stoi(potentiallyInvalidInput) > 9))
  {
    std::cout << "Invalid move, Please try againgob: ";
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> potentiallyInvalidInput;
  }
  validInput = stoi(potentiallyInvalidInput);
  return validInput;
}