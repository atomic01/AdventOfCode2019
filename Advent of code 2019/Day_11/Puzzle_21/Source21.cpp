#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define _CRT_SECURE_NO_WARNINGS


int main()
{
	long long int i = 0, x = 657;//x is size of array
	long long int array[1000] = { 3,8,1005,8,335,1106,0,11,0,0,0,104,1,104,0,3,8,1002,8,-1,10,1001,10,1,10,4,10,108,0,8,10,4,10,102,1,8,28,3,8,1002,8,-1,10,1001,10,1,10,4,10,1008,8,1,10,4,10,101,0,8,51,1006,0,82,1006,0,56,1,1107,0,10,3,8,102,-1,8,10,101,1,10,10,4,10,1008,8,0,10,4,10,1001,8,0,83,3,8,1002,8,-1,10,101,1,10,10,4,10,108,1,8,10,4,10,101,0,8,104,1006,0,58,3,8,1002,8,-1,10,1001,10,1,10,4,10,108,0,8,10,4,10,1001,8,0,129,1006,0,54,1006,0,50,1006,0,31,3,8,1002,8,-1,10,1001,10,1,10,4,10,1008,8,1,10,4,10,102,1,8,161,2,101,14,10,1006,0,43,1006,0,77,3,8,102,-1,8,10,1001,10,1,10,4,10,1008,8,0,10,4,10,102,1,8,193,2,101,12,10,2,109,18,10,1,1009,13,10,3,8,102,-1,8,10,101,1,10,10,4,10,108,1,8,10,4,10,102,1,8,226,1,1103,1,10,1,1007,16,10,1,3,4,10,1006,0,88,3,8,102,-1,8,10,101,1,10,10,4,10,108,1,8,10,4,10,1001,8,0,263,1006,0,50,2,1108,17,10,1006,0,36,1,9,8,10,3,8,1002,8,-1,10,101,1,10,10,4,10,1008,8,0,10,4,10,1002,8,1,300,1006,0,22,2,106,2,10,2,1001,19,10,1,3,1,10,101,1,9,9,1007,9,925,10,1005,10,15,99,109,657,104,0,104,1,21101,0,937268454156,1,21102,1,352,0,1106,0,456,21101,0,666538713748,1,21102,363,1,0,1105,1,456,3,10,104,0,104,1,3,10,104,0,104,0,3,10,104,0,104,1,3,10,104,0,104,1,3,10,104,0,104,0,3,10,104,0,104,1,21101,3316845608,0,1,21102,1,410,0,1105,1,456,21101,0,209475103911,1,21101,421,0,0,1106,0,456,3,10,104,0,104,0,3,10,104,0,104,0,21101,0,984353603944,1,21101,444,0,0,1105,1,456,21102,1,988220752232,1,21102,1,455,0,1106,0,456,99,109,2,22101,0,-1,1,21102,40,1,2,21101,487,0,3,21101,0,477,0,1106,0,520,109,-2,2105,1,0,0,1,0,0,1,109,2,3,10,204,-1,1001,482,483,498,4,0,1001,482,1,482,108,4,482,10,1006,10,514,1102,0,1,482,109,-2,2105,1,0,0,109,4,2101,0,-1,519,1207,-3,0,10,1006,10,537,21101,0,0,-3,22101,0,-3,1,22101,0,-2,2,21102,1,1,3,21101,556,0,0,1106,0,561,109,-4,2106,0,0,109,5,1207,-3,1,10,1006,10,584,2207,-4,-2,10,1006,10,584,21201,-4,0,-4,1106,0,652,22101,0,-4,1,21201,-3,-1,2,21202,-2,2,3,21101,0,603,0,1105,1,561,22101,0,1,-4,21102,1,1,-1,2207,-4,-2,10,1006,10,622,21102,1,0,-1,22202,-2,-1,-2,2107,0,-3,10,1006,10,644,21201,-1,0,1,21101,644,0,0,105,1,519,21202,-2,-1,-2,22201,-4,-2,-4,109,-5,2106,0,0 };
	int opcode = 0;
	int first_op = 0, second_op = 0, third_op = 0;
	long long int first_parametar = 0, second_parametar = 0, third_parametar = 0;
	long long int code = 0, rel_base = 0;
	char panels[200][200] = { '.' };
	bool paintedAtleastOnce[200][200] = { false };
	int panelWidth = 100, panelHeight = 100;
	int panelColor = 0;//0 black, 1 white
	char direction = '0';
	int output[2] = { 0,0 };
	int outputCounter = 0;

	for (i = 0; i < 200; i++)
		for (int j = 0; j < 200; j++)
			panels[i][j] = '.';

	i = 0;

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
				if (panels[panelHeight][panelWidth] == '.')
					panelColor = 0;
				else if (panels[panelHeight][panelWidth] == '#')
					panelColor = 1;

				if (direction == '0')
					direction = '^';

				array[first_parametar] = panelColor;
			}
			else if (opcode == 4)
			{
				output[outputCounter] = first_parametar;

				if (outputCounter == 0)
					outputCounter++;
				else if (outputCounter == 1)
				{
					outputCounter--;

					if (output[0] == 0)
						panels[panelHeight][panelWidth] = '.';
					else if (output[0] == 1)
						panels[panelHeight][panelWidth] = '#';

					paintedAtleastOnce[panelHeight][panelWidth] = true;

					if (output[1] == 0)
					{
						if (direction == '^')
						{
							direction = '<';
							panelWidth--;
						}
						else if (direction == '<')
						{
							direction = 'ˇ';
							panelHeight++;
						}
						else if (direction == 'ˇ')
						{
							direction = '>';
							panelWidth++;
						}
						else if (direction == '>')
						{
							direction = '^';
							panelHeight--;
						}
					}
					else if (output[1] == 1)
					{
						if (direction == '^')
						{
							direction = '>';
							panelWidth++;
						}
						else if (direction == '>')
						{
							direction = 'ˇ';
							panelHeight++;
						}
						else if (direction == 'ˇ')
						{
							direction = '<';
							panelWidth--;
						}
						else if (direction == '<')
						{
							direction = '^';
							panelHeight--;
						}
					}
				}
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

	for (i = 0; i < 200; i++)
		for (int j = 0; j < 200; j++)
			if (paintedAtleastOnce[i][j] == true)
				outputCounter++;

	printf("%d", outputCounter);

	return 0;
}
