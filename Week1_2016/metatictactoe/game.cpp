#include "metaboard.cpp"
#include "game.hpp"



#include <iostream>




using namespace std;

/** 
* @brief Creates a new game
*/

Game::Game()
{
	metaGameBoard = Metaboard();
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
	
	int count = 0;
	int doneBoards[9];
	int choice = 0;
	int winner = 0;
	int activeboard = 0;
	int X = 0;
	int O = 0;
	bool active = true;
	metaGameBoard.PrintBoard();
	cout<<"Which board would you like to start on (1-9)? " << endl;
	cin >> activeboard;
	do
	{
		active = true;
		metaGameBoard.PrintBoard();
		cout << "Where would you like to place your piece (1-9)? " << endl;
		cin >> choice;

		metaGameBoard.Place(activeboard, choice, turn);
		winner = metaGameBoard.CheckWin(activeboard);
		activeboard = choice;

		for (int i = 0; i < count ; i++){
			if (doneBoards[i] == activeboard){
				active = false;
			}
		}
		if (winner == 1 && active == true )
		{
			X += 1;
			doneBoards[count] = activeboard;
			count += 1;
		}

		if (winner == 2  && active == true )
		{
			O += 1;
			doneBoards[count] = activeboard;
			count += 1;
		}

		if (winner == 3  && active == true )
		{
			doneBoards[count] = activeboard;
			count += 1;
			cout << "Which board would you like to go to (1-9)? ";
			cin >> activeboard;
		}

		this->toggleTurns();
	}

	while (metaGameBoard.CheckGameOver() == false);
}