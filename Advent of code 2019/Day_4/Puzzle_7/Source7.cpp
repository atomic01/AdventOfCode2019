#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS

bool meets_criteria(unsigned int);


int main()
{
	//171309 - 643603;
	int n = 0;//number of passwords
	for (unsigned int i = 171309; i <= 643603; i++)
		if (meets_criteria(i)==true)
			n++;

	printf("%d", n);
		
	return 0;
}

bool meets_criteria(unsigned int x)
{
	int x_digits[6] = { 0 };
	int i = 5;
	bool return_value = false;
	while (x)
	{
		x_digits[i] = x%10;
		x /= 10;
		i--;
	}
	
	
	if ((x_digits[0] == x_digits[1]) || (x_digits[1] == x_digits[2]) || (x_digits[2] == x_digits[3]) || (x_digits[3] == x_digits[4]) || (x_digits[4] == x_digits[5]))
		return_value = true;
	else
		return false;

	if ((x_digits[0] <= x_digits[1]) && (x_digits[1] <= x_digits[2]) && (x_digits[2] <= x_digits[3]) && (x_digits[3] <= x_digits[4]) && (x_digits[4] <= x_digits[5]))
		return_value = true;
	else
		return false;

	return return_value;	
}

