#include "board.hpp"
#include "game.hpp"
#include <iostream>




using namespace std;

/** 
* @brief Creates a new game
*/

Game::Game()
{
	gameBoard = Board();
	turn = 'X';
}

/**
* @brief Destructor for Game
*/


Game::~Game()
{

}

/** 
* @brief Changes turn
* @param none
* @return void
*/


void Game::toggleTurns()
{
	if (turn == 'X')
	{
		turn = 'O';
	}
	else 
	{
		turn = 'X';
	}
}


/** 
* @brief Runs the tic-tac-toe game
* @param None
* @return void
*/

void Game::Run()
{
	int choice;
	int winner;
	

	do
	{
		gameBoard.PrintBoard();
		do{
			cout << "Where would you like to place your piece? ";
			cin >> choice;
		} while ((gameBoard.Query(choice) != 'U') || choice < 1 || choice >9);  //Makes sure the location that is inputted is valid (between 1 and 9 and unoccupied)

		gameBoard.Place(choice, turn);
		winner = gameBoard.CheckWin();
		if (winner == 1)
		{
			gameBoard.PrintBoard();
			cout << endl <<"Player 1('X') wins!" << endl;
		}

		if (winner == 2)
		{
			gameBoard.PrintBoard();
			cout << endl <<"Player 2('O') wins!" << endl;
		}

		if (winner == 3)
		{
			gameBoard.PrintBoard();
			cout << endl<< "Draw!" << endl;
		}

		this->toggleTurns();
	}

	while (gameBoard.CheckWin() == 0);
}