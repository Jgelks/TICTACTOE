#include <iostream>

#include "battle_tic_tac_toe.hpp"
#include "board.hpp"
#include "rules.hpp"
#include "tic_tac_toe.hpp"
#include "board_printer.hpp"
#include "main_menu.hpp"
#include "paladin.hpp"
#include "alchemist.hpp"
#include "ballista.hpp"

string playerOneMark;
string playerTwoMark;

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
  int playerOneArchetype;
  int playerTwoArchetype;

  Board *board = new Board();
  Rules *rules = new Rules(board);
  
  // string playerOneMark;
  // string playerTwoMark;
  BoardPrinter *boardPrinter = new BoardPrinter(board);
  if (option == 1)
  {
    TicTacToe *ticTacToe = new TicTacToe(rules, board, boardPrinter);
    ticTacToe->start();
    delete ticTacToe;
  }
  else
  {
    std::cout << "Player one choose your mark!" << std::endl;
    std::cin >> playerOneMark;
    std::cout << "Player two choose your mark!" << std::endl;
    std::cin >> playerTwoMark;
    // std::cout << "Player 1 select your archetype:" << std::endl;
    // std::cout << "1 for Alchemist" << std::endl;
    // std::cout << "2 for Paladin" << std::endl;
    // std::cout << "3 for Ballista" << std::endl;
    // std::cin >> playerOneArchetype;
    // if (playerOneArchetype == 1)
    // {
    //   Player *playerOne = new Alchemist(board, playerOneMark);
    // }
    // else if (playerOneArchetype == 2)
    // {
    //   Player *playerOne = new Paladin(board, playerOneMark);
    // }
    // else if (playerOneArchetype == 3)
    // {
    //   Player *playerOne = new Ballista(board, playerOneMark);
    // }

    // std::cout << "Player 2 select your archetype:" << std::endl;
    // std::cout << "1 for Alchemist" << std::endl;
    // std::cout << "2 for Paladin" << std::endl;
    // std::cout << "3 for Ballista" << std::endl;
    // std::cin >> playerTwoArchetype;
    // if (playerTwoArchetype == 1)
    // {
    //   Player *playerTwo = new Alchemist(board, playerTwoMark);
    // }
    // else if (playerOneArchetype == 2)
    // {
    //   Player *playerTwo = new Paladin(board, playerTwoMark);
    // }
    // else if (playerOneArchetype == 3)
    // {
    //   Player *playerTwo = new Ballista(board, playerTwoMark);
    // }
    Player *playerOne = new Alchemist(board, playerOneMark);
  Player *playerTwo = new Ballista(board, playerTwoMark);

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
