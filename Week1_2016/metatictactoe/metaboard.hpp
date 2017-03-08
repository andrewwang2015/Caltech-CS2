
class Metaboard
{
public:
	Board met[9];

public:
	Metaboard();
	~Metaboard();
	void PrintBoard();
	void Place(int active, int loc, char turn);
	int CheckWin(int active);
	bool CheckGameOver();

};