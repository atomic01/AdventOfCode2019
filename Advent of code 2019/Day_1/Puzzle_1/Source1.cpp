#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	unsigned int modul_weight = 0, total_fuel=0, i = 0;
	char buffer =  '\0' ;
	FILE* fp = fopen("Puzzle_1.txt", "r+");

	while (i < 1496) // to get past the text for the puzzle in the txt file where i stored the moduel weights
	{
		fscanf(fp, "%c", &buffer);
		//printf("%c", buffer);
		i++;

	}

	while (!feof(fp))
	{
		fscanf(fp, "%d", &modul_weight);
		//printf("%d\n", modul_weight);

		modul_weight = int(modul_weight / 3) - 2;
		total_fuel += modul_weight;
	}

	printf("%d", total_fuel);


	return 0;
}