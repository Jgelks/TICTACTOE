#pragma once

#include <string>
#include "board.hpp"
#include "player.hpp"

class Ballista : public Player
{
private:
  Board *board;
  std::string mark;
  int validator(string);
  int selectOneOrTwo();

public:
  Ballista(Board *, std::string);
  std::string getMark() override;
  void move() override;
  void prompt() override;
};
