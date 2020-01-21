#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

struct map;
typedef struct map* Pos;
typedef struct map
{
	char planet_name[3];
	int orbit_level;
	Pos next_Neighbour;
	Pos next_Satelite;
};

struct path;
typedef struct path* Path;
typedef struct path
{
	Pos planet;
	Path next;
};

Pos create_Planet();
Path create_Path_Node();
void push_Front(Pos, Pos);
void push_To_Map(Pos, Pos, Pos);
int calculate_Number_Of_Orbits(Pos);
Pos find_planet(Pos, Pos);
Pos find_prev(Pos, Pos);
void recorect_orbit_levels(Pos );
int calculate_Number_Of_Orbits_To_Santa(Pos );
void find_path_from_root(Pos , Pos , Path);
void remove_same_orbits(Path );


int main()
{
	FILE* fp = fopen("Puzzle_12.txt", "r+");
	int i = 0;
	char buffer = '\0';
	char planet_Name[3] = { '\0' };
	Pos map = create_Planet();
	Pos planet = NULL;
	Pos satelite = NULL;
	int number_Of_Orbits_To_Santa = 0;
	int k = 0;
	while (i < 1285)//to get past the text of the 
	{
		fscanf(fp, "%c", &buffer);
		//printf("%c", buffer);
		i++;
	}

	while (!feof(fp))
	{
		fscanf(fp, "%c%c%c", &planet_Name[0], &planet_Name[1], &planet_Name[2]);			//
		planet = create_Planet();															//
		planet->planet_name[0] = planet_Name[0];											//				THE FIRST PLANET LOADED
		planet->planet_name[1] = planet_Name[1];											//
		planet->planet_name[2] = planet_Name[2];											//

		fscanf(fp, "%c", &buffer);															//				THE ) LOADED																

		fscanf(fp, "%c%c%c", &planet_Name[0], &planet_Name[1], &planet_Name[2]);			//
		satelite = create_Planet();															//				
		satelite->planet_name[0] = planet_Name[0];											//				THE SECOND PLANET LOADED
		satelite->planet_name[1] = planet_Name[1];											//
		satelite->planet_name[2] = planet_Name[2];											//					

		fscanf(fp, "%c", &buffer);															//				THE \n LOADED
		k++;
		push_To_Map(map, planet, satelite);
	}

	number_Of_Orbits_To_Santa = calculate_Number_Of_Orbits_To_Santa(map->next_Neighbour);
	printf("\n%d", number_Of_Orbits_To_Santa);

	return 0;
}

Pos create_Planet()
{
	Pos new_Planet = (Pos)malloc(sizeof(struct map));
	if (new_Planet != NULL)
	{
		new_Planet->planet_name[0] = '\0';
		new_Planet->planet_name[1] = '\0';
		new_Planet->planet_name[2] = '\0';
		new_Planet->orbit_level = 0;
		new_Planet->next_Neighbour = NULL;
		new_Planet->next_Satelite = NULL;

		return new_Planet;
	}
	else
		return NULL;
}

Path create_Path_Node()
{
	Path new_path = (Path)malloc(sizeof(struct path));
	if (new_path != NULL)
	{
		Pos planet;
		Path next = NULL;

		return new_path;
	}
	else
		return NULL;
}

void push_To_Front(Pos map, Pos COM)
{
	COM->next_Satelite = map->next_Neighbour;
	map->next_Neighbour = COM;
}

void push_To_Map(Pos map, Pos planet, Pos satelite)
{
	Pos p = map;
	Pos planet_pointer = NULL;
	Pos satelite_pointer = NULL;
	Pos prev = NULL;
	bool COM_is_in_the_map = false;

	if (planet->planet_name[0] == 'C' && planet->planet_name[1] == 'O' && planet->planet_name[2] == 'M')
		push_To_Front(map, planet);

	if (p->next_Neighbour != NULL)
	{
		if (p->next_Neighbour->planet_name[0] == 'C' && p->next_Neighbour->planet_name[1] == 'O' && p->next_Neighbour->planet_name[2] == 'M')
		{
			p = p->next_Neighbour->next_Satelite;
			COM_is_in_the_map = true;
		}
	}

	planet_pointer = find_planet(map, planet);
	if (planet_pointer == NULL)
	{
		while (p->next_Neighbour != NULL)
			p = p->next_Neighbour;

		planet->orbit_level++;
		p->next_Neighbour = planet;

		planet_pointer = planet;
	}

	if (planet_pointer != NULL)
	{
		satelite_pointer = find_planet(map, satelite);
		if (satelite_pointer == NULL)
		{
			satelite->orbit_level = planet_pointer->orbit_level + 1;

			p = planet_pointer;
			if (p->next_Satelite != NULL)
			{
				p = p->next_Satelite;
				if (p->next_Neighbour != NULL)
					while (p->next_Neighbour != NULL)
						p = p->next_Neighbour;
				else
					p->next_Neighbour = satelite;
			}
			else
				p->next_Satelite = satelite;

		}
		else if (satelite_pointer != NULL)
		{	
			if (COM_is_in_the_map == true)
			{
				prev = find_prev(map->next_Neighbour->next_Satelite, satelite_pointer);

				if (prev == NULL)
					map->next_Neighbour->next_Satelite = satelite_pointer->next_Neighbour;
				else
					prev->next_Neighbour = satelite_pointer->next_Neighbour;
			}
			else
			{
				prev = find_prev(map, satelite_pointer);
				prev->next_Neighbour = satelite_pointer->next_Neighbour;
			}

			satelite_pointer->next_Neighbour = planet_pointer->next_Satelite;
			planet_pointer->next_Satelite = satelite_pointer;
			satelite_pointer->orbit_level = planet_pointer->orbit_level + 1;

			recorect_orbit_levels(satelite_pointer);
		}
	}
}

Pos find_planet(Pos map, Pos planet)
{
	Pos p = map;
	Pos current = NULL;

	if (map != NULL)
	{
		if (planet->planet_name[0] == p->planet_name[0] && planet->planet_name[1] == p->planet_name[1] && planet->planet_name[2] == p->planet_name[2])
			return p;
		else
		{
			if (p->next_Satelite != NULL)
				current = find_planet(p->next_Satelite, planet);

			if (current == NULL)
			{
				if (p->next_Neighbour != NULL)
					current = find_planet(p->next_Neighbour, planet);
			}
			return current;
		}
	}
	else
		return NULL;
}

Pos find_prev(Pos map, Pos planet)
{
	Pos prev = map;
	Pos p = map;

	if (planet->planet_name[0] == p->planet_name[0] && planet->planet_name[1] == p->planet_name[1] && planet->planet_name[2] == p->planet_name[2])
		return NULL;

	if (p->next_Neighbour != NULL)
		p = p->next_Neighbour;

	while (p!=NULL)
	{
		if (planet->planet_name[0] == p->planet_name[0] && planet->planet_name[1] == p->planet_name[1] && planet->planet_name[2] == p->planet_name[2])
			return prev;
		else
		{
			prev = p;
			p = p->next_Neighbour;
		}
	}
	
}

int calculate_Number_Of_Orbits(Pos COM)
{
	Pos p = COM;
	int sum = 0;

	if (p->next_Neighbour != NULL)
		sum += calculate_Number_Of_Orbits(p->next_Neighbour);
	if ( p->next_Satelite!=NULL)
		sum += calculate_Number_Of_Orbits(p->next_Satelite);
	

	return sum + p->orbit_level;
}

void recorect_orbit_levels(Pos satelite)
{
	Pos p = satelite->next_Satelite;
	
	while (p!=NULL)
	{
		p->orbit_level = satelite->orbit_level + 1;
		recorect_orbit_levels(p);		
		p = p->next_Neighbour;
	}
}

int calculate_Number_Of_Orbits_To_Santa(Pos COM)
{
	int i = 0;
	Path p = NULL, q = NULL;	
	Pos planet = create_Planet();
	Pos you = NULL, san = NULL;
	Path com_to_you = create_Path_Node();
	Path com_to_san = create_Path_Node();

	planet->planet_name[0] = 'Y';
	planet->planet_name[1] = 'O';
	planet->planet_name[2] = 'U';
	you = find_planet(COM, planet);
	printf("%c%c%c ---- orbit: %d\n", you->planet_name[0], you->planet_name[1], you->planet_name[2], you->orbit_level);

	planet->planet_name[0] = 'S';
	planet->planet_name[1] = 'A';
	planet->planet_name[2] = 'N';
	san = find_planet(COM, planet);
	printf("%c%c%c ---- orbit: %d\n", san->planet_name[0], san->planet_name[1], san->planet_name[2], san->orbit_level);

	find_path_from_root(COM, you, com_to_you);
	find_path_from_root(COM, san, com_to_san);
	
	remove_same_orbits(com_to_you);
	remove_same_orbits(com_to_san);

	p = com_to_you->next;
	q = com_to_san->next;
	while (p->planet == q->planet)
	{
		i++;
		p = p->next;
		q = q->next;
	}

	return ( you->orbit_level + san->orbit_level - 2*i );

}

void find_path_from_root(Pos COM, Pos node, Path path_to_node)
{
	
	Path new_node = NULL;
	if (COM != NULL)
	{
		if (find_planet(COM->next_Neighbour, node) == NULL && find_planet(COM->next_Satelite, node) == NULL)
			path_to_node->next = NULL;
		else if (find_planet(COM->next_Neighbour, node) != NULL || find_planet(COM->next_Satelite, node) != NULL)
		{
			new_node = create_Path_Node();
			new_node->planet = COM;
			path_to_node->next = new_node;
			path_to_node = path_to_node->next;
		}
		if (find_planet(COM->next_Neighbour, node) != NULL)
			find_path_from_root(COM->next_Neighbour, node, path_to_node);
		if (find_planet(COM->next_Satelite, node) != NULL)
			find_path_from_root(COM->next_Satelite, node, path_to_node);
	}
}

void remove_same_orbits(Path path)
{
	Path prev = path;
	Path p = path->next;
	bool removed = false;
	while (p->next != NULL)
	{
		removed = false;

		if (p->planet->orbit_level == p->next->planet->orbit_level)
		{
			prev->next = p->next;
			removed = true;
		}

		if (removed == false)
		{
			prev = p;
			p = p->next;
		}
		else
			p = prev->next;
	}

}