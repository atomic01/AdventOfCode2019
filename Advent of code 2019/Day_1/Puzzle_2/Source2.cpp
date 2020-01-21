#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int fuel_formula(int);
int calculate_weight(int );

int main()
{
	unsigned int modul_weight = 0, total_fuel = 0, i = 0;
	char buffer = '\0';
	FILE* fp = fopen("Puzzle_2.txt", "r+");

	while (i < 1725 ) // to get past the text for the puzzle in the txt file where i stored the moduel weights
	{
		fscanf(fp, "%c", &buffer);
		//printf("%c", buffer);
		i++;

	}

	while (!feof(fp))
	{
		fscanf(fp, "%d", &modul_weight);
		//printf("%d\n", modul_weight);

		modul_weight = calculate_weight(modul_weight);
		total_fuel += modul_weight;
	}

	printf("%d", total_fuel);


	return 0;
}

int fuel_formula(int modul_weight)
{
	return (int(modul_weight / 3)) - 2;
}

int calculate_weight(int modul_weight)
{
	int fuel_weight=0, total_fuel = 0;

	fuel_weight = fuel_formula(modul_weight);
	total_fuel += fuel_weight;

	if( fuel_formula(fuel_weight) > 0 )
		total_fuel += calculate_weight(fuel_weight);

	return total_fuel;
}
