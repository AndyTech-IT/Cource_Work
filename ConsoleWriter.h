#pragma once
#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include "Point2.h"
#include "Color.h"
#include "Sprite.h"
using namespace std;

class ConsoleWriter
{
private:
	static HANDLE hConsole;
public:

	static void Chainge_ConsolePixel(SHORT line, SHORT num, char ch, Color c = Color::White)
	{
		SetConsoleTextAttribute(hConsole, (WORD)c);

		if (hConsole != INVALID_HANDLE_VALUE)
		{
			CONSOLE_SCREEN_BUFFER_INFO old;
			GetConsoleScreenBufferInfo(hConsole, &old);
			SetConsoleCursorPosition(hConsole, { num, line });
			cout << ch;
			SetConsoleCursorPosition(hConsole, old.dwCursorPosition);
		}
	}
	static void Draw_Part(Sprite part, Point2 top_left_point, Point2 editor_size, bool is_selected = false)
	{
		for (int y = 0; y < part.Size.Y; y++)
		{
			if ((y == 0 || y == part.Size.Y - 1) && is_selected)
			{
				int screen_y = top_left_point.Y + y;
				for (int x = part.Size.X + top_left_point.X + 5; x < editor_size.X - 1; x++)
				{
					Chainge_ConsolePixel(screen_y, x, '-');
					Chainge_ConsolePixel(screen_y, editor_size.X - x, '-');
				}
			}

			for (int x = 0; x < part.Size.X; x++)
			{
				char ch = part.Characters[y][x];
				int screen_x = top_left_point.X + x;
				int screen_y = top_left_point.Y + y;
				bool is_h_edge = screen_x < 0 || screen_x >= editor_size.X;
				bool is_v_edge = screen_y < 0 || screen_y >= editor_size.Y;
				if (ch == ' ' || is_h_edge || is_v_edge)
					continue;
				Chainge_ConsolePixel(screen_y, screen_x, ch);
			}
		}
	}
};

