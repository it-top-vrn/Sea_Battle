#include <iostream>
using namespace std;

int Shoot(int** gameBoard, int size)
{
	int shootRow, shootCol;
	cout << "Enter the coordinates of the shot(row) ";
	cin >> shootRow; cout << endl;
	cout << "Enter the coordinates of the shot(column) ";
	cin >> shootCol; cout << endl;
	if (gameBoard[shootRow][shootCol] == 1 || gameBoard[shootRow][shootCol] == 2 ||
		gameBoard[shootRow][shootCol] == 3 || gameBoard[shootRow][shootCol] == 4)
	{
		gameBoard[shootRow][shootCol] = 5;
		return 1;
	}
	else if (gameBoard[shootRow][shootCol] == 0)
	{
		gameBoard[shootRow][shootCol] = 10;
		return 0;
	}
	else if (gameBoard[shootRow][shootCol] == 5 || gameBoard[shootRow][shootCol] == 6 || gameBoard[shootRow][shootCol] == 10)
	{
		cout << "You already shot at this position " << endl;
		return 0;
	}
}