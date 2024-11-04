#pragma once

#include <string>

class Player
{
public:
  virtual std::string getMark() = 0;
  virtual void move() = 0;
  virtual void prompt() = 0;
  virtual ~Player() = default;
};
