#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS

unsigned long long int lcm(unsigned long long int, unsigned long long int);
unsigned long long int gcd(unsigned long long int, unsigned long long int);

int main()
{
	bool is_done[4] = { false };
	unsigned long long int time = 0, pot = 0, kin = 0, total = 0, number_of_iterations = 0;
	int satelite_velocity[4][3] = { 0 };
	unsigned long long int axis_orbit[3] = { 0 };
	int satelite[4][3] = { {-9,  10,	-1	},
							{-14, -8,	14	},
							{1,	   5,	6	},
							{-19,  7,   8   } };
	int initialPos[4][3] = { {-9,  10,	-1	},
							{-14, -8,	14	},
							{1,	   5,	6	},
							{-19,  7,   8   } };

	while (is_done[3] != true)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int k = 0; k < 3; k++)
			{
				for (int j = i; j < 4; j++)
				{
					if (satelite[i][k] < satelite[j][k])
					{
						satelite_velocity[i][k]++;
						satelite_velocity[j][k]--;
					}
					else if (satelite[i][k] > satelite[j][k])
					{
						satelite_velocity[i][k]--;
						satelite_velocity[j][k]++;
					}
				}
			}
		}

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 3; j++)
				satelite[i][j] += satelite_velocity[i][j];

		time++;

		if (satelite[0][0] == initialPos[0][0] && satelite[1][0] == initialPos[1][0] && satelite[2][0] == initialPos[2][0] && satelite[3][0] == initialPos[3][0] &&
			satelite_velocity[0][0] == 0 && satelite_velocity[1][0] == 0 && satelite_velocity[2][0] == 0 && satelite_velocity[3][0] == 0 && is_done[0] == false)
		{
			axis_orbit[0] = time;
			is_done[0] = true;
		}
		if (satelite[0][1] == initialPos[0][1] && satelite[1][1] == initialPos[1][1] && satelite[2][1] == initialPos[2][1] && satelite[3][1] == initialPos[3][1] &&
			satelite_velocity[0][1] == 0 && satelite_velocity[1][1] == 0 && satelite_velocity[2][1] == 0 && satelite_velocity[3][1] == 0 && is_done[1] == false)
		{
			axis_orbit[1] = time;
			is_done[1] = true;
		}
		if (satelite[0][2] == initialPos[0][2] && satelite[1][2] == initialPos[1][2] && satelite[2][2] == initialPos[2][2] && satelite[3][2] == initialPos[3][2] &&
			satelite_velocity[0][2] == 0 && satelite_velocity[1][2] == 0 && satelite_velocity[2][2] == 0 && satelite_velocity[3][2] == 0 && is_done[2] == false)
		{
			axis_orbit[2] = time;
			is_done[2] = true;
		}

		if (is_done[0] == true && is_done[1] == true && is_done[2] == true)
			is_done[3] = true;
	}

	number_of_iterations = lcm(axis_orbit[0], axis_orbit[1]);
	number_of_iterations = lcm(number_of_iterations, axis_orbit[2]);

	printf("%llu", number_of_iterations);

	return 0;
}

unsigned long long int lcm(unsigned long long int x, unsigned long long int y)
{
	int d = gcd(x, y);
	unsigned long long int result = (x / d) * y;
	return result;
}

unsigned long long int gcd(unsigned long long x, unsigned long long y)
{
	int i = 0;
	while (y)
	{
		i = y;
		y = x % y;
		x = i;
	}

	return x;
}