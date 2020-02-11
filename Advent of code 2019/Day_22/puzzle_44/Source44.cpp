#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define SIZE_OF_DECK 119315717514047	
#define NUMBER_OF_ITERATIONS 101741582076661
#define CARD_POSITION 2020

struct lcs;
typedef struct lcs* tuple;
typedef struct lcs {
	long long int a;
	long long int b;
};

long long int getNumber(char*);
tuple simplifyInstructions();
tuple createTuple();
long long int exponentiationBySquaring(long long int, long long int, long long int);


int main()
{
	//DOES NOT WORK
	tuple shuffleLCF = simplifyInstructions();
	tuple finalLCF = createTuple();
	long long int A = 0, B = 0, x = 0, fToTheNegativeKOfX = 0;
	long long int AToTheK = exponentiationBySquaring(shuffleLCF->a, NUMBER_OF_ITERATIONS, SIZE_OF_DECK);

	finalLCF->a = AToTheK % SIZE_OF_DECK;
	finalLCF->b = (((shuffleLCF->b * (1 - AToTheK)) % SIZE_OF_DECK) * (exponentiationBySquaring(1 - shuffleLCF->a, SIZE_OF_DECK - 2, SIZE_OF_DECK)% SIZE_OF_DECK)) % SIZE_OF_DECK;
	A = finalLCF->a;
	B = finalLCF->b;
	x = CARD_POSITION;
	fToTheNegativeKOfX = (((x -B) % SIZE_OF_DECK) * (exponentiationBySquaring(A, SIZE_OF_DECK - 2, SIZE_OF_DECK)) % SIZE_OF_DECK) % SIZE_OF_DECK;

	printf("%llu", fToTheNegativeKOfX);

	/*int result = 0;
	result = ((2019 * shuffleLCF->a) + shuffleLCF->b) % SIZE_OF_DECK;
	if (result < 0)
		result += SIZE_OF_DECK;

	printf("%d", result);*/

	return 0;
}

tuple createTuple()
{
	tuple p = (tuple )malloc(sizeof(struct lcs));
	if (p != NULL)
	{
		p->a = 0;
		p->b = 0;
		return p;
	}
}

tuple simplifyInstructions()
{
	long long int N = 0;
	char buffer[50] = { '\0' };
	FILE* fp = fopen("Input.txt", "r+");
	tuple LCF = createTuple();
	tuple finalLCF = createTuple();
	bool firstIteration = true;
	finalLCF->a = 1;
	finalLCF->b = 1;

	while (!feof(fp))
	{
		fscanf(fp, "%[^\n]%*c", &buffer);
		N = 0;

		if (strstr(buffer, "deal into new stack") != 0)
		{
			LCF->a = -1;
			LCF->b = -1;
		}
		else if (strstr(buffer, "cut") != 0)
		{
			LCF->a = 1;
			LCF->b = -getNumber(buffer);
		}
		else if (strstr(buffer, "deal with increment") != 0)
		{
			LCF->a = getNumber(buffer);
			LCF->b = 0;
		}

		if (firstIteration == true)
		{
			finalLCF->a = LCF->a;
			finalLCF->b = LCF->b;
			firstIteration = false;
		}
		else
		{
			finalLCF->a = (finalLCF->a * LCF->a) % SIZE_OF_DECK;
			finalLCF->b = (finalLCF->b * LCF->a + LCF->b) % SIZE_OF_DECK;
		}
	}

	return finalLCF;
}

long long int getNumber(char* buffer)
{
	long long int i = 0, value = 0;
	bool negativeNumber = false;

	if (strstr(buffer, "cut") != 0)
		i = 4;
	else if (strstr(buffer, "deal with increment") != 0)
		i = 20;

	while (buffer[i] != '\0')
	{
		switch (buffer[i])
		{
			case '-':negativeNumber = true; break;
			case '0':value = value * 10 + 0; break;
			case '1':value = value * 10 + 1; break;
			case '2':value = value * 10 + 2; break;
			case '3':value = value * 10 + 3; break;
			case '4':value = value * 10 + 4; break;
			case '5':value = value * 10 + 5; break;
			case '6':value = value * 10 + 6; break;
			case '7':value = value * 10 + 7; break;
			case '8':value = value * 10 + 8; break;
			case '9':value = value * 10 + 9; break;
		}
		i++;
	}

	if (negativeNumber == true)
		value = -value;

	return value;	
}

long long int exponentiationBySquaring(long long int x, long long int n, long long int m)
{
	if (n == 0)
		return 1;
	else if (n == 1)
		return x;
	else if (n % 2 == 0)
		return exponentiationBySquaring((x * x) % m, n / 2, m);
	else
		return (x * exponentiationBySquaring((x * x) % m, (n-1)/2,m)) % m;
}
