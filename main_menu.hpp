#pragma once

class MainMenu
{
private:
  void playAgainOrExit();
  void printExitMessage();
  void printPlayAgainMessage();
  void printWelcomeMessage();
  void buildAndPlayGame(int option);
  int selectOneOrTwo();

public:
  void start();
};
