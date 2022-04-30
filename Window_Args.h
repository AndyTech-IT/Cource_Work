#pragma once
#include "Define.h"
#include "Point2.h"
#include "Part.h"


struct Window_Args
{
	struct Window_Parts_Panel_Args
	{
		Window_Args* args = NULL;
		int parts_count = 10;
		int parts_padding = 1;
		Point2 part_window_size = Point2(21+2, 45);
		int parts_on_page = 3;
		int pages_count = parts_count / parts_on_page + (parts_count % parts_on_page != 0 ? 1 : 0);
		int page = 0;
		int selected_index = 0; 
		Point2 part_icon_size = Point2(19 + 2, 10);
		Part* Parts = Get_Parts(10);

		Part* Collide_With(Part target)
		{
			for (Part* p = &args->parts[0]; p < &args->parts[args->parts_count]; p++)
			{
				Point2 d_pos = target.Position - p->Position;
				for (int y = 0; y < p->Size.Y; y++)
				{
					int y1 = d_pos.Y >= 0 ? -p->Size.Y + y : target.Size.Y + y ;
					if (y1 >= 0 && y1 < target.Size.Y)
						for (int x = 0; x < p->Size.X - 1; x++)
						{
							int x1 = d_pos.X >= 0 ? -p->Size.X + x : target.Size.X + x;
							if (x1 >= 0 && x1 < target.Size.X)
							{
								if (p->Sprite[y][x] != ' ' && target.Sprite[y1][x1] != ' ')
									return p;
							}
						}
				}
			}

			return NULL;
		}
		void On_Key_UP()
		{
			if (selected_index > 0)
			{
				selected_index--;
				page = selected_index / parts_on_page;
			}
		}
		void On_Key_Left()
		{
			if (page > 0)
			{
				page--;
				selected_index = page * parts_on_page;
			}
		}
		void On_Key_Down()
		{
			if (selected_index < parts_count - 1)
			{
				selected_index++;
				page = selected_index / parts_on_page;
			}
		}
		void On_Key_Right()
		{
			if (page < pages_count - 1)
			{
				page++;
				selected_index = page * parts_on_page;
			}
		}
		void On_Key_Accept()
		{
			if (args->parts_count == 0)
			{
				// Add main part in arr
				args->parts = new Part[1]{ Get_Part((Part_Type)(selected_index + 1)) };
				args->parts_count = 1;

				// Add main part
				
				args->parts[0].Position = Point2(args->Size.X / 2-1, args->Size.Y / 2-1 + args->Scroll);
				args->selected_part = &args->parts[0];
				args->selected_con_index = 0;
				args->selected_connector = &args->selected_part->Connectors[args->selected_con_index];
				args->cursor_pos = new Point2(args->selected_part->Position + args->selected_connector->Position);

			}
			else
			{
				// Create new part
				Part* adding = new Part(Parts[selected_index]);
				PartConnector* con = NULL;

				// Finding of connection to new part
				for (int i = 0; i < adding->Connectors_Count; i++)
				{
					PartConnector* temp = &adding->Connectors[i];
					if (args->selected_part->Connectable(*args->selected_connector, *temp))
					{
						con = temp;
						break;
					}
				}
				if (con != NULL)
				{
					adding->Position = *args->cursor_pos + args->selected_connector->Connected_Position - con->Position;
					Part* collide = Collide_With(adding);
					if (collide == NULL)
					{
						// Connect new part to exist
						con->Connected = args->selected_connector;
						args->selected_connector->Connected = con;

						// add new part to arr
						Part* parts = new Part[args->parts_count+1];
						for (int i = 0; i < args->parts_count; i++)
						{
							parts[i] = args->parts[i];
							parts[i].Index = i;
						}
						adding->Index = args->parts_count;
						parts[args->parts_count++] = *adding;
						args->parts = parts;
					}
					else
					{
						// Finding connection to exist part
						for (int i = 0; i < collide->Connectors_Count; i++)
						{
							PartConnector* temp = &collide->Connectors[i];
							if (args->selected_part->Connectable(*args->selected_connector, *temp))
							{
								con = temp;
								break;
							}
						}
						if (con != NULL)
						{
							// Connect exist part to enother exist part
							con->Connected = args->selected_connector;
							args->selected_connector->Connected = con;
						}
					}
				}
			}
			page = 0;
			selected_index = 0;
		}
	} Parts_Panel_Args{this};
	int Scroll = 0;
	int Scroll_Speed = 3;
	Point2 Size = Point2(100, 50);
	bool is_selection_color = false;
	bool part_selecting = true;
	bool connector_selecting = false;
	bool update = true;

	Part* parts = NULL;
	int parts_count = 0;

	Part* selected_part = NULL;
	int selected_con_index = 0;
	PartConnector* selected_connector = NULL;
	Point2* cursor_pos = new Point2();

	void Reset()
	{
		if (parts_count != 0)
		{
			selected_part = &parts[0];
			selected_con_index = 0;
			selected_connector = &selected_part->Connectors[0];
			cursor_pos = new Point2(selected_part->Position + selected_connector->Position);
		}
	}
	void On_Key_Cancel()
	{
		if (part_selecting && parts_count != 0)
		{
			connector_selecting = true;
			part_selecting = false;
			return;
		}
		if (connector_selecting)
		{
			Reset();
		}
	}
	void On_Key_Delete()
	{
		if (connector_selecting)
		{
			Part* deleting = selected_connector->Connected->Main;
			for (int i = 0; i < deleting->Connectors_Count; i++)
			{
				// Mast be only one connection with curent
				if (deleting->Connectors[i].Connected != NULL && deleting->Connectors[i].Connected != selected_connector)
					return;
			}
			bool founded = false; 
			--parts_count;
			for (int i = 0; i < parts_count; i++)
			{
				if (parts[i] == deleting)
					founded = true;
				if (founded)
				{
					parts[i] = parts[i + 1];
					parts[i].Index = i;
				}
			}
		}
	}
	void On_Key_UP()
	{
		if (part_selecting)
		{
			Parts_Panel_Args.On_Key_UP();
			update = true;
			return;
		}
		else
		{
			Scroll += Scroll_Speed;
			return;
		}
		update = false;
	}
	void On_Key_Down()
	{
		if (part_selecting)
		{
			Parts_Panel_Args.On_Key_Down(); 
			update = true;
			return;
		}
		else
		{
			Scroll -= Scroll_Speed;
			return;
		}
		update = false;
	}
	void On_Key_Left()
	{
		if (part_selecting)
		{
			Parts_Panel_Args.On_Key_Left();
			update = true;
			return;
		}
		if (connector_selecting)
		{
			selected_con_index = selected_con_index > 0 ? selected_con_index - 1 : selected_part->Connectors_Count - 1;
			selected_connector = &selected_part->Connectors[selected_con_index];
			cursor_pos = new Point2(selected_part->Position + selected_connector->Position);
			update = true;
			return;
		}
		update = false;
	}
	void On_Key_Right()
	{
		if (part_selecting)
		{
			Parts_Panel_Args.On_Key_Right();
			update = true;
			return;
		}
		if (connector_selecting)
		{
			selected_con_index = selected_con_index < selected_part->Connectors_Count - 1 ? selected_con_index + 1 : 0;
			selected_connector = &selected_part->Connectors[selected_con_index];
			cursor_pos = new Point2(selected_part->Position + selected_connector->Position);
			update = true;
			return;
		}
		update = false;
	}
	void On_Key_Accept()
	{
		if (part_selecting)
		{
			part_selecting = false;
			Parts_Panel_Args.On_Key_Accept();

			connector_selecting = true;
			update = true;
			return;
		}
		if (connector_selecting)
		{
			if (selected_connector->Connected)
			{
				selected_part = selected_connector->Connected->Main;
				selected_connector = &selected_part->Connectors[0];
				selected_con_index = 0;
				cursor_pos = new Point2(selected_part->Position + selected_connector->Position);
				return;
			}
			connector_selecting = false;
			part_selecting = true;
			update = true;
			return;
		}
		update = false;
	}
};