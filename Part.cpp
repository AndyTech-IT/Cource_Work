#include "Part.h"

Part* Get_Cocpit()
{
	const Point2 center = Point2(6, 3);
	const Point2 size = Point2(12, 5);
	char** sprite = new char* [5]
	{
		new char[12] {R"(  /|||||\  )"},
		new char[12] {R"( /||/ \||\ )"},
		new char[12] {R"([|°|\ /|°|])"},
		new char[12] {R"(||||<=>||||)"},
		new char[12] {R"([|||<=>|||])"},
	};
	int con_count = 4;
	PartConnector* conectors = new PartConnector[4]
	{
		PartConnector(Point2(0, -2), Point2(0, -1)),
		PartConnector(Point2(5, 1), Point2(1, 0)),
		PartConnector(Point2(0, 2), Point2(0, 1)),
		PartConnector(Point2(-5, 1), Point2(-1, 0)),
	};

	return new Part(Part_Type::Cocpit, center, sprite, size, conectors, con_count);
}

Part* Get_FuelTank()
{
	const Point2 center = Point2(6, 4);
	const Point2 size = Point2(12, 7);
	char** sprite = new char* [7]
	{
		new char[12] {R"([|||||||||])"},
		new char[12] {R"(|||||||||||)"},
		new char[12] {R"(|||||||||||)"},
		new char[12] {R"(|||||||||||)"},
		new char[12] {R"(|||||||||||)"},
		new char[12] {R"(|||||||||||)"},
		new char[12] {R"([|||||||||])"},
	};
	int con_count = 4;
	PartConnector* conectors = new PartConnector[4]
	{
		PartConnector(Point2(0, -3), Point2(0, -1)),
		PartConnector(Point2(5, 0), Point2(1, 0)),
		PartConnector(Point2(0, 3), Point2(0, 1)),
		PartConnector(Point2(-5, 0), Point2(-1, 0)),
	};

	return new Part(Part_Type::FuelTank, center, sprite, size, conectors, con_count);
}

Part* Get_Engine()
{
	const Point2 center = Point2(6, 3);
	const Point2 size = Point2(12, 6);
	char** sprite = new char* [6]
	{
		new char[12] {R"([|||||||||])"},
		new char[12] {R"([|||||||||])"},
		new char[12] {R"(   \||/-\  )"},
		new char[12] {R"(   //|\-/  )"},
		new char[12] {R"(  //|||\\  )"},
		new char[12] {R"( //|||||\\ )"},
	};
	int con_count = 2;
	PartConnector* conectors = new PartConnector[2]
	{
		PartConnector(Point2(0, -2), Point2(0, -1)),
		PartConnector(Point2(0, 3), Point2(0, 1)),
	};

	return new Part(Part_Type::Engine, center, sprite, size, conectors, con_count);
}

Part* Get_Decupler()
{
	const Point2 center = Point2(6, 2);
	const Point2 size = Point2(12, 2);
	char** sprite = new char* [2]
	{
		new char[12] {R"(/<<<<=>>>>\)"},
		new char[12] {R"(\<<<<=>>>>/)"},
	};
	int con_count = 2;
	PartConnector* conectors = new PartConnector[2]
	{
		PartConnector(Point2(0, -1), Point2(0, -1)),
		PartConnector(Point2(0, 0), Point2(0, 1)),
	};

	return new Part(Part_Type::Decupler, center, sprite, size, conectors, con_count);
}

Part* Get_Parashute()
{
	const Point2 center = Point2(3, 2);
	const Point2 size = Point2(6, 2);
	char** sprite = new char* [2]
	{
		new char[6] {R"( ___ )"},
		new char[6] {R"(/>|<\)"},
	};
	int con_count = 1;
	PartConnector* conectors = new PartConnector[1]
	{
		PartConnector(Point2(0, 0), Point2(0, 1)),
	};

	return new Part(Part_Type::Parashute, center, sprite, size, conectors, con_count);
}
Part* Get_Cone_L()
{
	const Point2 center = Point2(3, 2);
	const Point2 size = Point2(6, 2);
	char** sprite = new char* [2]
	{
		new char[6] {R"( /|\ )"},
		new char[6] {R"(/>|<\)"},
	};
	int con_count = 1;
	PartConnector* conectors = new PartConnector[1]
	{
		PartConnector(Point2(0, 0), Point2(0, 1)),
	};

	return new Part(Part_Type::Cone_L, center, sprite, size, conectors, con_count);
}

Part* Get_Cone_M()
{
	const Point2 center = Point2(6, 3);
	const Point2 size = Point2(12, 5);
	char** sprite = new char* [5]
	{
		new char[12] {R"(    /|\    )"},
		new char[12] {R"(   />|<\   )"},
		new char[12] {R"(  />/|\<\  )"},
		new char[12] {R"( />/>|<\<\ )"},
		new char[12] {R"(/>/>/|\<\<\)"},
	};
	int con_count = 1;
	PartConnector* conectors = new PartConnector[1]
	{
		PartConnector(Point2(0, 2), Point2(0, 1)),
	};

	return new Part(Part_Type::Cone_M, center, sprite, size, conectors, con_count);
}

Part* Get_RadialDecupler()
{
	const Point2 center = Point2(2, 2);
	const Point2 size = Point2(4, 3);
	char** sprite = new char* [3]
	{
		new char[4] {R"(\-/)"},
		new char[4] {R"(|-|)"},
		new char[4] {R"(/-\)"},
	};
	int con_count = 2;
	PartConnector* conectors = new PartConnector[2]
	{
		PartConnector(Point2(-1, 0), Point2(-1, 0)),
		PartConnector(Point2(1, 0), Point2(1, 0)),
	};

	return new Part(Part_Type::RadialDecupler, center, sprite, size, conectors, con_count);
}

Part* Get_RadialParashute_R()
{
	const Point2 center = Point2(2, 2);
	const Point2 size = Point2(4, 3);
	char** sprite = new char* [3]
	{
		new char[4] {R"([\ )"},
		new char[4] {R"([<))"},
		new char[4] {R"([/ )"},
	};
	int con_count = 1;
	PartConnector* conectors = new PartConnector[1]
	{
		PartConnector(Point2(-1, 0), Point2(-1, 0)),
	};

	return new Part(Part_Type::RadialParashute_R, center, sprite, size, conectors, con_count);
}

Part* Get_RadialParashute_L()
{
	const Point2 center = Point2(2, 2);
	const Point2 size = Point2(4, 3);
	char** sprite = new char* [3]
	{
		new char[4] {R"( /])"},
		new char[4] {R"((>])"},
		new char[4] {R"( \])"},
	};
	int con_count = 1;
	PartConnector* conectors = new PartConnector[1]
	{
		PartConnector(Point2(1, 0), Point2(1, 0)),
	};

	return new Part(Part_Type::RadialParashute_L, center, sprite, size, conectors, con_count);
}

Part* Get_Part(Part_Type type)
{
	switch (type)
	{
	case Part_Type::Cocpit:
		return Get_Cocpit();
	case Part_Type::FuelTank:
		return Get_FuelTank();
	case Part_Type::Engine:
		return Get_Engine();
	case Part_Type::Cone_L:
		return Get_Cone_L();
	case Part_Type::Cone_M:
		return Get_Cone_M();
	case Part_Type::Parashute:
		return Get_Parashute();
	case Part_Type::Decupler:
		return Get_Decupler();
	case Part_Type::RadialDecupler:
		return Get_RadialDecupler();
	case Part_Type::RadialParashute_R:
		return Get_RadialParashute_R();
	case Part_Type::RadialParashute_L:
		return Get_RadialParashute_L();
	default:
		return NULL;
	}
}

string Get_PartTitle(Part_Type type)
{
	switch (type)
	{
	case Part_Type::Cocpit:
		return "Рубка";
	case Part_Type::FuelTank:
		return "Топливный бак";
	case Part_Type::Engine:
		return "Двигатель";
	case Part_Type::Cone_L:
		return "Обтекатель L";
	case Part_Type::Cone_M:
		return "Обтекатель M";
	case Part_Type::Parashute:
		return "Парашют";
	case Part_Type::Decupler:
		return "Разъединитель";
	case Part_Type::RadialDecupler:
		return "Разъединитель";
	case Part_Type::RadialParashute_R:
		return "Парашют R";
	case Part_Type::RadialParashute_L:
		return "Парашют L";
	default:
		return "<blank>";
	}
}

Part* Get_Parts(int count)
{
	Part* parts = new Part[count];
	for (int i = 0; i < count; i++)
	{
		parts[i] = *Get_Part((Part_Type)(i+1));
	}
	return parts;
}


Part::Part()
{
}

Part::Part(const Part& value)
{
	this->Center = value.Center;
	this->Connectors_Count = value.Connectors_Count;
	Connectors = new PartConnector[Connectors_Count];
	for (int i = 0; i < Connectors_Count; i++)
	{
		Connectors[i] = value.Connectors[i];
		Connectors[i].Main = this;
		Connectors[i].Index = i;
	}
	this->Connectors_Count = value.Connectors_Count;
	this->Type = value.Type;
	this->Position = value.Position;
	this->Size = value.Size;
	this->Sprite = new char* [Size.Y];
	for (int y = 0; y < Size.Y; y++)
	{
		Sprite[y] = new char[Size.X];
		for (int x = 0; x < Size.X; x++)
			Sprite[y][x] = value.Sprite[y][x];
	}
	this->Index = value.Index;
}

Part::Part(const Part* value)
{
	this->Center = value->Center;
	this->Connectors_Count = value->Connectors_Count;
	Connectors = new PartConnector[Connectors_Count];
	for (int i = 0; i < Connectors_Count; i++)
	{
		Connectors[i] = value->Connectors[i];
		Connectors[i].Main = this;
		Connectors[i].Index = i;
	}
	this->Position = value->Position;
	this->Size = value->Size;
	this->Sprite = new char* [Size.Y];
	for (int y = 0; y < Size.Y; y++)
	{
		Sprite[y] = new char[Size.X];
		for (int x = 0; x < Size.X; x++)
			Sprite[y][x] = value->Sprite[y][x];
	}
	this->Type = value->Type;
	this->Index = value->Index;
}

Part::Part(Part_Type type, Point2 center, char** sprite, Point2 size, PartConnector* connectors, int connectors_count)
{
	Type = type;
	Size = size;
	this->Sprite = new char* [Size.Y];
	for (int y = 0; y < Size.Y; y++)
	{
		Sprite[y] = new char[Size.X];
		for (int x = 0; x < Size.X; x++)
			Sprite[y][x] = sprite[y][x];
	}
	Center = center;
	Connectors = new PartConnector[connectors_count];
	for (int i = 0; i < connectors_count; i++)
	{
		Connectors[i] = connectors[i];
		Connectors[i].Main = this;
		Connectors[i].Index = i;
	}
	Connectors_Count = connectors_count;
}

bool Part::Connectable(PartConnector my_connector, PartConnector other_connector)
{
	return my_connector.Connected_Position == -other_connector.Connected_Position;
}



Part::~Part()
{
	for (int i = 0; i < Size.Y; i++)
	{
		delete[] Sprite[i];
	}
	delete[] Sprite;

	delete[] Connectors;
}
