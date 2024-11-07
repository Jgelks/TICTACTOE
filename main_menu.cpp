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
  string archetypeChoice = "choose your archetype:\n1. Alchemist\n2. Ballista\n3. Paladin";

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
   
    bool P1markValid = false;
    bool P2markValid = false;
    while(!P1markValid){
    std::cout << "Player one choose your mark!" << std::endl;
    std::cin >> playerOneMark;
    if (playerOneMark.size() != 1){
      std::cout << "Your mark must be one character!" << endl;
    }
    else{P1markValid = true;}
    }
    while(!P2markValid){
    
    std::cout << "Player two choose your mark!" << std::endl;
    std::cin >> playerTwoMark;
    if (playerTwoMark.size() != 1 || playerTwoMark == playerOneMark){
      std::cout << "Your mark must be one character and cannot be the same as Player One!" << endl;
    }
    else{P2markValid = true;}
    }

    Player *playerOne = nullptr;
    Player *playerTwo = nullptr;
    cout << "Player one " << archetypeChoice << endl;

    cin >> playerOneArchetype;
    if (playerOneArchetype == 1){
      playerOne = new Alchemist(board, playerOneMark);
    }
    else if(playerOneArchetype == 2){
      playerOne = new Ballista(board, playerOneMark);
    }
    else if(playerOneArchetype == 3){
      playerOne = new Paladin(board, playerOneMark);
    }
    
    cout << "Player two " << archetypeChoice << endl;

    cin >> playerTwoArchetype;
    if (playerTwoArchetype == 1){
      playerTwo = new Alchemist(board, playerTwoMark);
    }
    else if(playerTwoArchetype == 2){
      playerTwo = new Ballista(board, playerTwoMark);
    }
    else if(playerTwoArchetype == 3){
      playerTwo = new Paladin(board, playerTwoMark);
    }
    

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
