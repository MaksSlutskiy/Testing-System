#include "Header.h"

void SetConsWinSize(int XSize, int YSize)
{
	HWND hWnd = GetForegroundWindow();
	HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetWindowPos(hWnd, NULL, 180, 180, 0, 0, NULL);
	SMALL_RECT windowSize;
	windowSize.Bottom = YSize;
	windowSize.Left = 0;
	windowSize.Right = XSize;
	windowSize.Top = 0;
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	COORD bufferSize = { XSize + 1, YSize + 100 };
	SetConsoleScreenBufferSize(wHnd, bufferSize);
}

void SetColorBgTex(int Bg, int Tex)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Bg = Bg << 4 | Tex;
	SetConsoleTextAttribute(hConsole, Bg);
}

void cursor_to(SHORT xPos, SHORT yPos)
{
	COORD curPos;
	curPos.X = xPos; curPos.Y = yPos;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), curPos);
}