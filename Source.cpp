#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <chrono>
#include <thread>
#include <stdlib.h>
using namespace std;


void Chainge_ConsolePixel(SHORT line, SHORT num, char ch)
{
	HANDLE cons = GetStdHandle(STD_OUTPUT_HANDLE);
	if (cons != INVALID_HANDLE_VALUE)
	{
		CONSOLE_SCREEN_BUFFER_INFO old;
		GetConsoleScreenBufferInfo(cons, &old);
		SetConsoleCursorPosition(cons, { num, line });
		cout << ch;
		SetConsoleCursorPosition(cons, old.dwCursorPosition);
	}
}

class Console_SpaceShip_Editor
{
	struct Point2
	{
		int x;
		int y;
	};

	enum class EditorCommand
	{
		Exit,
		AddStageInTop,
		AddStageInBottom,
		DeleteStage,
		NextStage,
		PreviousStage,
		ChaingeStage_MainPart,
		ChaingeStage_RadialPart,
		ChaingeStage_ContainerPart
	};

	static class RocketParts
	{
	public:
		enum class Stage_Type
		{
			NoseCone,
			Parachute,
			Cockpit,
			FuelTank,
			Engine,
			Decupler
		};

		enum class RadialParts_Type
		{
			Parachute,
			Truster,
		};

		enum class Container_Type
		{
			ConeContainer,
			Flat_Container,
		};

	public:
		struct RocketPart_Sprite
		{
			Point2 Size;
			int TypeEnum;
			char** Sprite = NULL;
		};

	public:
		static RocketPart_Sprite* Get_Container_Sprite(Container_Type type, Point2 contained_size)
		{
			Point2 size;
			RocketPart_Sprite* sprite;
			int height = contained_size.y;
			int half_width;
			switch (type)
			{
			case Console_SpaceShip_Editor::RocketParts::Container_Type::ConeContainer:
				size = { contained_size.x + 2, height + contained_size.x / 2 };
				half_width = size.x / 2;
				sprite = new RocketPart_Sprite{ size, (int)type,
					new char* [size.y]
				};
				for (int i = 0; i < size.y; i++)
				{
					sprite->Sprite[i] = new char[size.x + 1];
					for (int x = 0; x < size.x; x++)
					{
						sprite->Sprite[i][x] = ' ';
					}
					sprite->Sprite[i][size.x] = '\0';
				}
				for (int y = 0; y <= size.x / 2; y++)
				{
					int x1 = half_width - y - 1;
					int x2 = half_width + y;
					sprite->Sprite[y][x1] = '/';
					sprite->Sprite[y][x2] = '\\';
				}
				for (int i = size.x / 2; i < size.y - 1; i++)
				{
					sprite->Sprite[i][0] = '|';
					sprite->Sprite[i][size.x - 1] = '|';
				}
				sprite->Sprite[size.y - 1][0] = '\\';
				sprite->Sprite[size.y - 1][size.x - 1] = '/';
				break;

			case Container_Type::Flat_Container:
				size = { contained_size.x + 2, height };
				sprite = new RocketPart_Sprite{ size, (int)type,
					new char* [size.y]
				};

				for (int i = 0; i < size.y; i++)
				{
					sprite->Sprite[i] = new char[size.x + 1];
					for (int x = 0; x < size.x; x++)
					{
						sprite->Sprite[i][x] = ' ';
					}
					sprite->Sprite[i][size.x] = '\0';
				}

				for (int i = 0; i < size.y; i++)
				{
					sprite->Sprite[i][0] = '|';
					sprite->Sprite[i][size.x - 1] = '|';
				}
				break;

			default:

				return NULL;
			}
			return sprite;
		}
		static RocketPart_Sprite* Get_RadialPart_Sprite(RadialParts_Type type)
		{
			Point2 size;
			RocketPart_Sprite* sprite;
			switch (type)
			{
			case RadialParts_Type::Parachute:
				size = { 12, 3 };
				sprite = new RocketPart_Sprite{ size, (int)type,
					new char* [size.y]{
						new char[] {"/|        |\\"},
						new char[] {"||        ||"},
						new char[] {"\\|        |/"},
					}
				};
				break;

			case RadialParts_Type::Truster:
				size = { 14, 3 };
				sprite = new RocketPart_Sprite{ size,(int)type,
					new char* [size.y]{
						new char[] {"/|          |\\"},
						new char[] {"||#        #||"},
						new char[] {"^^          ^^"},
					}
				};
				break;

			default:
				return NULL;
			}

			return sprite;
		}
		static RocketPart_Sprite* Get_Stage_Sprite(Stage_Type type)
		{
			Point2 size{ 0, 0 };
			RocketPart_Sprite* sprite;
			switch (type)
			{
			case Stage_Type::NoseCone:
				size = { 4, 2 };
				sprite = new RocketPart_Sprite{ size,(int)type,
					new char* [size.y]{
						new char[] {" /\\ "},
						new char[] {"//\\\\"}
					}
				};
				break;

			case Stage_Type::Parachute:
				size = { 4, 2 };
				sprite = new RocketPart_Sprite{ size,(int)type,
					new char* [2]{
						new char[] {" __ "},
						new char[] {"/||\\"},
					}
				};
				break;

			case Stage_Type::Cockpit:
				size = { 8, 3 };
				sprite = new RocketPart_Sprite{ size,(int)type,
					new char* [size.y]{
						new char[] {" /####\\ "},
						new char[] {"/|(__)|\\"},
						new char[] {"[||||||]"},
					}
				};
				break;

			case Stage_Type::FuelTank:
				size = { 8, 3 };
				sprite = new RocketPart_Sprite{ size,(int)type,
					new char* [size.y]{
						new char[] {"[||||||]"},
						new char[] {"||[--]||"},
						new char[] {"[||||||]"},
					}
				};
				break;

			case Stage_Type::Engine:
				size = { 6, 3 };
				sprite = new RocketPart_Sprite{ size,(int)type,
					new char* [size.y]{
						new char[] {"\\||||/"},
						new char[] {" //\\\\ "},
						new char[] {"//||\\\\"},
					}
				};
				break;
			case Stage_Type::Decupler:
				size = { 8, 1 };
				sprite = new RocketPart_Sprite{ size,(int)type,
					new char* [size.y]{
						new char[] {"[======]"}
					}
				};
				break;

			default:
				return NULL;
			}
			return sprite;
		}
		static void Draw_Part(RocketPart_Sprite part, Point2 top_left_point, Point2 editor_size, bool is_selected = false)
		{
			for (int y = 0; y < part.Size.y; y++)
			{
				if ((y == 0 || y == part.Size.y - 1) && is_selected)
				{
					int screen_y = top_left_point.y + y;
					for (int x = part.Size.x + top_left_point.x + 5; x < editor_size.x - 1; x++)
					{
						Chainge_ConsolePixel(screen_y, x, '-');
						Chainge_ConsolePixel(screen_y, editor_size.x - x, '-');
					}
				}

				for (int x = 0; x < part.Size.x; x++)
				{
					char ch = part.Sprite[y][x];
					int screen_x = top_left_point.x + x;
					int screen_y = top_left_point.y + y;
					bool is_h_edge = screen_x < 0 || screen_x >= editor_size.x;
					bool is_v_edge = screen_y < 0 || screen_y >= editor_size.y;
					if (ch == ' ' || is_h_edge || is_v_edge)
						continue;
					Chainge_ConsolePixel(screen_y, screen_x, ch);
				}
			}
		}
	};

	struct Part_ListItem
	{
		RocketParts::RocketPart_Sprite* Main_Part = NULL;
		RocketParts::RocketPart_Sprite* Radial_Part = NULL;
		RocketParts::RocketPart_Sprite* Container = NULL;
		Part_ListItem* Next_Part = NULL;
		Part_ListItem* Prev_Part = NULL;
		~Part_ListItem()
		{
			if (Main_Part)
				delete Main_Part;
			if (Radial_Part)
				delete Radial_Part;
			if (Container)
				delete Container;
		}
	};

	class Parts_List
	{
	private:
		Part_ListItem* _first = NULL;
		Part_ListItem* _last = NULL;
		int _count = 0;

	public:
		Parts_List() {};
		~Parts_List()
		{
			if (_first)
			{
				delete _first->Next_Part;
				delete _first;
			}
		}

	private:
		bool Index_IsOutOfRange(int index)
		{
			return index > _count + 1 || index < 0;
		}

	public:
		int Get_Count()
		{
			return _count;
		}
		void AddInTail(Part_ListItem* item)
		{
			if (_last)
			{
				_last->Next_Part = item;
				item->Prev_Part = _last;
			}
			else
				_first = item;

			_last = item;
			_count++;
		}

		void AddInHead(Part_ListItem* item)
		{
			if (_first)
			{
				_first->Prev_Part = item;
				item->Next_Part = _last;
			}
			else
				_last = item;

			_first = item;
			_count++;
		}

		Part_ListItem* operator [](int index)
		{
			if (Index_IsOutOfRange(index))
				throw "Index out of range!";

			Part_ListItem* item = _first;
			for (int i = 0; i < index; i++)
			{
				item = item->Next_Part;
			}
			return item;
		}

		void Remove(int index)
		{
			if (Index_IsOutOfRange(index))
				return;

			if (index == 0)
			{
				if (_count == 1)
				{
					delete _first, _last;
					_first = _last = NULL;
				}
				else
				{
					Part_ListItem* next = _first->Next_Part;
					delete _first;
					_first = next;
				}
			}
			else
			{
				Part_ListItem* previous = this->operator[](index - 1);

				if (index == _count - 1)
				{
					delete _last;
					_last = previous;
					_count--;
					return;
				}
				else
				{
					Part_ListItem* next = this->operator[](index + 1);

					delete previous->Next_Part;
					previous->Next_Part = next;
					next->Prev_Part = previous;
				}
			}
			_count--;
		}
	};

private:
	const Point2 Editor_Size{ 50, 50 };
	const Point2 Border_Size{ 1, 1 };
	const char Border_H = '|';
	const char Border_V = '-';
	const char Border_C = '#';
private:
	Parts_List _parts;
private:

	void Update_Editor(int curent_index)
	{
		system("cls");
		for (int y = -Border_Size.y; y < Editor_Size.y + Border_Size.y; y++)
		{
			for (int x = -Border_Size.x; x < Editor_Size.x + Border_Size.x; x++)
			{
				bool is_h_edge = x < 0 || x >= Editor_Size.x;
				bool is_v_edge = y < 0 || y >= Editor_Size.y;
				if (is_h_edge)
					if (is_v_edge)
						cout << Border_C;
					else
						cout << Border_H;
				else if (is_v_edge)
					cout << Border_V;
				else
					cout << ' ';
			}
			cout << endl;
		}
		Build_Ship(curent_index);
	}

	void Build_Ship(int curent_index)
	{
		int curent_y = Editor_Size.y + Border_Size.y - 1;
		int center_x = (Editor_Size.x + Border_Size.x) / 2;
		for (int i = 0; i < _parts.Get_Count(); i++)
		{
			bool is_selected = i == curent_index;
			Part_ListItem* part = _parts[i];
			if (part->Container)
			{
				RocketParts::Draw_Part(*part->Container, Point2{ center_x - part->Container->Size.x / 2, curent_y - part->Container->Size.y }, Editor_Size);
			}

			if (part->Main_Part)
			{
				RocketParts::Draw_Part(*part->Main_Part, Point2{ center_x - part->Main_Part->Size.x / 2, curent_y - part->Main_Part->Size.y }, Editor_Size, is_selected);

				if (part->Radial_Part)
				{
					RocketParts::Draw_Part(*part->Radial_Part, Point2{ center_x - part->Radial_Part->Size.x / 2, curent_y - part->Radial_Part->Size.y }, Editor_Size);
				}
				curent_y -= part->Main_Part->Size.y;
			}
		}
	}

	RocketParts::Stage_Type SelectStage(Part_ListItem*& part)
	{
		if (part->Main_Part)
		{
			delete part->Main_Part;
			part->Main_Part = NULL;
		}

		cout << "1) NoseCone" << endl;
		cout << "2) Parachute" << endl;
		cout << "3) Cockpit" << endl;
		cout << "4) FuelTank" << endl;
		cout << "5) Engine" << endl;
		cout << "6) Decupler" << endl;
		int t;
		cout << "Select Type: ";
		cin >> t;
		t--;
		part->Main_Part = RocketParts::Get_Stage_Sprite((RocketParts::Stage_Type)t);
		return (RocketParts::Stage_Type)t;
	}

	void SelectRadial(Part_ListItem*& part, string& message)
	{
		if (part->Main_Part == NULL)
		{
			message = "MainPart is not exist!";
			return;
		}

		if (part->Radial_Part)
		{
			delete part->Radial_Part;
			part->Radial_Part = NULL;
		}

		cout << "0) Empty" << endl;
		cout << "1) Parachute" << endl;
		cout << "2) Truster" << endl;
		int t;
		cout << "Select Type: ";
		cin >> t;
		if (t == 0)
			return;
		t--;
		part->Radial_Part = RocketParts::Get_RadialPart_Sprite((RocketParts::RadialParts_Type)t);
	}

	void SelectContainer(Part_ListItem*& part, string& message)
	{
		if (part->Main_Part == NULL)
		{
			message = "MainPart is not exist!";
			return;
		}

		if (part->Container)
		{
			delete part->Container;
			part->Container = NULL;
		}

		cout << "0) Empty" << endl;
		cout << "1) ConeContainer" << endl;
		cout << "2) Flat_Container" << endl;
		int t;
		cout << "Select Type: ";
		cin >> t;
		if (t == 0)
			return;
		t--;

		Point2 size = part->Main_Part->Size;

		part->Container = RocketParts::Get_Container_Sprite((RocketParts::Container_Type)t, size);
	}

	void NextStage(int& curent_index, string& message)
	{
		if (_parts.Get_Count() - 1 > curent_index)
			curent_index++;
		else
			message = "Edge is researched!";
	}
	void PrevStage(int& curent_index, string& message)
	{
		if (0 < curent_index)
			curent_index--;
		else
			message = "Edge is researched!";
	}

public:
	void Start()
	{
		_parts = Parts_List();
		int command = -1;
		int curent_stage_index = -1;
		Part_ListItem* part;
		string message;

		while (true)
		{
			system("cls");
			Update_Editor(curent_stage_index);
			cout << message << endl;
			message = "";

			cout << "0) Exit" << endl;
			cout << "1) AddStage on Top" << endl;
			cout << "2) AddStage on Bottom" << endl;
			cout << "3) DeleteStage" << endl;
			cout << "4) NextStage" << endl;
			cout << "5) PreviousStage" << endl;
			cout << "6) ChaingeStage_MainPart" << endl;
			cout << "7) ChaingeStage_RadialPart" << endl;
			cout << "8) ChaingeStage_ContainerPart" << endl;
			cout << "Enter command: ";
			cin >> command;
			if (curent_stage_index != -1)
				part = _parts[curent_stage_index];
			else
				part = NULL;

			switch ((EditorCommand)command)
			{
			case EditorCommand::AddStageInTop:
			{
				part = new Part_ListItem;
				RocketParts::Stage_Type t = SelectStage(part);
				if (t == RocketParts::Stage_Type::FuelTank)
					SelectRadial(part, message);
				if (t == RocketParts::Stage_Type::Decupler || t == RocketParts::Stage_Type::Engine)
					SelectContainer(part, message);

				_parts.AddInTail(part);
				if (curent_stage_index == -1)
					curent_stage_index = 0;
				break;
			}
			case EditorCommand::AddStageInBottom:
			{
				part = new Part_ListItem;
				RocketParts::Stage_Type t = SelectStage(part);
				if (t == RocketParts::Stage_Type::FuelTank)
					SelectRadial(part, message);
				if (t == RocketParts::Stage_Type::Decupler || t == RocketParts::Stage_Type::Engine)
					SelectContainer(part, message);

				_parts.AddInHead(part);
				if (curent_stage_index == -1)
					curent_stage_index = 0;
				break;
			}
			case EditorCommand::DeleteStage:
				if (curent_stage_index != -1)
				{
					_parts.Remove(curent_stage_index);
					if (curent_stage_index == _parts.Get_Count())
						curent_stage_index--;
				}
				break;
			case EditorCommand::NextStage:
				NextStage(curent_stage_index, message);
				break;
			case EditorCommand::PreviousStage:
				PrevStage(curent_stage_index, message);
				break;
			case EditorCommand::ChaingeStage_MainPart:
				if (part)
					SelectStage(part);
				else
					message = "Stage not exist!";
				break;
			case EditorCommand::ChaingeStage_RadialPart:
				if (part)
					if (part->Main_Part->TypeEnum == (int)RocketParts::Stage_Type::FuelTank)
						SelectRadial(part, message);
					else
						message = "Incorect Part!";
				else
					message = "Stage not exist!";
				break;
			case EditorCommand::ChaingeStage_ContainerPart:
				if (part)
					if (part->Main_Part->TypeEnum == (int)RocketParts::Stage_Type::Decupler ||
						part->Main_Part->TypeEnum == (int)RocketParts::Stage_Type::Engine)
						SelectContainer(part, message);
					else
						message = "Incorrect Part!";
				else
					message = "Stage not exist!";
				break;
			case EditorCommand::Exit:
				return;
			default:
				message = "Wrong command!";
				break;
			}
		}
	}
};

//int main()
//{
//	system("mode 650");
//	setlocale(LC_ALL, "rus");
//	Console_SpaceShip_Editor editor;
//	editor.Start();
//	system("pause");
//	return 0;
//}