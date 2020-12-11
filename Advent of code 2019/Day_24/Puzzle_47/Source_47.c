#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

#define sampleSize 5
#define memorySize 1000

void printLayout(char * );

void updateLayout(char *, char *);
void copyLayout(char *, char *);
long long int checkForRepetition(char *, long long int*, int);
long long int pow(int, int);

int main()
{
	int i = 0, j = 0, done = 0, itteration = 0;
	long long int result = 0;
	char buffer =  '\0' ;
	char layout[sampleSize][sampleSize] = {"\0"};
	char updatedLayout[sampleSize][sampleSize] = {"\0"};
	long long int memory[memorySize] = {0};
	FILE* fp = fopen("Puzzle.txt", "r+");

	while (i < 2105) // to get past the text for the puzzle in the txt file where i stored the numbers
	{
		fscanf(fp, "%c", &buffer);
		//printf("%c", buffer);
		i++;
	}

	i = 0;
	while (!done)
	{
		fscanf(fp, "%c", &buffer);
		if(feof(fp))
			done = 1;
		else
		{
			if(buffer=='\n')
			{
				i++;
				j=0;
			}
			else
			{
				layout[i][j] = buffer;
				updatedLayout[i][j] = buffer;
				j++;
			}
		}
	}


	while(result == 0)
	{
		updateLayout(&layout[0], &updatedLayout[0]);
		copyLayout(&layout[0], &updatedLayout[0]);
		result = checkForRepetition(&layout[0], &memory[0], itteration);
		itteration++;
	}

	//printLayout(&layout[0]);
	printf("%lld\n", result);

	return 0;
}


void printLayout(char *layout )
{
	for(int i = 0; i < sampleSize; i++)
	{
		for(int j = 0; j < sampleSize; j++)
			printf("%c", *((layout + i*sampleSize) + j) );
		printf("\n");
	}
}




void updateLayout(char *layout, char *updatedLayout)
{
	int neighbours = 0;

	for(int i = 0; i < sampleSize; i++)
	{
		for(int j = 0; j < sampleSize; j++)
		{

			if( i-1>=0 && *((layout + (i-1)*sampleSize) + j)  =='#' )				//UP
				neighbours++;
			if( i+1<sampleSize && *((layout + (i+1)*sampleSize) + j)  =='#' )		//DOWN
				neighbours++;
			if( j-1>=0 && *((layout + i*sampleSize) + j-1)  =='#' )					//LEFT
				neighbours++;
			if( j+1<sampleSize && *((layout + i*sampleSize) + j+1)  =='#' )			//RIGHT
				neighbours++;

			if(*((layout + i*sampleSize) + j)=='#' && neighbours != 1)
				*((updatedLayout + i*sampleSize) + j) = '.';
			if(*((layout + i*sampleSize) + j)=='.' && (neighbours == 1 || neighbours == 2))
				*((updatedLayout + i*sampleSize) + j) = '#';
			neighbours = 0;
		}
	}

}

void copyLayout(char *layout, char *updatedLayout)
{
	for(int i = 0; i < sampleSize; i++)
		for(int j = 0; j < sampleSize; j++)
			*((layout + i*sampleSize) + j) = *((updatedLayout + i*sampleSize) + j);
}

long long int checkForRepetition(char *layout, long long int *memory, int itteration)
{
	long long int result = 0;

	for(int i = 0; i < sampleSize; i++)
		for(int j = 0; j < sampleSize; j++)
			if( *((layout + i*sampleSize) + j) == '#')
				result+= pow(2, sampleSize*i + j);

	for(int i = 0; i < memorySize; i++)
		if(memory[i] == result)
			return result;
	memory[itteration] = result;

	return 0;
}

long long int pow(int b, int p)
{
	long long int x = 1;

	for(int i=0; i < p; i++)
		x*=b;

	return x;
}

