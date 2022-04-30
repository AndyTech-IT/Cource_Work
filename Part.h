#pragma once
#include "Define.h"

#include "Point2.h"
#include "PartConnector.h"

enum class Part_Type
{
	None,
	Cocpit,
	FuelTank,
	Engine,
	Cone_L,
	Cone_M,
	Parashute,
	Decupler,
	RadialDecupler,
	RadialParashute_R,
	RadialParashute_L
};
struct Part
{
	Part_Type Type = Part_Type::None;
	Point2 Position = Point2();
	Point2 Size = Point2();
	Point2 Center = Point2();
	int Index = 0;

	PartConnector* Connectors = NULL;
	int Connectors_Count = 0;

	char** Sprite = NULL;

	Part();
	Part(const Part& value);
	Part(const Part* value);
	Part(Part_Type type, Point2 center, char** sprite, Point2 size, PartConnector* connectors = NULL, int connectors_count = 0);
	bool Connectable(PartConnector my_connector, PartConnector other_connector);
	bool operator ==(Part value)
	{
		return value.Position == this->Position && value.Size == this->Size;
	}
	bool operator !=(Part value)
	{
		return (*this == value) == false;
	}
	~Part();
};


Part* Get_Cocpit();
Part* Get_FuelTank();
Part* Get_Engine();
Part* Get_Cone_L();
Part* Get_Cone_M();
Part* Get_Parashute();
Part* Get_Decupler();
Part* Get_RadialDecupler();
Part* Get_RadialParashute_R();
Part* Get_RadialParashute_L();

Part* Get_Part(Part_Type type);
Part* Get_Parts(int count);
string Get_PartTitle(Part_Type type);


