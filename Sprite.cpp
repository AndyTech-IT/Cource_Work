#include "Sprite.h"

template <typename T>
T** CopyArr2(const T** copy, const Point2 size)
{
	if (copy == NULL)
		return NULL;

	T** result = new T*[size.X];
	for (int i = 0; i < size.X; i++)
	{
		result[i] = new T[size.Y];
		for (int j = 0; j < size.Y; j++)
		{
			result[i][j] = copy[i][j];
		}
	}
	return result;
}
void Sprite::Delete_Data()
{
	if (Characters)
	{
		for (int i = 0; i < Size.Y; i++)
			delete[] Characters[i];
		delete[] Characters;
		Characters = NULL;
	}
	if (Colors)
	{
		for (int i = 0; i < Size.Y; i++)
			delete[] Colors[i];
		delete[] Colors;
		Colors = NULL;
	}
}
Sprite::Sprite(Point2 pos = {}, Point2 size = {}, const char** chars, const Color** colors)
{
	Position = pos;
	Size = size;
	Characters = CopyArr2(chars, size);
	Colors = CopyArr2(colors, size);
}

Sprite::Sprite(const Sprite& copy)
{
	Delete_Data();
	Position = copy.Position;
	Size = copy.Size;
	const char** chars = copy.Characters;
	Characters = CopyArr2(chars, copy.Size);
	const Color** colors = copy.Colors;
	Colors = CopyArr2(colors, copy.Size);
}

Sprite::Sprite(const Sprite* copy)
{
	Delete_Data();
	Position = copy->Position;
	Size = copy->Size;
	const char** chars = copy->Characters;
	Characters = CopyArr2(chars, copy->Size);
	const Color** colors = copy->Colors;
	Colors = CopyArr2(colors, copy->Size);
}



Sprite::~Sprite()
{
	Delete_Data();
}

Sprite Sprite::Get_Sprite()
{
	return Sprite();
}
