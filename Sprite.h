#pragma once
#include "Point2.h"
#include "Color.h"

class Sprite
{
protected:
	Point2 Position;
	Point2 Size;
	char** Characters;
	Color** Colors;
	//friend void ConsoleWriter::Chainge_ConsolePixel(SHORT line, SHORT num, char ch, Color c);
private:
	void Delete_Data();
public:
	Sprite(Point2 pos = {}, Point2 size = {}, const char** chars = NULL, const Color** colors = NULL);
	Sprite(const Sprite& copy);
	Sprite(const Sprite* copy);
	~Sprite();
	static Sprite Get_Sprite();
};

