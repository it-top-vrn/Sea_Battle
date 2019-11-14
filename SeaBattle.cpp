
#include <iostream>
#include "conio.h"
#include "windows.h"
#include "ioarray.h"
#include "play.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	const int SIZE = 12;
	int** gameBoard1 = new int* [SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		gameBoard1[i] = new int[SIZE];
	}
	int** gameBoard2 = new int* [SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		gameBoard2[i] = new int[SIZE];
	}
	int** gameBoardTemp = new int* [SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		gameBoardTemp[i] = new int[SIZE];
	}

	int lifeCounter1 = 0;
	int lifeCounter2 = 0;

	CreateBoard(gameBoard1, SIZE);
	CreateBoard(gameBoard2, SIZE);
	cout << "First player board " << endl;
	OutputBoard(gameBoard1, SIZE);
	cout << "Second player board " << endl;
	OutputBoard(gameBoard2, SIZE);
	cout << "Let arrange first player ships " << endl;
	InitBoardPrototype(gameBoard1, gameBoardTemp, SIZE);
	cout << "Let arrange second player ships " << endl;
	InitBoardPrototype(gameBoard2, gameBoardTemp, SIZE);
	system("cls");
	cout << "First player board " << endl;
	OutputBoard(gameBoard1, SIZE);
	cout << "Second player board " << endl;
	OutputBoard(gameBoard2, SIZE);

	do
	{
		//First player shooting
		do
		{
			system("cls");
			cout << "First player shot " << endl;
			cout << "Second player board with disguise " << endl;
			OutputBoardDisguise(gameBoard2, SIZE);
			cout << "First player board" << endl;
			OutputBoard(gameBoard1, SIZE);
			if (Shoot(gameBoard2, SIZE) == 0)
			{
				system("cls");
				cout << "Second player board with disguise " << endl;
				OutputBoardDisguise(gameBoard2, SIZE);
				break;
			}
			else
			{
				system("cls");
				cout << "Second player board with disguise" << endl;
				OutputBoardDisguise(gameBoard2, SIZE);
				lifeCounter2++;
				if (lifeCounter2 >= 20)
				{
					break;
				}
			}

		} while (true);

		if (lifeCounter1 >= 20 || lifeCounter2 >= 20)
		{
			break;
		}
		
		//Second player shooting
		do
		{
			system("cls");
			cout << "Second player shot " << endl;
			cout << "First player board with disguise" << endl;
			OutputBoardDisguise(gameBoard1, SIZE);
			cout << "Second player board" << endl;
			OutputBoard(gameBoard2, SIZE);
			if (Shoot(gameBoard1, SIZE) == 0)
			{
				system("cls");
				cout << "First player board with disguise" << endl;
				OutputBoardDisguise(gameBoard1, SIZE);
				break;
			}
			else
			{
				system("cls");
				cout << "First player board with disguise " << endl;
				OutputBoardDisguise(gameBoard1, SIZE);
				lifeCounter1++;
				if (lifeCounter1 >= 20)
				{
					break;
				}
			}

		} while (true);

		if (lifeCounter1 >= 20 || lifeCounter2 >= 20)
		{
			break;
		}
	} while (true);

	if (lifeCounter1 >= 20)
	{
		system("cls");
		cout << "First player board " << endl;
		OutputBoard(gameBoard1, SIZE);
		cout << "Second player have won " << endl;
	}
	else if (lifeCounter2 >= 20)
	{
		system("cls");
		cout << "Second player board " << endl;
		OutputBoard(gameBoard2, SIZE);
		cout << "First player have won " << endl;
	}
	else
	{
		cout << "Something wrong with player's lifes " << endl;
	}

	cout << "BUT SERGEY IS ETREMELY GOOD BOY" << endl;

	for (int i = 0; i < SIZE; i++)
	{
		delete[] gameBoard1[i];
	}
	for (int i = 0; i < SIZE; i++)
	{
		delete[] gameBoard2[i];
	}
	for (int i = 0; i < SIZE; i++)
	{
		delete[] gameBoardTemp[i];
	}
}
