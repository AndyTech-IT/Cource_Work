#pragma once
#include "Define.h"

#include "Point2.h"
#include "PartConnector.h"

struct Part
{
	char** Sprite = NULL;
	Point2 Position = Point2();
	Point2 Size = Point2();
	PartConnector* Top_Connectors = NULL;
	PartConnector* Bottom_Connectors = NULL;
	PartConnector* Radial_Connectors = NULL;
};

