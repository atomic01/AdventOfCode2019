#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define _CRT_SECURE_NO_WARNINGS

void findNewMonitoringStationLocation(char [20][20]);
int findNumberOfVisibleAsteroids(int , int , char[20][20]);
int gdcFunction(int, int);

int main()
{
	FILE* fp = fopen("Puzzle_19.txt", "r+");
	char buffer = '0';
	int i = 0, j = 0;
	char array[20][20] = { 0 };

	while (i < 3262)
	{
		fscanf(fp, "%c", &buffer);
		//printf("%c", buffer);
		i++;
	}
	i = 0;

	while (j < 20)
	{
		fscanf(fp, "%c", &buffer);

		if (buffer == '\n')
		{
			j++;
			i = 0;
		}
		else
		{
			array[j][i] = buffer;
			i++;
		}
	}

	findNewMonitoringStationLocation(array);


	return 0;
}

void findNewMonitoringStationLocation(char map[20][20])
{
	int max = 0, current = 0;
	int maxI = 0, maxJ = 0;

	for (int j = 0; j < 20; j++)
	{
		for (int i = 0; i < 20; i++)
		{
			if (map[j][i] == '#')
			{
				current = findNumberOfVisibleAsteroids(i, j, map);
				if (current > max)
				{
					max = current;
					maxI = i;
					maxJ = j;
				}
			}
		}
	}	

	printf("x:%d\ty:%d\t[%d]",maxI,maxJ, max);
}

int findNumberOfVisibleAsteroids(int x, int y, char map[20][20])
{
	int numberOfVisibleAsteroids = 0, counter = 0;
	int numberOfBlockingPositions = 0;
	bool isTheAsteroidVisible = true;
	int xdiff = 0, ydiff = 0;
	int gdc = 0;
	int iCounter = 0, jCounter = 0;

	for (int j = 0; j < 20; j++)
	{
		for (int i = 0; i < 20; i++)
		{
			isTheAsteroidVisible = true;

			if (map[j][i] == '#' && !(j == y && i == x))
			{
				//IN THE SAME ROW
				if (j == y)
				{
					counter = i;
					if (counter < x)												//ON THE LEFT SIDE
					{
						while (counter < (x-1))
						{
							counter++;
							if (map[j][counter] == '#')
							{
								isTheAsteroidVisible = false;
								counter == x - 1;
							}
						}
					}
					else if (counter > x)											//ON THE RIGHT SIDE
					{
						while (counter > (x + 1))
						{
							counter--;
							if (map[j][counter] == '#')
							{
								isTheAsteroidVisible = false;
								counter == x + 1;
							}
						}
					}
				}
				//IN THE SAME COLLUMN
				else if (i == x)
				{
					counter = j;
					if (counter < y)												//ABOVE
					{
						while (counter < (y - 1))
						{
							counter++;
							if (map[counter][i] == '#')
							{
								isTheAsteroidVisible = false;
								counter == y - 1;
							}
						}
					}
					else if (counter > y)											//BELOW
					{
						while (counter > (y + 1))
						{
							counter--;
							if (map[counter][i] == '#')
							{
								isTheAsteroidVisible = false;
								counter == y + 1;
							}
						}
					}
				}
				//ABOVE 
				else if (j < y)
				{
					iCounter = i;
					jCounter = j;
					//ON THE LEFT
					if (i < x)
					{
						xdiff = x - i;
						ydiff = y - j;

						gdc = gdcFunction(xdiff, ydiff);
						numberOfBlockingPositions = gdc - 1;

						while (numberOfBlockingPositions != 0)
						{
							iCounter += xdiff / gdc;
							jCounter += ydiff / gdc;

							if (map[jCounter][iCounter] == '#')
							{
								isTheAsteroidVisible = false;
								numberOfBlockingPositions = 0;
							}
							else
								numberOfBlockingPositions--;
						}
						
					}
					//ON THE RIGHT
					else if (i > x)
					{
						xdiff = i - x;
						ydiff = y - j;

						gdc = gdcFunction(xdiff, ydiff);
						numberOfBlockingPositions = gdc - 1;

						while (numberOfBlockingPositions != 0)
						{
							iCounter -= xdiff / gdc;
							jCounter += ydiff / gdc;

							if (map[jCounter][iCounter] == '#')
							{
								isTheAsteroidVisible = false;
								numberOfBlockingPositions = 0;
							}
							else
								numberOfBlockingPositions--;
						}

					}
				}
				//BELOW
				else if (j > y)
				{
					iCounter = i;
					jCounter = j;
					//ON THE LEFT
					if (i < x)
					{
						xdiff = x - i;
						ydiff = j - y;

						gdc = gdcFunction(xdiff, ydiff);
						numberOfBlockingPositions = gdc - 1;

						while (numberOfBlockingPositions != 0)
						{
							iCounter += xdiff / gdc;
							jCounter -= ydiff / gdc;

							if (map[jCounter][iCounter] == '#')
							{
								isTheAsteroidVisible = false;
								numberOfBlockingPositions = 0;
							}
							else
								numberOfBlockingPositions--;
						}

					}
					//ON THE RIGHT
					else if (i > x)
					{
						xdiff = i - x;
						ydiff = j - y;

						gdc = gdcFunction(xdiff, ydiff);
						numberOfBlockingPositions = gdc - 1;

						while (numberOfBlockingPositions != 0)
						{
							iCounter -= xdiff / gdc;
							jCounter -= ydiff / gdc;

							if (map[jCounter][iCounter] == '#')
							{
								isTheAsteroidVisible = false;
								numberOfBlockingPositions = 0;
							}
							else
								numberOfBlockingPositions--;
						}

					}
				}
			
				if (isTheAsteroidVisible == true)
					numberOfVisibleAsteroids++;
			}
		}
	}

	return numberOfVisibleAsteroids;
}

int gdcFunction(int a, int b)
{
	int temp = 0;
	int gdc = 0;
	bool complete = false;

	if (a < b) //a should always be bigger
	{
		temp = b;
		b = a;
		a = temp;
	}

	gdc = b;

	while (complete==false)
	{
		if (b % gdc == 0 && a % gdc == 0)
			complete = true;
		else
			gdc--;
	}

	return gdc;
}

