#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define _CRT_SECURE_NO_WARNINGS


int main()
{

	int array[121] = { 0 };
	int counter_f = 0, counter_s = 0;
	int i = 0, x = 121;//x is size of array
	int initial_array[121] = { 1,0,0,3,1,1,2,3,1,3,4,3,1,5,0,3,2,1,10,19,1,6,19,23,2,23,6,27,2,6,27,31,2,13,31,35,1,10,35,39,2,39,13,43,1,43,13,47,1,6,47,51,1,10,51,55,2,55,6,59,1,5,59,63,2,9,63,67,1,6,67,71,2,9,71,75,1,6,75,79,2,79,13,83,1,83,10,87,1,13,87,91,1,91,10,95,2,9,95,99,1,5,99,103,2,10,103,107,1,107,2,111,1,111,5,0,99,2,14,0,0 };

	while (i < x)
	{
		if (array[i] == 1)
			array[array[i + 3]] = array[array[i + 1]] + array[array[i + 2]];
		else if (array[i] == 2)
			array[array[i + 3]] = array[array[i + 1]] * array[array[i + 2]];
		else if (array[i] == 99)
			i = x;

		i += 4;
	}

	for (counter_f = 0; counter_f <= 99; counter_f++)
	{
		for (counter_s = 0; counter_s <= 99; counter_s++)
		{
			for (i = 0; i < 121; i++)
				array[i] = initial_array[i];

			array[1] = counter_f;
			array[2] = counter_s;

			i = 0;
			while (i < x)
			{
				if (array[i] == 1)
					array[array[i + 3]] = array[array[i + 1]] + array[array[i + 2]];
				else if (array[i] == 2)
					array[array[i + 3]] = array[array[i + 1]] * array[array[i + 2]];
				else if (array[i] == 99)
					i = x;

				i += 4;
			}

			if (array[0] == 19690720)
			{
				printf("noun:%d\tverb:%d---------%d", counter_f, counter_s, array[0]);
				printf("\n100 * noun + verb: %d", (100 * counter_f) + counter_s);
				counter_f = 99;
			}

		}

	}

	return 0;
}