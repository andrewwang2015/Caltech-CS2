
/*
* @brief Holds the game state of the tic-tac-toe game
*/

class Game
{

private:
	Board gameBoard;
	char turn;   // Designates 'X' or 'O' depending on player 1/ player 2 respectively
public:
	Game();
	~Game();
	void toggleTurns();
	void Run();

};
