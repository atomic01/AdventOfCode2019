#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define _CRT_SECURE_NO_WARNINGS

int computation(int, int, int, int, int);
bool check_phase_modes(int, int, int, int, int);

int main()
{
	int i, j, k, l, m;
	int max_output = 0, permutation_output = 0;

	for (i = 5; i < 10; i++)
	{
		for (j = 5; j < 10; j++)
		{
			for (k = 5; k < 10; k++)
			{
				for (l = 5; l < 10; l++)
				{
					for (m = 5; m < 10; m++)
					{
						if (check_phase_modes(i, j, k, l, m) == true)
						{
							permutation_output = computation(i, j, k, l, m);
							if (permutation_output > max_output)
								max_output = permutation_output;
						}
					}
				}
			}
		}
	}

	printf("%d", max_output);

	return 0;
}

int computation(int y, int j, int k, int l, int m)
{
	int i = 0, x = 503;//x is size of array
	int values_array[503] = { 3,8,1001,8,10,8,105,1,0,0,21,34,51,68,89,98,179,260,341,422,99999,3,9,1001,9,4,9,102,4,9,9,4,9,99,3,9,1002,9,5,9,1001,9,2,9,1002,9,2,9,4,9,99,3,9,1001,9,3,9,102,3,9,9,101,4,9,9,4,9,99,3,9,102,2,9,9,101,2,9,9,1002,9,5,9,1001,9,2,9,4,9,99,3,9,102,2,9,9,4,9,99,3,9,101,2,9,9,4,9,3,9,102,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,1001,9,2,9,4,9,3,9,1001,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,1001,9,1,9,4,9,99,3,9,1001,9,1,9,4,9,3,9,102,2,9,9,4,9,3,9,1001,9,1,9,4,9,3,9,1001,9,1,9,4,9,3,9,1001,9,1,9,4,9,3,9,1001,9,2,9,4,9,3,9,101,1,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,1,9,9,4,9,3,9,1001,9,2,9,4,9,99,3,9,101,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,1001,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,1001,9,1,9,4,9,3,9,1001,9,1,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,102,2,9,9,4,9,99,3,9,1001,9,1,9,4,9,3,9,102,2,9,9,4,9,3,9,1001,9,1,9,4,9,3,9,1002,9,2,9,4,9,3,9,1001,9,1,9,4,9,3,9,1001,9,1,9,4,9,3,9,1001,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,101,2,9,9,4,9,3,9,101,2,9,9,4,9,99,3,9,1002,9,2,9,4,9,3,9,1001,9,2,9,4,9,3,9,101,2,9,9,4,9,3,9,102,2,9,9,4,9,3,9,1001,9,2,9,4,9,3,9,101,2,9,9,4,9,3,9,1001,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,1,9,9,4,9,99 };
	int array[5][503] = { 0 };
	int i_amplifiers[5] = { 0 };
	int opcode = 0, output = 0, input = 0, amplifier_cunter = 0, last_output_from_E=0;
	int first_op = 0, second_op = 0, third_op = 0;
	int first_parametar = 0, second_parametar = 0, third_parametar = -1;
	int code = 0;
	bool is_phase_input = true, is_first_loop=true;

	for (i = 0; i < 503; i++)
	{
		array[0][i] = values_array[i];
		array[1][i] = values_array[i];
		array[2][i] = values_array[i];
		array[3][i] = values_array[i];
		array[4][i] = values_array[i];
	}
	i = 0;

	while (amplifier_cunter < 5)
	{
		i = i_amplifiers[amplifier_cunter];

		while (i < x)
		{
			code = array[amplifier_cunter][i];
			opcode = code % 100;
			first_op = (code / 100) % 10;
			second_op = (code / 1000) % 10;
			third_op = code / 10000;

			if (opcode == 99)
			{
				i = x;
				amplifier_cunter = 99;
			}
			else
			{
				if (first_op == 0)
					first_parametar = array[amplifier_cunter][array[amplifier_cunter][i + 1]];
				else if (first_op == 1)
					first_parametar = array[amplifier_cunter][i + 1];

				if (second_op == 0 && (opcode != 3 && opcode != 4))
					second_parametar = array[amplifier_cunter][array[amplifier_cunter][i + 2]];
				else if (second_op == 1 && (i + 2) < x)
					second_parametar = array[amplifier_cunter][i + 2];

				/*if (third_op == 0 && (opcode != 7 && opcode != 8))
					third_parametar = array[array[i + 3]];
				else if (third_op == 1 && (i+3) < x)*/
				third_parametar = array[amplifier_cunter][i + 3];


				if (opcode == 1)
					array[amplifier_cunter][array[amplifier_cunter][i + 3]] = first_parametar + second_parametar;
				else if (opcode == 2)
					array[amplifier_cunter][array[amplifier_cunter][i + 3]] = first_parametar * second_parametar;
				else if (opcode == 3)
				{
					if (amplifier_cunter == 0 && is_phase_input == true && is_first_loop == true)
					{
						array[amplifier_cunter][array[amplifier_cunter][i + 1]] = y;
						is_phase_input = false;
					}
					else if (amplifier_cunter == 0 && is_phase_input == false && is_first_loop==true)
						array[amplifier_cunter][array[amplifier_cunter][i + 1]] = 0;
					else if (amplifier_cunter == 1 && is_phase_input == true && is_first_loop == true)
					{
						array[amplifier_cunter][array[amplifier_cunter][i + 1]] = j;
						is_phase_input = false;
					}
					else if (amplifier_cunter == 2 && is_phase_input == true && is_first_loop == true)
					{
						array[amplifier_cunter][array[amplifier_cunter][i + 1]] = k;
						is_phase_input = false;
					}
					else if (amplifier_cunter == 3 && is_phase_input == true && is_first_loop == true)
					{
						array[amplifier_cunter][array[amplifier_cunter][i + 1]] = l;
						is_phase_input = false;
					}
					else if (amplifier_cunter == 4 && is_phase_input == true && is_first_loop == true)
					{
						array[amplifier_cunter][array[amplifier_cunter][i + 1]] = m;
						is_phase_input = false;
					}
					else if (is_phase_input == false)
						array[amplifier_cunter][array[amplifier_cunter][i + 1]] = input;
				}
				else if (opcode == 4)
				{
					//printf("%d\n", first_parametar);
					i_amplifiers[amplifier_cunter] = i+2;
					i = x;
					output = first_parametar;
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
						array[amplifier_cunter][third_parametar] = 1;
					else
						array[amplifier_cunter][third_parametar] = 0;
				}
				else if (opcode == 8)
				{
					if (first_parametar == second_parametar)
						array[amplifier_cunter][third_parametar] = 1;
					else
						array[amplifier_cunter][third_parametar] = 0;
				}

				if (opcode == 1 || opcode == 2 || opcode == 7 || opcode == 8)
					i += 4;
				else if (opcode == 3 || opcode == 4)
					i += 2;


				first_op = 0;
				second_op = 0;
				third_op = -1;
			}
		}
		input = output;

		if (amplifier_cunter == 4)
		{
			amplifier_cunter = 0;
			last_output_from_E = output;
			is_first_loop = false;
		}
		else
			amplifier_cunter++;

		if (is_first_loop == true)
			is_phase_input = true;
	}

	return last_output_from_E;
}

bool check_phase_modes(int i, int j, int k, int l, int m)
{
	if (m != l && m != k && m != j && m != i)
	{
		if (l != k && l != j && l != i)
		{
			if (k != j && k != i)
			{
				if (j != i)
				{
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		else return false;
	}
	else
		return false;
}