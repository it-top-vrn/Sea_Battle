#include <iostream>
#include "conio.h"
#include "windows.h"
using namespace std;

void CreateBoard(int** gameBoard, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			gameBoard[i][j] = 0;
		}
	}
}

void OutputBoard(int** gameBoard, int size)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "    1 2 3 4 5 6 7 8 9 10" << endl;
	for (int i = 1; i < size - 1; i++)
	{
		if (i == 10)
		{
			cout << i << " |";
		}
		else
		{
			cout << ' ' << i << " |";
		}
		for (int j = 1; j < size - 1; j++)
		{
			if (gameBoard[i][j] == 0)
			{
				cout << " " << "|";
			}
			else if (gameBoard[i][j] == 5)
			{
				SetConsoleTextAttribute(hConsole, 240);
				cout << "x";
				SetConsoleTextAttribute(hConsole, 15);
				cout << "|";
			}
			else if (gameBoard[i][j] == 6)
			{
				SetConsoleTextAttribute(hConsole, 240);
				cout << "X";
				SetConsoleTextAttribute(hConsole, 15);
				cout << "|";
			}
			else if (gameBoard[i][j] == 10)
			{
				cout << "*" << "|";
			}
			else if ((gameBoard[i][j] == 1 || gameBoard[i][j] == 2 || gameBoard[i][j] == 3 || gameBoard[i][j] == 4)
				&& gameBoard[i][j + 1] == 0)
			{
				SetConsoleTextAttribute(hConsole, 240);
				cout << " ";
				SetConsoleTextAttribute(hConsole, 15);
				cout << "|";
			}
			else if (gameBoard[i][j] == 1 || gameBoard[i][j] == 2 || gameBoard[i][j] == 3 || gameBoard[i][j] == 4)
			{
				SetConsoleTextAttribute(hConsole, 240);
				cout << " " << "|";
				SetConsoleTextAttribute(hConsole, 15);
			}
		}
		cout << endl;
	}
}

void OutputBoardDisguise(int** gameBoard, int size)
{
	cout << "    1 2 3 4 5 6 7 8 9 10" << endl;
	for (int i = 1; i < size - 1; i++)
	{
		if (i == 10)
		{
			cout << i << " |";
		}
		else
		{
			cout << ' ' << i << " |";
		}
		for (int j = 1; j < size - 1; j++)
		{
			if (gameBoard[i][j] == 0)
			{
				cout << " " << "|";
			}
			else if (gameBoard[i][j] == 5)
			{
				cout << "x" << "|";
			}
			else if (gameBoard[i][j] == 6)
			{
				cout << "X" << "|";
			}
			else if (gameBoard[i][j] == 10)
			{
				cout << "*" << "|";
			}
			else if (gameBoard[i][j] == 1 || gameBoard[i][j] == 2 || gameBoard[i][j] == 3 || gameBoard[i][j] == 4)
			{
				cout << " " << "|";
			}
		}
		cout << endl;
	}
}

void OutputBoardPrototype(int** gameBoard, int** gameBoardTemp, int size, char shipDirection, int startPointRow, int startPointCol, int value)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			gameBoardTemp[i][j] = gameBoard[i][j];
		}
	}

	if (shipDirection == 'g')
	{
		for (int l = 0; l < value; l++)
		{
			gameBoardTemp[startPointRow][startPointCol + l] = value;
		}
	}
	else if (shipDirection == 'v')
	{
		for (int l = 0; l < value; l++)
		{
			gameBoardTemp[startPointRow + l][startPointCol] = value;
		}
	}
	else
	{
		cout << "Что-то не так с направлением " << endl;
	}

	cout << "    1 2 3 4 5 6 7 8 9 10" << endl;
	for (int i = 1; i < size - 1; i++)
	{
		if (i == 10)
		{
			cout << i << " |";
		}
		else
		{
			cout << ' ' << i << " |";
		}
		for (int j = 1; j < size - 1; j++)
		{
			if (gameBoardTemp[i][j] == 0)
			{
				cout << " " << "|";
			}
			else if (gameBoardTemp[i][j] == 5)
			{
				SetConsoleTextAttribute(hConsole, 240);
				cout << "x";
				SetConsoleTextAttribute(hConsole, 15);
				cout << "|";
			}
			else if (gameBoardTemp[i][j] == 6)
			{
				SetConsoleTextAttribute(hConsole, 240);
				cout << "X";
				SetConsoleTextAttribute(hConsole, 15);
				cout << "|";
			}
			else if (gameBoardTemp[i][j] == 10)
			{
				cout << "*" << "|";
			}
			else if ((gameBoardTemp[i][j] == 1 || gameBoardTemp[i][j] == 2 || gameBoardTemp[i][j] == 3 || gameBoardTemp[i][j] == 4)
				&& gameBoardTemp[i][j + 1] == 0)
			{
				SetConsoleTextAttribute(hConsole, 240);
				cout << " ";
				SetConsoleTextAttribute(hConsole, 15);
				cout << "|";
			}
			else if (gameBoardTemp[i][j] == 1 || gameBoardTemp[i][j] == 2 || gameBoardTemp[i][j] == 3 || gameBoardTemp[i][j] == 4)
			{
				SetConsoleTextAttribute(hConsole, 240);
				cout << " " << "|";
				SetConsoleTextAttribute(hConsole, 15);
			}
		}
		cout << endl;
	}
	cout << "Control by arrows, press Space to change ship direction, press Enter to arrange ship on the game board" << endl;
}

void InitBoardPrototype(int** gameBoard, int** gameBoardTemp, int size)
{
	char shipDirection;
	int startPointRow, startPointCol, pushButton;
	bool chekShipNearby = true;
	
	startPointRow = 1;
	startPointCol = 1;
	shipDirection = 'g';
	do
	{	
		//four-deckers ship
		system("cls");
		OutputBoardPrototype(gameBoard, gameBoardTemp, size, shipDirection, startPointRow, startPointCol, 4);
		cout << "Let arrange four-deckers ship " << endl;
		pushButton = _getch();
		if (pushButton == 224) //push
		{
			pushButton = _getch();
		}
	
		if (pushButton == 72) //up
		{
			if (startPointRow > 1)
			{
				startPointRow--;
			}
		}
		else if (pushButton == 80) //down
		{
			if (startPointRow < 10)
			{
				if ((shipDirection == 'g') || (shipDirection == 'v' && startPointRow < 7))
				{
					startPointRow++;
				}
			}
		}
		else if (pushButton == 75) //left
		{
			if (startPointCol > 1)
			{
				startPointCol--;
			}
		}
		else if (pushButton == 77) //right
		{
			if (startPointCol < 10)
			{
				if ((shipDirection == 'v') || (shipDirection == 'g' && startPointCol < 7))
				{
					startPointCol++;
				}		
			}
		}
		else if (pushButton == 32) //space
		{
			if (shipDirection == 'g')
			{
				shipDirection = 'v';
				if (startPointRow > 7)
				{
					startPointRow = 7;
				}
			}
			else if (shipDirection == 'v')
			{
				shipDirection = 'g';
				if (startPointCol > 7)
				{
					startPointCol = 7;
				}
			}
		}
		else if (pushButton == 13) //enter
		{
			if (shipDirection == 'g')
			{
				for (int l = 0; l < 4; l++)
				{
					gameBoard[startPointRow][startPointCol + l] = 4;
				}
				break;
			}
			else if (shipDirection == 'v')
			{
				for (int l = 0; l < 4; l++)
				{
					gameBoard[startPointRow + l][startPointCol] = 4;
				}
				break;
			}
		}
	} while (true);
	//tree-deckers ships
	system("cls");
	OutputBoard(gameBoard, size);
	for (int i = 0; i < 2; i++)
	{
		startPointRow = 1;
		startPointCol = 1;
		shipDirection = 'g';
		do
		{
			system("cls");
			OutputBoardPrototype(gameBoard, gameBoardTemp, size, shipDirection, startPointRow, startPointCol, 3);
			cout << "Let arrange two three-deckers ship " << endl;
			pushButton = _getch();
			if (pushButton == 224) //push
			{
				pushButton = _getch();
			}

			if (pushButton == 72) //up
			{
				if (startPointRow > 1)
				{
					startPointRow--;
				}
			}
			else if (pushButton == 80) //down
			{
				if (startPointRow < 10)
				{
					if ((shipDirection == 'g') || (shipDirection == 'v' && startPointRow < 8))
					{
						startPointRow++;
					}
				}
			}
			else if (pushButton == 75) //left
			{
				if (startPointCol > 1)
				{
					startPointCol--;
				}
			}
			else if (pushButton == 77) //right
			{
				if (startPointCol < 10)
				{
					if ((shipDirection == 'v') || (shipDirection == 'g' && startPointCol < 8))
					{
						startPointCol++;
					}
				}
			}
			else if (pushButton == 32) //space
			{
				if (shipDirection == 'g')
				{
					shipDirection = 'v';
					if (startPointRow > 8)
					{
						startPointRow = 8;
					}
				}
				else if (shipDirection == 'v')
				{
					shipDirection = 'g';
					if (startPointCol > 8)
					{
						startPointCol = 8;
					}
				}
			}
			else if (pushButton == 13) //enter
			{
				chekShipNearby = true;
				
				if (shipDirection == 'g')
				{
					for (int j = 0; j < 3; j++)
					{
						for (int k = 0; k < 5; k++)
						{
							if (gameBoard[startPointRow - 1 + j][startPointCol - 1 + k] != 0)
							{
								chekShipNearby = false;
							}
						}
					}
					if (startPointCol <= 8 && chekShipNearby)
					{
						for (int l = 0; l < 3; l++)
						{
							gameBoard[startPointRow][startPointCol + l] = 3;
						}
						break;
					}
					else
					{
						cout << "The ship is out of the game board or srapes other ships " << endl;
					}
				}
				else if (shipDirection == 'v')
				{
					for (int j = 0; j < 3; j++)
					{
						for (int k = 0; k < 5; k++)
						{
							if (gameBoard[startPointRow - 1 + k][startPointCol - 1 + j] != 0)
							{
								chekShipNearby = false;
							}
						}
					}
					if (startPointRow <= 8 && chekShipNearby)
					{
						for (int l = 0; l < 3; l++)
						{
							gameBoard[startPointRow + l][startPointCol] = 3;
						}
						break;
					}
					else
					{
						cout << "The ship is out of the game board or srapes other ships " << endl;
					}
				}
			}
		} while (true);
	}
	//two-deckers ships
	system("cls");
	OutputBoard(gameBoard, size);
	for (int i = 0; i < 3; i++)
	{
		startPointRow = 1;
		startPointCol = 1;
		shipDirection = 'g';
		do
		{
			system("cls");
			OutputBoardPrototype(gameBoard, gameBoardTemp, size, shipDirection, startPointRow, startPointCol, 2);
			cout << "Let arrange three two-deckers ship " << endl;
			pushButton = _getch();
			if (pushButton == 224) //push
			{
				pushButton = _getch();
			}

			if (pushButton == 72) //up
			{
				if (startPointRow > 1)
				{
					startPointRow--;
				}
			}
			else if (pushButton == 80) //down
			{
				if (startPointRow < 10)
				{
					if ((shipDirection == 'g') || (shipDirection == 'v' && startPointRow < 9))
					{
						startPointRow++;
					}
				}
			}
			else if (pushButton == 75) //left
			{
				if (startPointCol > 1)
				{
					startPointCol--;
				}
			}
			else if (pushButton == 77) //right
			{
				if (startPointCol < 10)
				{
					if ((shipDirection == 'v') || (shipDirection == 'g' && startPointCol < 9))
					{
						startPointCol++;
					}
				}
			}
			else if (pushButton == 32) //space
			{
				if (shipDirection == 'g')
				{
					shipDirection = 'v';
					if (startPointRow > 9)
					{
						startPointRow = 9;
					}
				}
				else if (shipDirection == 'v')
				{
					shipDirection = 'g';
					if (startPointCol > 9)
					{
						startPointCol = 9;
					}
				}
			}
			else if (pushButton == 13) //enter
			{
				chekShipNearby = true;

				if (shipDirection == 'g')
				{
					for (int j = 0; j < 3; j++)
					{
						for (int k = 0; k < 4; k++)
						{
							if (gameBoard[startPointRow - 1 + j][startPointCol - 1 + k] != 0)
							{
								chekShipNearby = false;
							}
						}
					}
					if (startPointCol <= 9 && chekShipNearby)
					{
						for (int l = 0; l < 2; l++)
						{
							gameBoard[startPointRow][startPointCol + l] = 2;
						}
						break;
					}
					else
					{
						cout << "The ship is out of the game board or srapes other ships " << endl;
					}
				}
				else if (shipDirection == 'v')
				{
					for (int j = 0; j < 3; j++)
					{
						for (int k = 0; k < 4; k++)
						{
							if (gameBoard[startPointRow - 1 + k][startPointCol - 1 + j] != 0)
							{
								chekShipNearby = false;
							}
						}
					}
					if (startPointRow <= 9 && chekShipNearby)
					{
						for (int l = 0; l < 2; l++)
						{
							gameBoard[startPointRow + l][startPointCol] = 2;
						}
						break;
					}
					else
					{
						cout << "The ship is out of the game board or srapes other ships " << endl;
					}
				}
			}
		} while (true);
	}
	//one-deckers ships
	system("cls");
	OutputBoard(gameBoard, size);
	for (int i = 0; i < 4; i++)
	{
		startPointRow = 1;
		startPointCol = 1;
		shipDirection = 'g';
		do
		{
			system("cls");
			OutputBoardPrototype(gameBoard, gameBoardTemp, size, shipDirection, startPointRow, startPointCol, 1);
			cout << "Let arrange four one-decker ship " << endl;
			pushButton = _getch();
			if (pushButton == 224) //push
			{
				pushButton = _getch();
			}
			if (pushButton == 72) //up
			{
				if (startPointRow > 1)
				{
					startPointRow--;
				}
			}
			else if (pushButton == 80) //down
			{
				if (startPointRow < 10)
				{
					startPointRow++;
				}
			}
			else if (pushButton == 75) //left
			{
				if (startPointCol > 1)
				{
					startPointCol--;
				}
			}
			else if (pushButton == 77) //right
			{
				if (startPointCol < 10)
				{
					startPointCol++;
				}
			}
			else if (pushButton == 13) //enter
			{
				chekShipNearby = true;
				for (int j = 0; j < 3; j++)
				{
					for (int k = 0; k < 3; k++)
					{
						if (gameBoard[startPointRow - 1 + j][startPointCol - 1 + k] != 0)
						{
							chekShipNearby = false;
						}
					}
				}
				if (startPointCol <= 10 && chekShipNearby)
				{
					gameBoard[startPointRow][startPointCol] = 1;
					break;
				}
				else
				{
					cout << "The ship is out of the game board or srapes other ships " << endl;
				}
			}
		} while (true);
	}
}
