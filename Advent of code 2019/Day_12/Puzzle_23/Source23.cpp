#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS


int main()
{	
	int time = 0, pot = 0, kin = 0, total = 0;
	int satelite_velocity[4][3] = { 0 };
	int satelite[4][3] = { {-9,  10,	-1	},
							{-14, -8,	14	},
							{1,	   5,	6	},
							{-19,  7,   8   } };
	

	while (time < 1000)
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
	}

	for (int i = 0; i < 4; i++)
	{
		pot = abs(satelite[i][0]) + abs(satelite[i][1]) + abs(satelite[i][2]);
		kin = abs(satelite_velocity[i][0]) + abs(satelite_velocity[i][1]) + abs(satelite_velocity[i][2]);
		total += pot * kin;
	}

	printf("%d", total);

	return 0;
}

