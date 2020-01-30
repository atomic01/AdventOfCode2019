#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

void createPattern(int*, int);
#define SIZE 650

int main()
{
	int i = 0, operationResult = 0, offset = 0, previousResult = 0;
	int* input = (int*)malloc(sizeof(int) * SIZE * 10000);
	int* output = (int*)malloc(sizeof(int) * SIZE * 10000);
	char buffer = '\0';
	FILE* fp = fopen("Puzzle_32.txt", "r+");

	// to get past the text for the puzzle in the txt file 
	while (i < 1511)
	{
		fscanf(fp, "%c", &buffer);
		//printf("%c", buffer);
		i++;

	}
	i = 0;//the input is in
	while (i < SIZE)
	{
		if (fscanf(fp, "%c", &buffer) == 1);
		{
			input[i] = atoi(&buffer);
			//printf("%d", input[i]);
			for (int j = 0; j < 10000; j++)
				input[i + (j * SIZE)] = input[i];
			i++;
		}
	}

	//getoffset
	for (i = 0; i < 7; i++)
		offset = offset * 10 + input[i];

	for (int phaseCounter = 0; phaseCounter < 100; phaseCounter++)
	{
		for (i = offset; i < (SIZE * 10000); i++)
		{
			previousResult = operationResult;
			operationResult = 0;
			if (i == offset)
				for (int j = i; j < (SIZE * 10000); j++)
					operationResult += input[j];
			else
				operationResult = previousResult - input[i - 1];

			output[i] = abs(operationResult % 10);
		}

		for (int j = offset; j < (SIZE * 10000); j++)
			input[j] = output[j];
	}

	for (i = offset; i < (offset + 8); i++)
		printf("%d", input[i]);

	return 0;
}