#pragma once

#include <string>
#include "board.hpp"
#include "player.hpp"

class Alchemist : public Player
{
private:
  Board *board;
  std::string mark;
  int validator(string);
  int selectOneOrTwo();

public:
  Alchemist(Board *, std::string);
  std::string getMark() override;
  void move() override;
  void prompt() override;
};
