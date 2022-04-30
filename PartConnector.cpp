#include "PartConnector.h"

PartConnector::PartConnector()
{
}

PartConnector::PartConnector(const PartConnector& value)
{
	this->Connected = value.Connected;
	this->Connected_Position = value.Connected_Position;
	this->Main = value.Main;
	this->Position = value.Position;
	this->Index = value.Index;
}

PartConnector::PartConnector(const PartConnector* value)
{
	this->Connected = value->Connected;
	this->Connected_Position = value->Connected_Position;
	this->Main = value->Main;
	this->Position = value->Position;
	this->Index = value->Index;
}

PartConnector::PartConnector(Point2 position, Point2 con_position)
{
	Position = position;
	Connected_Position = con_position;
}

PartConnector::~PartConnector()
{
	if (Connected)
	{
		Connected->Connected = NULL;
	}
}
