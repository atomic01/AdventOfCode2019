#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

void createPattern(int*, int);

int main()
{
	int i=0, operationResult = 0, input[650] = { 0 }, output[650] = { 0 }, pattern[651] = { 0 };
	int* patternPointer = pattern;
	char buffer = '\0';
	FILE* fp = fopen("Puzzle_31.txt", "r+");

	// to get past the text for the puzzle in the txt file 
	while (i < 4717) 
	{
		fscanf(fp, "%c", &buffer);
		//printf("%c", buffer);
		i++;

	}
	i = 0;//the input is in
	while (i < 650)
	{
		if(fscanf(fp, "%c", &buffer)==1 );
		{
			input[i] = atoi(&buffer);
			//printf("%d", input[i]);
			i++;
		}
	}

	for (int phaseCounter = 0; phaseCounter < 100; phaseCounter++)
	{
		for (i = 0; i < 650; i++)
		{
			createPattern(patternPointer, i+1);

			operationResult = 0;
			for (int j = 0; j < 650; j++)
				operationResult += input[j] * pattern[j];
			output[i] = abs(operationResult % 10);
		}	

		for (int j = 0; j < 650; j++)
			input[j] = output[j];
	}
	
	for (int i = 0; i < 8; i++)
		printf("%d", input[i]);

	return 0;
}

void createPattern(int *patternPointer, int i)
{
	int values[4] = { 0,1,0,-1 };
	int j = 0, valueCounter = 0, repetitionCoutner = 0;

	valueCounter = 0;
	repetitionCoutner = 0;
	j = 0;
	while (j < 651)
	{
		if (repetitionCoutner == i )
		{
			repetitionCoutner = 0;
			valueCounter++;

			if (valueCounter == 4)
				valueCounter = 0;
		}
		patternPointer[j] = values[valueCounter];
		repetitionCoutner++;
		j++;
	}

	//shift the pattern to the left
	for (j = 0; j < 650; j++)
		patternPointer[j] = patternPointer[j + 1];
	patternPointer[650] = 2;//terminator
}
