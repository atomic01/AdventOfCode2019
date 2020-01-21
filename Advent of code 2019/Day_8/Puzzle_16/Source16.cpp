#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define _CRT_SECURE_NO_WARNINGS

int char_to_digit(char);

int main()
{
	int i = 0, j = 0, width_of_image = 25, height_of_image = 6, number_of_layers = 0;
	short int array[15001] = { 0 };
	short int picture[100][150] = { 0 };
	short int message[150] = { 0 };
	char buffer = '\0';
	bool pixel_copied = false;
	FILE* fp = fopen("Puzzle_16.txt", "r+");

	while (i < 1332) // to get past the text for the puzzle in the txt file where i stored the moduel weights
	{
		fscanf(fp, "%c", &buffer);
		//printf("%c", buffer);
		i++;
	}

	i = 0;
	while (!feof(fp))
	{

		fscanf(fp, "%c", &buffer);
		//printf("%c", buffer);

		array[i] = char_to_digit(buffer);
		i++;
	}

	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < 150; j++)
			picture[i][j] = array[(i * 150) + j];
	}

	for (i = 0; i < 150; i++)
	{
		bool pixel_copied = false;
		j = 0;

		while (pixel_copied == false)
		{
			if (picture[j][i] == 2)//transparent
				j++;
			else
			{
				message[i] = picture[j][i];
				pixel_copied = true;
			}
		}

	}

	int pixel_cunter = 0;
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 25; j++)
		{
			if (message[pixel_cunter] == 0)
				printf(" ");
			else if (message[pixel_cunter] == 1)
				printf( "#");

			pixel_cunter++;
		}
		printf( "\n");
	}

	return 0;
}

int char_to_digit(char c)
{
	if (c == '0')
		return 0;
	else if (c == '1')
		return 1;
	else if (c == '2')
		return 2;
	else if (c == '3')
		return 3;
	else if (c == '4')
		return 4;
	else if (c == '5')
		return 5;
	else if (c == '6')
		return 6;
	else if (c == '7')
		return 7;
	else if (c == '8')
		return 8;
	else if (c == '9')
		return 9;
}