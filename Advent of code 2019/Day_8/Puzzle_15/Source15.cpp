#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define _CRT_SECURE_NO_WARNINGS

int char_to_digit(char);

int main()
{
	int i = 0, width_of_image = 25, height_of_image = 6, number_of_layers = 0, number_of_zeroes = 0, number_of_ones = 0, number_of_twos = 0, max_number_of_zeroes = 1000, total = 0;
	short int array[15001] = { 0 };
	char buffer = '\0';
	FILE* fp = fopen("Puzzle_15.txt", "r+");

	while (i < 1856) // to get past the text for the puzzle in the txt file where i stored the moduel weights
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

	number_of_layers = i / (height_of_image * width_of_image);

	i = 0;
	while (i < number_of_layers)
	{
		for (int j = 0; j < (height_of_image * width_of_image); j++)
		{
			if (array[i * (height_of_image * width_of_image) + j] == 0)
				number_of_zeroes++;
			else if (array[i * (height_of_image * width_of_image) + j] == 1)
				number_of_ones++;
			else if (array[i * (height_of_image * width_of_image) + j] == 2)
				number_of_twos++;
		}

		if (number_of_zeroes < max_number_of_zeroes)
		{
			max_number_of_zeroes = number_of_zeroes;
			total = number_of_ones * number_of_twos;
		}
		i++;
		number_of_zeroes = 0;
		number_of_ones = 0;
		number_of_twos = 0;
	}

	printf("%d", total);


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