
/*
* @brief A class used to store a tic-tac-toe board
*/
class Board
{
public:
	char squares[9]; // a list of length 9 that keeps track of which spaces are occupied. An int means unoccupied, 'X' and 'O' mean occupied
public:
	Board();
	~Board();
	char Query(int loc); // Outputs whether the specific coordinate is unoccupied ('U'), a X, or a O
	void Place(int loc, char player); // Puts the player's symbol at the specific location
	int CheckWin(); // Checks if anyone won and returns 1 or 2 (corresponding to player 1 and player 2) if the game has been won, returns 0 
					// if still going, returns 3 if tie and game is over
	bool checkDraw(); // Returns true if draw, false if not a draw
	void PrintBoard(); // Prints the current state of the board

};