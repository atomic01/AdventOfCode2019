#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct List;
typedef struct List* Pos;
struct List {

	short int x;
	short int y;
	
	Pos next;
};

Pos createPos();
void construct_wires(Pos , Pos );
void find_closest_intercection(Pos, Pos);
bool do_the_lines_intersect(Pos , Pos , Pos , Pos );

int main()
{
	Pos wire_one = createPos();
	Pos wire_two = createPos();

	construct_wires(wire_one, wire_two);
	find_closest_intercection(wire_one, wire_two);
		
	return 0;
}

Pos createPos()
{
	Pos newPos = (Pos)malloc(sizeof(struct List));
	newPos->x = 0;
	newPos->y = 0;
	newPos->next = NULL;

	return newPos;
}

void construct_wires(Pos wire_one, Pos wire_two)
{
	int i = 0, x = 0;
	char c = { '\0' };
	FILE* fp = fopen("Puzzle_5.txt", "r+");

	Pos temp;
	Pos p = createPos();//the begging of the wires
	Pos q = createPos();
	wire_one->next = p;
	wire_two->next = q;

	while (i < 1803) // to get past the text for the puzzle in the txt file where i stored the moduel weights
	{
		fscanf(fp, "%c", &c);
		i++;
	}
	
	i = 0;
	while (i < 301)
	{
		fscanf(fp, "%c", &c);
		fscanf(fp, "%d", &x);

		temp = createPos();
		p->next = temp;

		if (c == 'R')
			temp->x = p->x + x;
		else if (c == 'L')
			temp->x = p->x - x;
		else if (c == 'U')
			temp->y = p->y + x;
		else if (c == 'D')
			temp->y = p->y - x;

		if (c == 'R' || c == 'L')
			temp->y = p->y;
		else if (c == 'U' || c == 'D')
			temp->x = p->x;

		p = p->next;
	
		fscanf(fp, "%c", &c);
		i++;
	}

	while (i < 602)
	{
		fscanf(fp, "%c", &c);
		fscanf(fp, "%d", &x);

		temp = createPos();
		q->next = temp;

		if (c == 'R')
			temp->x = q->x + x;
		else if (c == 'L')
			temp->x = q->x - x;
		else if (c == 'U')
			temp->y = q->y + x;
		else if (c == 'D')
			temp->y = q->y - x;

		if (c == 'R' || c == 'L')
			temp->y = q->y;
		else if (c == 'U' || c == 'D')
			temp->x = q->x;


		q = q->next;

		fscanf(fp, "%c", &c);
		i++;
	}
}

void find_closest_intercection(Pos wire_one, Pos wire_two)
{
	int distance = 385765;
	Pos p1 = wire_one->next;
	Pos q1 = p1->next;

	Pos p2 = wire_two->next;
	Pos q2 = p2->next;

	while (q1 != NULL)
	{

		if (p1->y == q1->y)//if horisontal line in the first wire
		{
			while (q2 != NULL)
			{
				 if (p2->x == q2->x && do_the_lines_intersect(p1, q1, p2, q2) == true )//if vertical line in the second wire and if the intersect
				 {
					 if ((abs(p1->y) + abs(p2->x)) < distance)
						 distance = (abs(p1->y) + abs(p2->x));
				 }

				 p2 = p2->next;
				 q2 = q2->next;
				 
			}
			p2 = wire_two->next;
			q2 = p2->next;
		}
		else if (p1->x == q1->x)//if vertical line in the first  wire
		{
			while (q2 != NULL)
			{
				if (p2->y == q2->y && do_the_lines_intersect(p2, q2, p1, q1) == true)//if horisontal line in the second wire and if the intersect
				{
					if ((abs(p1->x) + abs(p2->y)) < distance)
						distance = (abs(p1->x) + abs(p2->y));
				}
	
				p2 = p2->next;
				q2 = q2->next;	
			}
			p2 = wire_two->next;
			q2 = p2->next;
		}

		p1 = p1->next;
		q1 = q1->next;

	}

	printf("%d", distance);
}

bool do_the_lines_intersect(Pos p1, Pos q1 , Pos p2, Pos q2)
{
	if (((p1->y <= p2->y) && (p1->y >= q2->y)) || ((p1->y <= q2->y) && (p1->y >= p2->y)))
	{
		if (((p2->x <= p1->x) && (p2->x >= q1->x)) || ((p2->x <= q1->x) && (p2->x >= p1->x)))
			return true;

		else
			return false;
	}
	else
		return false;
}
