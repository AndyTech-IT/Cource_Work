#include "Define.h"

#include "Point2.h"

HANDLE cons = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO buf_info;

#define Is_UpKey(key_code) key_code == 72 || key_code == 119 || key_code == 56
#define Is_LeftKey(key_code) key_code == 75 || key_code == 97 || key_code == 52
#define Is_DownKey(key_code) key_code == 80 || key_code == 115 || key_code == 50
#define Is_RightKey(key_code) key_code == 77 || key_code == 100 || key_code == 54
#define Is_AcceptKey(key_code) key_code == 13 || key_code == 32

int main()
{
	GetConsoleScreenBufferInfo(cons, &buf_info);
	const int count = 10;
	Point2* points = new Point2[count];
	for (int i = 0; i < count; i++)
		points[i] = Point2(i, i);
	int index = 0;

	SetConsoleCursorPosition(cons, points[index]);
	while (true)
	{
		char c = _getch();
		if (Is_UpKey(c))
		{

		}
		else if (Is_LeftKey(c))
		{
			index = index > 0 ? index - 1 : count - 1;
		}
		else if (Is_DownKey(c))
		{

		}
		else if (Is_RightKey(c))
		{
			index = index < count-1 ? index + 1 : 0;
		}
		else if (Is_AcceptKey(c))
		{
			index = 0;
		}
		SetConsoleCursorPosition(cons, buf_info.dwCursorPosition);
		cout << (int)c << ' ' << c << endl;
		SetConsoleCursorPosition(cons, points[index]);
		switch (c)
		{
		default:
			break;
		}
	}
	return 0;
}