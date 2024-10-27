#pragma once

#include <string>

#include "rules.hpp"
#include "board.hpp"
#include "board_printer.hpp"
#include "player.hpp"

class BattleTicTacToe
{
private:
  Rules *rules;
  Board *board;
  BoardPrinter *boardPrinter;
  Player *playerOne;
  Player *playerTwo;
  Player *currentPlayer;

public:
  BattleTicTacToe(Rules *rules, Board *board, BoardPrinter *boardPrinter, Player *playerOne, Player *playerTwo);
  void togglePlayer();
  void start();
};
