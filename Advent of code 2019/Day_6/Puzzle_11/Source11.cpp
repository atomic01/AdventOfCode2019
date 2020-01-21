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
	Pos parent;
	Pos next_Neighbour;
	Pos next_Satelite;
};

Pos create_Planet();
void push_Front(Pos, Pos);
void push_To_Map(Pos, Pos, Pos);
int calculate_Number_Of_Orbits(Pos);
Pos find_planet(Pos, Pos);
Pos find_prev(Pos, Pos);
void recorect_orbit_levels(Pos );

int main()
{
	FILE* fp = fopen("Puzzle_11.txt", "r+");
	int i = 0;
	char buffer = '\0';
	char planet_Name[3] = { '\0' };
	Pos map = create_Planet();
	Pos planet = NULL;
	Pos satelite = NULL;
	int number_Of_Orbits = 0;
	int k = 0;
	while (i < 2141)//to get past the text of the 
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

	number_Of_Orbits = calculate_Number_Of_Orbits(map->next_Neighbour);
	printf("%d", number_Of_Orbits);

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
		new_Planet->parent = NULL;
		new_Planet->next_Neighbour = NULL;
		new_Planet->next_Satelite = NULL;

		return new_Planet;
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
			//satelite->parent = planet_pointer;

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