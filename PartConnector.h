#pragma once
#include "Define.h"

#include "Point2.h"
#include "Part.h"

struct PartConnector
{
	Part* Main = NULL;
	bool Visited = false;
	PartConnector* Connected = NULL;
	Point2 Position = Point2();
	Point2 Connected_Position = Point2();
	int Index = 0;

	PartConnector();
	PartConnector(const PartConnector& value);
	PartConnector(const PartConnector* value);
	PartConnector(Point2 position, Point2 con_position);
	~PartConnector();
};

