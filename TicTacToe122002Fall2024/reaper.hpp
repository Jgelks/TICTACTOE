#pragma once

#include <string>
#include "board.hpp"
#include "player.hpp"

class Reaper : public Player
{
private:
  Board *board;
  std::string mark;
  int validator(int);
  int selectOneOrTwo();

public:
  Reaper(Board *, std::string);
  std::string getMark() override;
  void move() override;
  void prompt() override;
};
