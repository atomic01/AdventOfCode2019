#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define SIZE_OF_DECK 10007
#define CARD_NUMBER 2019

void createNewDeck(int *);
void dealIntoNewStack(int*);
void cutDeck(int*, int);
void dealWithIncrement(int*, int);
void printDeck(int*);
int getNumber(char*);
void findCardInDeck(int*, int);

int main()
{
	int i = 0, deck[SIZE_OF_DECK] = { 0 }, value = 0;
	char buffer[50] = { '\0' };
	FILE* fp = fopen("Input.txt", "r+");
	int* deckPointer = deck;

	createNewDeck(deckPointer);

	while (!feof(fp))
	{
		fscanf(fp, "%[^\n]%*c", &buffer);
		//printf("%s\n", buffer);

		value = 0;

		if (strstr(buffer, "deal into new stack") != 0)
			dealIntoNewStack(deckPointer);
		else if (strstr(buffer, "cut") != 0)
		{
			value = getNumber(buffer);
			cutDeck(deckPointer, value);
		}
		else if (strstr(buffer, "deal with increment") != 0)
		{
			value = getNumber(buffer);
			dealWithIncrement(deckPointer, value);
		}
	}

	findCardInDeck(deckPointer, CARD_NUMBER);

	return 0;
}

void createNewDeck(int* p)
{
	for (int i = 0; i < SIZE_OF_DECK; i++)
		p[i] = i;
}

void dealIntoNewStack(int* p)
{
	int newStack[SIZE_OF_DECK] = { 0 };

	for (int i = 0; i < SIZE_OF_DECK; i++)
		newStack[SIZE_OF_DECK - 1 - i] = p[i];

	for (int i = 0; i < SIZE_OF_DECK; i++)
		p[i] = newStack[i];	
}

void cutDeck(int* p, int N)
{
	int newStack[SIZE_OF_DECK] = { 0 };

	if (N > 0)
	{
		for (int i = 0; i < N; i++)
			newStack[SIZE_OF_DECK - N + i] = p[i];

		for (int i = N; i < SIZE_OF_DECK; i++)
			newStack[i - N] = p[i];

		for (int i = 0; i < SIZE_OF_DECK; i++)
			p[i] = newStack[i];
	}
	else if(N < 0)
	{
		N = abs(N);
		for (int i = 0; i < N; i++)
			newStack[i] = p[SIZE_OF_DECK - N +i];

		for (int i = N; i < SIZE_OF_DECK; i++)
			newStack[i ] = p[i-N];

		for (int i = 0; i < SIZE_OF_DECK; i++)
			p[i] = newStack[i];
	}	
}

void dealWithIncrement(int* p, int N)
{
	int newStack[SIZE_OF_DECK] = { 0 };
	int counter = -N;

	for (int i = 0; i < (SIZE_OF_DECK); i++)
	{
		counter +=N;
		if (counter > (SIZE_OF_DECK)-1)
			counter -= SIZE_OF_DECK;

		newStack[counter] = p[i];
	}

	for (int i = 0; i < SIZE_OF_DECK; i++)
		p[i] = newStack[i];
}

void printDeck(int* p)
{
	for (int i = 0; i < SIZE_OF_DECK; i++)
		printf("%d", p[i]);

	printf("\n");
}

int getNumber(char* buffer)
{
	int i = 0, value = 0;
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

void findCardInDeck(int* p, int cardNumber)
{
	for (int i = 0; i < SIZE_OF_DECK; i++)
	{
		if (p[i] == cardNumber)
		{
			printf("%d", i);
			i = SIZE_OF_DECK;
		}
	}
}