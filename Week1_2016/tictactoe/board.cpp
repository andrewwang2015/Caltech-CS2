#include <iostream>
#include "board.hpp"
using namespace std;

/**
* @brief Constructs a new tic-tac-toe board all filled with digits representing board locations 
*/

Board::Board()
{
	
	squares[0] = '1';
	squares[1] = '2';
	squares[2] = '3';
	squares[3] = '4';
	squares[4] = '5';
	squares[5] = '6';
	squares[6] = '7';
	squares[7] = '8';
	squares[8] = '9';
}

/**
* @brief Destructor for Board
*/

Board::~Board()
{

}

/**
* @brief Returns whether or not a space is occupied/ unoccupied and if occupied, whether it's an 'X' or 'O'
* @param loc: the location on board
* @return: char representing what is in the location: 'X', 'O', or 'U' (for unoccupied)
*/

char Board::Query(int loc)
{
	if (squares[loc-1] == 'X')
	{
		return 'X';
	}

	else if (squares[loc-1] == 'O')
	{
		return 'O';
	}

	else
	{
		return 'U';     // For unoccupied
	}
}

/**
 * @brief Puts an 'X' or 'O' at specific location
 * @param loc: location on board, player: 'X' or 'O' representing who the player is
 * @return: void
*/

void Board::Place(int loc, char player)
{
	squares[loc-1] = player;
}

/**
* @brief Prints the board to user
* @param: none
* @return: void
*/

void Board::PrintBoard()
{
	cout << endl;
	cout << " " << squares[0] << " | " << squares[1] << " | " << squares[2] << endl;
	cout << "-----------" << endl;
	cout << " "<< squares[3] << " | " << squares[4] << " | " << squares[5] << endl;
	cout << "-----------" << endl;
	cout << " " << squares[6] << " | " << squares[7] << " | " << squares[8] << endl;
	cout << endl;


}

/**
* @brief Checks if anyone won and returns 1 or 2 (corresponding to player 1 and player 2) if the game has been won, returns 0 
* if still going, returns 3 if tie and game is over
* @param: none
* @return: int corresponding to winning player or ongoing game or tie 
*/

int Board::CheckWin()
{

	for (int i = 0; i < 3; i++) // Testing if any columns have the same character
	{
		if (squares[i] == squares[i+3] && squares[i] == squares[i+6])
		{
			if (squares[i] == 'X') {return 1;}
			else {return 2;}
		}
	}

	for (int i = 0; i < 7; i = i + 3) // Testing if any rows have the same character
	{
		if (squares[i] == squares[i+1] && squares[i] == squares[i+2])
		{
			if (squares[i] == 'X') {return 1;}
			else {return 2;}
		}
	}

	if (squares[0] == squares[4] && squares[0] == squares[8]) // Checking diagonal from top left to bottom right
	{
		if (squares[0] == 'X')
		{
			return 1;
		}
		else {return 2;}
	}

	if (squares[2] == squares[4] && squares[2] == squares[6]) // Checking diagonal from top right to bottom left
	{
		if (squares[2] == 'X') {return 1;}
		else {return 2;}
	}

	for (int i = 0; i < 9; i++){			// Checks to make sure that the entire board is filled and if not, then still playing (return 0). Returns 3 if endgame draw.
		if (squares[i] != 'X' && squares[i] != 'O')
		{
			return 0;
		}
	}

	return 3; // If board filled, but no matches then tie.
		

	
}

/**
* @brief Checks for a draw
* @param: none
* @return: bool: true if draw at end of game, false if not a draw
*/

bool Board::checkDraw()
{
	return(CheckWin() == 3);
}


