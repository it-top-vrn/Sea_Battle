#pragma once
#ifndef IOARRAY
#define IOARRAY

void CreateBoard(int** gameBoard, int size);
void OutputBoard(int** gameBoard, int size);
void OutputBoardDisguise(int** gameBoard, int size);
void InitBoardPrototype(int** gameBoard, int** gameBoardTemp, int size);
void OutputBoardPrototype(int** gameBoard, int** gameBoardTemp, int size, char shipDirection, int startPointRow, int startPointCol, int value);
#endif
