#pragma once
#include "Define.h"

#include "Point2.h"
#include "Part.h"

struct PartConnector
{
	Part* Main = NULL;
	Part* Connected = NULL;
	Point2 Position = Point2();
};

