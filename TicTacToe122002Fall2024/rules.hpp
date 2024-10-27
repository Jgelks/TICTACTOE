#pragma once

#include "board.hpp"

class Rules
{
private:
  Board *board;
  bool turn;
  bool threeInARow(int index_one, int index_two, int index_three);
  int winningCombos[8][3];

public:
  int validator(int);
  string currentTurn();
  Rules(Board *board);
  bool inProgress();
  string status();
};
