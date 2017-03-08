#include "board.hpp"
#include "metaboard.hpp"

#include <iostream>



using namespace std;

Metaboard::Metaboard()
{
	met[0] = Board();
	met[1] = Board();
	met[2] = Board();
	met[3] = Board();
	met[4] = Board();
	met[5] = Board();
	met[6] = Board();
	met[7] = Board();
	met[8] = Board();
}

Metaboard::~Metaboard()
{

}

void Metaboard::PrintBoard()
{
 	cout << endl;
 	cout << met[0].squares[0] << " | " << met[0].squares[1] << " | "<< met[0].squares[2] << "        " << met[1].squares[0] << met[1].squares[1] << met[1].squares[2] << "        " << << met[2].squares[0] << met[2].squares[1] << met[2].squares[2] << endl;
 	cout << met[0].squares[0] << " | " << met[0].squares[1] << " | "<< met[0].squares[2] << "        " << met[1].squares[0] << met[1].squares[1] << met[1].squares[2] << "        " << << met[2].squares[0] << met[2].squares[1] << met[2].squares[2] << endl;
 	cout << met[0].squares[0] << " | " << met[0].squares[1] << " | "<< met[0].squares[2] << "        " << met[1].squares[0] << met[1].squares[1] << met[1].squares[2] << "        " << << met[2].squares[0] << met[2].squares[1] << met[2].squares[2] << endl;
 	cout << endl <<endl;

 	cout << met[0].squares[0] << " | " << met[0].squares[1] << " | "<< met[0].squares[2] << "        " << met[1].squares[0] << met[1].squares[1] << met[1].squares[2] << "        " << << met[2].squares[0] << met[2].squares[1] << met[2].squares[2] << endl;
 	cout << met[0].squares[0] << " | " << met[0].squares[1] << " | "<< met[0].squares[2] << "        " << met[1].squares[0] << met[1].squares[1] << met[1].squares[2] << "        " << << met[2].squares[0] << met[2].squares[1] << met[2].squares[2] << endl;
 	cout << met[0].squares[0] << " | " << met[0].squares[1] << " | "<< met[0].squares[2] << "        " << met[1].squares[0] << met[1].squares[1] << met[1].squares[2] << "        " << << met[2].squares[0] << met[2].squares[1] << met[2].squares[2] << endl;
 	cout << endl <<endl;

 	cout << met[0].squares[0] << " | " << met[0].squares[1] << " | "<< met[0].squares[2] << "        " << met[1].squares[0] << met[1].squares[1] << met[1].squares[2] << "        " << << met[2].squares[0] << met[2].squares[1] << met[2].squares[2] << endl;
 	cout << met[0].squares[0] << " | " << met[0].squares[1] << " | "<< met[0].squares[2] << "        " << met[1].squares[0] << met[1].squares[1] << met[1].squares[2] << "        " << << met[2].squares[0] << met[2].squares[1] << met[2].squares[2] << endl;
 	cout << met[0].squares[0] << " | " << met[0].squares[1] << " | "<< met[0].squares[2] << "        " << met[1].squares[0] << met[1].squares[1] << met[1].squares[2] << "        " << << met[2].squares[0] << met[2].squares[1] << met[2].squares[2] << endl;
 	cout << endl <<endl;

 	 	cout << met[0].squares[0] << " | " << met[0].squares[1] << " | "<< met[0].squares[2] << "        " << met[1].squares[0] << met[1].squares[1] << met[1].squares[2] << "        " << << met[2].squares[0] << met[2].squares[1] << met[2].squares[2] << endl;
 	cout << met[0].squares[0] << " | " << met[0].squares[1] << " | "<< met[0].squares[2] << "        " << met[1].squares[0] << met[1].squares[1] << met[1].squares[2] << "        " << << met[2].squares[0] << met[2].squares[1] << met[2].squares[2] << endl;
 	cout << met[0].squares[0] << " | " << met[0].squares[1] << " | "<< met[0].squares[2] << "        " << met[1].squares[0] << met[1].squares[1] << met[1].squares[2] << "        " << << met[2].squares[0] << met[2].squares[1] << met[2].squares[2] << endl;
 	cout << endl <<endl;

 	cout << met[0].squares[0] << " | " << met[0].squares[1] << " | "<< met[0].squares[2] << "        " << met[1].squares[0] << met[1].squares[1] << met[1].squares[2] << "        " << << met[2].squares[0] << met[2].squares[1] << met[2].squares[2] << endl;
 	cout << met[0].squares[0] << " | " << met[0].squares[1] << " | "<< met[0].squares[2] << "        " << met[1].squares[0] << met[1].squares[1] << met[1].squares[2] << "        " << << met[2].squares[0] << met[2].squares[1] << met[2].squares[2] << endl;
 	cout << met[0].squares[0] << " | " << met[0].squares[1] << " | "<< met[0].squares[2] << "        " << met[1].squares[0] << met[1].squares[1] << met[1].squares[2] << "        " << << met[2].squares[0] << met[2].squares[1] << met[2].squares[2] << endl;
 	cout << endl <<endl;

 	cout << met[0].squares[0] << " | " << met[0].squares[1] << " | "<< met[0].squares[2] << "        " << met[1].squares[0] << met[1].squares[1] << met[1].squares[2] << "        " << << met[2].squares[0] << met[2].squares[1] << met[2].squares[2] << endl;
 	cout << met[0].squares[0] << " | " << met[0].squares[1] << " | "<< met[0].squares[2] << "        " << met[1].squares[0] << met[1].squares[1] << met[1].squares[2] << "        " << << met[2].squares[0] << met[2].squares[1] << met[2].squares[2] << endl;
 	cout << met[0].squares[0] << " | " << met[0].squares[1] << " | "<< met[0].squares[2] << "        " << met[1].squares[0] << met[1].squares[1] << met[1].squares[2] << "        " << << met[2].squares[0] << met[2].squares[1] << met[2].squares[2] << endl;
 	cout << endl <<endl;


 	 	cout << met[0].squares[0] << " | " << met[0].squares[1] << " | "<< met[0].squares[2] << "        " << met[1].squares[0] << met[1].squares[1] << met[1].squares[2] << "        " << << met[2].squares[0] << met[2].squares[1] << met[2].squares[2] << endl;
 	cout << met[0].squares[0] << " | " << met[0].squares[1] << " | "<< met[0].squares[2] << "        " << met[1].squares[0] << met[1].squares[1] << met[1].squares[2] << "        " << << met[2].squares[0] << met[2].squares[1] << met[2].squares[2] << endl;
 	cout << met[0].squares[0] << " | " << met[0].squares[1] << " | "<< met[0].squares[2] << "        " << met[1].squares[0] << met[1].squares[1] << met[1].squares[2] << "        " << << met[2].squares[0] << met[2].squares[1] << met[2].squares[2] << endl;
 	cout << endl <<endl;

 	cout << met[0].squares[0] << " | " << met[0].squares[1] << " | "<< met[0].squares[2] << "        " << met[1].squares[0] << met[1].squares[1] << met[1].squares[2] << "        " << << met[2].squares[0] << met[2].squares[1] << met[2].squares[2] << endl;
 	cout << met[0].squares[0] << " | " << met[0].squares[1] << " | "<< met[0].squares[2] << "        " << met[1].squares[0] << met[1].squares[1] << met[1].squares[2] << "        " << << met[2].squares[0] << met[2].squares[1] << met[2].squares[2] << endl;
 	cout << met[0].squares[0] << " | " << met[0].squares[1] << " | "<< met[0].squares[2] << "        " << met[1].squares[0] << met[1].squares[1] << met[1].squares[2] << "        " << << met[2].squares[0] << met[2].squares[1] << met[2].squares[2] << endl;
 	cout << endl <<endl;

 	cout << met[0].squares[0] << " | " << met[0].squares[1] << " | "<< met[0].squares[2] << "        " << met[1].squares[0] << met[1].squares[1] << met[1].squares[2] << "        " << << met[2].squares[0] << met[2].squares[1] << met[2].squares[2] << endl;
 	cout << met[0].squares[0] << " | " << met[0].squares[1] << " | "<< met[0].squares[2] << "        " << met[1].squares[0] << met[1].squares[1] << met[1].squares[2] << "        " << << met[2].squares[0] << met[2].squares[1] << met[2].squares[2] << endl;
 	cout << met[0].squares[0] << " | " << met[0].squares[1] << " | "<< met[0].squares[2] << "        " << met[1].squares[0] << met[1].squares[1] << met[1].squares[2] << "        " << << met[2].squares[0] << met[2].squares[1] << met[2].squares[2] << endl;
 	cout << endl <<endl;

 	
 	

	
}

void Metaboard::Place(int active, int loc, char turn)
{
	met[active-1].Place(loc, turn);
}

int Metaboard::CheckWin(int active)
{
	return met[active-1].CheckWin();
}

bool Metaboard::CheckGameOver()
{
	for (int i = 0 ; i < 9 ; i++){
		if (met[i].CheckWin() != 3)
		{
			return false;
		}


	}
	return true;
}