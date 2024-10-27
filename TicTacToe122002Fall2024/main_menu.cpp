#include <iostream>

#include "battle_tic_tac_toe.hpp"
#include "board.hpp"
#include "rules.hpp"
#include "tic_tac_toe.hpp"
#include "board_printer.hpp"
#include "main_menu.hpp"
#include "goblin.hpp"
#include "reaper.hpp"

void MainMenu::printWelcomeMessage()
{
  std::cout << "Welcome to TTT!" << endl;
  std::cout << "Choose an Option!" << endl;
  std::cout << "(1) Regular TTT" << endl;
  std::cout << "(2) Battle TTT" << endl;
}

void MainMenu::printPlayAgainMessage()
{
  std::cout << "Do you want to play again?" << endl;
  std::cout << "(1) Yes" << endl;
  std::cout << "(2) No" << endl;
}

void MainMenu::printExitMessage()
{
  std::cout << "Goodbye!" << endl;
}

void MainMenu::buildAndPlayGame(int option)
{
  Board *board = new Board();
  Rules *rules = new Rules(board);
  BoardPrinter *boardPrinter = new BoardPrinter(board);
  if (option == 1)
  {
    TicTacToe *ticTacToe = new TicTacToe(rules, board, boardPrinter);
    ticTacToe->start();
    delete ticTacToe;
  }
  else
  {
    std::cout << "This might be a good time to allow each player to choose their marks!" << std::endl;
    std::cout << "But I am just going to hardcode X and O for now..." << std::endl;
    std::cout << "Also, helpful note for those of you reading this - be sure to update Peasant#validator to handle custom marks!" << std::endl;

    Player *playerOne = new Goblin(board, "X");
    Player *playerTwo = new Reaper(board, "O");

    BattleTicTacToe *battleTicTacToe = new BattleTicTacToe(rules, board, boardPrinter, playerOne, playerTwo);
    battleTicTacToe->start();
    delete battleTicTacToe;
    delete playerOne;
    delete playerTwo;
  }

  delete board;
  delete rules;
  delete boardPrinter;
}

void MainMenu::playAgainOrExit()
{
  if (selectOneOrTwo() == 1)
  {
    start();
  }
  else
  {
    printExitMessage();
  }
}

int MainMenu::selectOneOrTwo()
{
  int option;
  std::cin >> option;
  return option;
}

void MainMenu::start()
{
  printWelcomeMessage();
  buildAndPlayGame(selectOneOrTwo());
  printPlayAgainMessage();
  playAgainOrExit();
}
