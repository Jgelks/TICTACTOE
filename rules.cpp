#include "rules.hpp"

#include <iostream>

using namespace std;

Rules::Rules(Board *board)
{
  this->board = board;
  winningCombos[0][0] = 1;
  winningCombos[0][1] = 2;
  winningCombos[0][2] = 3;

  winningCombos[1][0] = 4;
  winningCombos[1][1] = 5;
  winningCombos[1][2] = 6;

  winningCombos[2][0] = 7;
  winningCombos[2][1] = 8;
  winningCombos[2][2] = 9;

  winningCombos[3][0] = 1;
  winningCombos[3][1] = 4;
  winningCombos[3][2] = 7;

  winningCombos[4][0] = 2;
  winningCombos[4][1] = 5;
  winningCombos[4][2] = 8;

  winningCombos[5][0] = 3;
  winningCombos[5][1] = 6;
  winningCombos[5][2] = 9;

  winningCombos[6][0] = 1;
  winningCombos[6][1] = 5;
  winningCombos[6][2] = 9;

  winningCombos[7][0] = 3;
  winningCombos[7][1] = 5;
  winningCombos[7][2] = 7;
}

bool Rules::inProgress()
{
  for (int i = 0; i < 8; i++)
  {
    if (this->threeInARow(winningCombos[i][0], winningCombos[i][1], winningCombos[i][2]))
    {
      return false;
    }
  }
  if (board->full())
  {
    return false;
  }
  return true;
}

int Rules::validator(int potentiallyInvalidInput)
{
  int validInput = potentiallyInvalidInput;
  while ((board->getValue(validInput) == "X" || board->getValue(validInput) == "O") || (validInput < 0 || validInput > 9))
  {
    cout << "Invalid move, Please try again: ";
    cin >> validInput;
  }
  return validInput;
}

string Rules::status()
{
  for (int i = 0; i < 8; i++)
  {
    if (this->threeInARow(winningCombos[i][0], winningCombos[i][1], winningCombos[i][2]))
    {
      return board->getValue(winningCombos[i][0]) + " wins the game!";
    }
  }

  if (board->full())
  {
    return "Tie game!";
  }

  return "";
}

bool Rules::threeInARow(int indexOne, int indexTwo, int indexThree)
{
  return board->getValue(indexOne) == board->getValue(indexTwo) && board->getValue(indexTwo) == board->getValue(indexThree);
}
