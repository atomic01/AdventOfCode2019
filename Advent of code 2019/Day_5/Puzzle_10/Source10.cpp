#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define _CRT_SECURE_NO_WARNINGS


int main()
{
	int i = 0, x = 678;//x is size of array
	int array[678] = { 3,225,1,225,6,6,1100,1,238,225,104,0,1002,36,25,224,1001,224,-2100,224,4,224,1002,223,8,223,101,1,224,224,1,223,224,223,1102,31,84,225,1102,29,77,225,1,176,188,224,101,-42,224,224,4,224,102,8,223,223,101,3,224,224,1,223,224,223,2,196,183,224,1001,224,-990,224,4,224,1002,223,8,223,101,7,224,224,1,224,223,223,102,14,40,224,101,-1078,224,224,4,224,1002,223,8,223,1001,224,2,224,1,224,223,223,1001,180,64,224,101,-128,224,224,4,224,102,8,223,223,101,3,224,224,1,223,224,223,1102,24,17,224,1001,224,-408,224,4,224,1002,223,8,223,101,2,224,224,1,223,224,223,1101,9,66,224,1001,224,-75,224,4,224,1002,223,8,223,1001,224,6,224,1,223,224,223,1102,18,33,225,1101,57,64,225,1102,45,11,225,1101,45,9,225,1101,11,34,225,1102,59,22,225,101,89,191,224,1001,224,-100,224,4,224,1002,223,8,223,1001,224,1,224,1,223,224,223,4,223,99,0,0,0,677,0,0,0,0,0,0,0,0,0,0,0,1105,0,99999,1105,227,247,1105,1,99999,1005,227,99999,1005,0,256,1105,1,99999,1106,227,99999,1106,0,265,1105,1,99999,1006,0,99999,1006,227,274,1105,1,99999,1105,1,280,1105,1,99999,1,225,225,225,1101,294,0,0,105,1,0,1105,1,99999,1106,0,300,1105,1,99999,1,225,225,225,1101,314,0,0,106,0,0,1105,1,99999,8,226,677,224,1002,223,2,223,1006,224,329,1001,223,1,223,108,226,226,224,1002,223,2,223,1006,224,344,1001,223,1,223,7,677,226,224,102,2,223,223,1005,224,359,101,1,223,223,7,226,677,224,102,2,223,223,1006,224,374,101,1,223,223,1008,677,226,224,1002,223,2,223,1006,224,389,101,1,223,223,8,677,677,224,1002,223,2,223,1005,224,404,101,1,223,223,8,677,226,224,102,2,223,223,1005,224,419,1001,223,1,223,1107,677,226,224,102,2,223,223,1005,224,434,1001,223,1,223,1107,226,677,224,1002,223,2,223,1006,224,449,1001,223,1,223,107,677,226,224,1002,223,2,223,1005,224,464,1001,223,1,223,1008,677,677,224,1002,223,2,223,1006,224,479,1001,223,1,223,1108,677,226,224,1002,223,2,223,1006,224,494,1001,223,1,223,1108,677,677,224,1002,223,2,223,1006,224,509,1001,223,1,223,107,677,677,224,1002,223,2,223,1005,224,524,101,1,223,223,1007,677,226,224,102,2,223,223,1005,224,539,1001,223,1,223,1107,226,226,224,1002,223,2,223,1006,224,554,1001,223,1,223,1008,226,226,224,1002,223,2,223,1006,224,569,101,1,223,223,1108,226,677,224,1002,223,2,223,1006,224,584,101,1,223,223,108,677,677,224,1002,223,2,223,1006,224,599,1001,223,1,223,1007,677,677,224,102,2,223,223,1006,224,614,101,1,223,223,107,226,226,224,102,2,223,223,1006,224,629,101,1,223,223,1007,226,226,224,102,2,223,223,1005,224,644,1001,223,1,223,108,226,677,224,102,2,223,223,1005,224,659,1001,223,1,223,7,677,677,224,102,2,223,223,1006,224,674,1001,223,1,223,4,223,99,226 };
	int opcode = 0;
	int first_op = 0, second_op = 0, third_op = 0;
	int first_parametar = 0, second_parametar = 0, third_parametar = -1;
	int code = 0;

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

			if (opcode != 3 && opcode != 4)
			{
				if (second_op == 0)
					second_parametar = array[array[i + 2]];
				else if (second_op == 1)
					second_parametar = array[i + 2];
			}
			//Parameters that an instruction writes to will never be in immediate mode. meaning ALWAYS position mode

			if (opcode == 1)
				array[array[i + 3]] = first_parametar + second_parametar;
			else if (opcode == 2)
				array[array[i + 3]] = first_parametar * second_parametar;
			else if (opcode == 3)
				scanf("%d", &array[array[i + 1]]);
			else if (opcode == 4)
				printf("%d\n", first_parametar);
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
					array[array[i + 3]] = 1;
				else
					array[array[i + 3]] = 0;
			}
			else if (opcode == 8)
			{
				if (first_parametar == second_parametar)
					array[array[i + 3]] = 1;
				else
					array[array[i + 3]] = 0;
			}


			if (opcode == 1 || opcode == 2 || opcode == 7 || opcode == 8)
				i += 4;
			else if (opcode == 3 || opcode == 4)
				i += 2;

			first_op = 0;
			second_op = 0;
			third_op = 0;

		}
	}

	return 0;
}
