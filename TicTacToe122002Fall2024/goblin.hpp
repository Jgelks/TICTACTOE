#pragma once

#include <string>
#include "board.hpp"
#include "player.hpp"

class Goblin : public Player
{
private:
  Board *board;
  std::string mark;
  int validator(int);

public:
  Goblin(Board *, std::string);
  std::string getMark() override;
  void move() override;
  void prompt() override;
};
