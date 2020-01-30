#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define _CRT_SECURE_NO_WARNINGS
#define SIZE_OF_GRID 50


int main()
{
	long long int i = 0, x = 422;//x is size of array
	long long int originalArray[1000] = { 109,424,203,1,21102,1,11,0,1106,0,282,21101,0,18,0,1105,1,259,2102,1,1,221,203,1,21102,31,1,0,1106,0,282,21101,38,0,0,1106,0,259,21002,23,1,2,21202,1,1,3,21102,1,1,1,21102,57,1,0,1106,0,303,2102,1,1,222,21001,221,0,3,21002,221,1,2,21101,0,259,1,21102,1,80,0,1106,0,225,21102,1,93,2,21102,1,91,0,1106,0,303,2101,0,1,223,21001,222,0,4,21102,1,259,3,21101,225,0,2,21101,225,0,1,21101,118,0,0,1106,0,225,20101,0,222,3,21102,1,120,2,21102,1,133,0,1106,0,303,21202,1,-1,1,22001,223,1,1,21101,0,148,0,1106,0,259,2102,1,1,223,21001,221,0,4,20102,1,222,3,21102,1,23,2,1001,132,-2,224,1002,224,2,224,1001,224,3,224,1002,132,-1,132,1,224,132,224,21001,224,1,1,21102,195,1,0,106,0,108,20207,1,223,2,20101,0,23,1,21101,-1,0,3,21102,1,214,0,1106,0,303,22101,1,1,1,204,1,99,0,0,0,0,109,5,2101,0,-4,249,21201,-3,0,1,21201,-2,0,2,21202,-1,1,3,21101,0,250,0,1105,1,225,21202,1,1,-4,109,-5,2106,0,0,109,3,22107,0,-2,-1,21202,-1,2,-1,21201,-1,-1,-1,22202,-1,-2,-2,109,-3,2106,0,0,109,3,21207,-2,0,-1,1206,-1,294,104,0,99,22102,1,-2,-2,109,-3,2106,0,0,109,5,22207,-3,-4,-1,1206,-1,346,22201,-4,-3,-4,21202,-3,-1,-1,22201,-4,-1,2,21202,2,-1,-1,22201,-4,-1,1,21201,-2,0,3,21102,343,1,0,1106,0,303,1106,0,415,22207,-2,-3,-1,1206,-1,387,22201,-3,-2,-3,21202,-2,-1,-1,22201,-3,-1,3,21202,3,-1,-1,22201,-3,-1,2,21201,-4,0,1,21101,0,384,0,1106,0,303,1105,1,415,21202,-4,-1,-4,22201,-4,-3,-4,22202,-3,-2,-2,22202,-2,-4,-4,22202,-3,-2,-3,21202,-4,-1,-2,22201,-3,-2,1,21202,1,1,-4,109,-5,2106,0,0 };
	long long int array[1000] = { 109,424,203,1,21102,1,11,0,1106,0,282,21101,0,18,0,1105,1,259,2102,1,1,221,203,1,21102,31,1,0,1106,0,282,21101,38,0,0,1106,0,259,21002,23,1,2,21202,1,1,3,21102,1,1,1,21102,57,1,0,1106,0,303,2102,1,1,222,21001,221,0,3,21002,221,1,2,21101,0,259,1,21102,1,80,0,1106,0,225,21102,1,93,2,21102,1,91,0,1106,0,303,2101,0,1,223,21001,222,0,4,21102,1,259,3,21101,225,0,2,21101,225,0,1,21101,118,0,0,1106,0,225,20101,0,222,3,21102,1,120,2,21102,1,133,0,1106,0,303,21202,1,-1,1,22001,223,1,1,21101,0,148,0,1106,0,259,2102,1,1,223,21001,221,0,4,20102,1,222,3,21102,1,23,2,1001,132,-2,224,1002,224,2,224,1001,224,3,224,1002,132,-1,132,1,224,132,224,21001,224,1,1,21102,195,1,0,106,0,108,20207,1,223,2,20101,0,23,1,21101,-1,0,3,21102,1,214,0,1106,0,303,22101,1,1,1,204,1,99,0,0,0,0,109,5,2101,0,-4,249,21201,-3,0,1,21201,-2,0,2,21202,-1,1,3,21101,0,250,0,1105,1,225,21202,1,1,-4,109,-5,2106,0,0,109,3,22107,0,-2,-1,21202,-1,2,-1,21201,-1,-1,-1,22202,-1,-2,-2,109,-3,2106,0,0,109,3,21207,-2,0,-1,1206,-1,294,104,0,99,22102,1,-2,-2,109,-3,2106,0,0,109,5,22207,-3,-4,-1,1206,-1,346,22201,-4,-3,-4,21202,-3,-1,-1,22201,-4,-1,2,21202,2,-1,-1,22201,-4,-1,1,21201,-2,0,3,21102,343,1,0,1106,0,303,1106,0,415,22207,-2,-3,-1,1206,-1,387,22201,-3,-2,-3,21202,-2,-1,-1,22201,-3,-1,3,21202,3,-1,-1,22201,-3,-1,2,21201,-4,0,1,21101,0,384,0,1106,0,303,1105,1,415,21202,-4,-1,-4,22201,-4,-3,-4,22202,-3,-2,-2,22202,-2,-4,-4,22202,-3,-2,-3,21202,-4,-1,-2,22201,-3,-2,1,21202,1,1,-4,109,-5,2106,0,0 };
	int opcode = 0, counter = 0;
	int first_op = 0, second_op = 0, third_op = 0, firstDimension = 0;
	long long int first_parametar = 0, second_parametar = 0, third_parametar = 0;
	long long int code = 0, rel_base = 0;
	char grid[SIZE_OF_GRID][SIZE_OF_GRID] = { " " };
	
	for (int yy = 0; yy < SIZE_OF_GRID; yy++)
	{
		for (int xx = 0; xx < SIZE_OF_GRID; xx++)
		{
			firstDimension = 0;
			for (i = 0; i < 1000; i++)
				array[i] = originalArray[i];
			i = 0;
			rel_base = 0;

			while (i < x)
			{
				code = array[i];
				opcode = code % 100;
				first_op = (code / 100) % 10;
				second_op = (code / 1000) % 10;
				third_op = code / 10000;

				if (opcode == 99)
					i = x;
				else
				{
					if (first_op == 0)																//0 means position mode			 1 means immideate mode 
						first_parametar = array[array[i + 1]];
					else if (first_op == 1)
						first_parametar = array[i + 1];
					else if (first_op == 2)
						first_parametar = array[array[i + 1] + rel_base];

					if (opcode != 3 && opcode != 4 && opcode != 9)
					{
						if (second_op == 0)
							second_parametar = array[array[i + 2]];
						else if (second_op == 1)
							second_parametar = array[i + 2];
						else if (second_op == 2)
							second_parametar = array[array[i + 2] + rel_base];
					}
					//Parameters that an instruction writes to will never be in immediate mode. meaning ALWAYS position mode or relative mode
					if (opcode < 3 || opcode == 8 || opcode == 7)
					{
						if (third_op == 0)
							third_parametar = array[i + 3];
						else if (third_op == 2)
							third_parametar = array[i + 3] + rel_base;
					}
					else if (opcode == 3)
					{
						if (first_op == 0)
							first_parametar = array[i + 1];
						else if (first_op == 2)
							first_parametar = array[i + 1] + rel_base;
					}

					if (opcode == 1)
						array[third_parametar] = first_parametar + second_parametar;
					else if (opcode == 2)
						array[third_parametar] = first_parametar * second_parametar;
					else if (opcode == 3)
					{
						if (firstDimension == 0)
							array[first_parametar] = xx;
						else
							array[first_parametar] = yy;

						firstDimension++;
					}
					else if (opcode == 4)
					{
						if (first_parametar == 0)
							grid[yy][xx] = '.';
						else if(first_parametar == 1)
							grid[yy][xx] = '#';
					}
					else if (opcode == 5)
					{
						if (first_parametar != 0)
							i = second_parametar;
						else
							i += 3;
					}
					else if (opcode == 6)
					{
						if (first_parametar == 0)
							i = second_parametar;
						else
							i += 3;
					}
					else if (opcode == 7)
					{
						if (first_parametar < second_parametar)
							array[third_parametar] = 1;
						else
							array[third_parametar] = 0;
					}
					else if (opcode == 8)
					{
						if (first_parametar == second_parametar)
							array[third_parametar] = 1;
						else
							array[third_parametar] = 0;
					}
					else if (opcode == 9)
						rel_base += first_parametar;

					if (opcode == 1 || opcode == 2 || opcode == 7 || opcode == 8)
						i += 4;
					else if (opcode == 3 || opcode == 4 || opcode == 9)
						i += 2;

					first_op = 0;
					second_op = 0;
					third_op = 0;

				}
			}
		}
	}
	
	for (int i = 0; i < SIZE_OF_GRID; i++)
	{
		for (int j = 0; j < SIZE_OF_GRID; j++)
		{
			printf("%c", grid[j][i]);
			if (grid[j][i] == '#')
				counter++;
		}
		printf("\n");

	}
	printf("%d", counter);

	return 0;
}
