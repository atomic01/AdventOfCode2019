#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS

struct list;
typedef struct list* Pos;
typedef struct list {
	unsigned int amount;
	char name[10];
	Pos next;
};

unsigned int findChemical(unsigned int, char[10], Pos);
Pos createNode();
unsigned int getOreFromSpareChemicals(char[10], Pos);
void pushSpareChemicals(char[10], unsigned int, Pos);

int main()
{
	unsigned int numberOfOre = 0;
	unsigned int numberOfOreLeft = 0;
	char fuel[10] = "FUEL";
	Pos spareChemicals = createNode();

	numberOfOre = findChemical(1, fuel, spareChemicals);

	printf("%d", numberOfOre);

	return 0;
}

unsigned int findChemical(unsigned int quantityRequiered, char chemicalName[10], Pos spareChemicals)
{
	char buffer = '\0', prevBuffer = '\0';
	char reaction[80] = { 0 }, number[3] = { '\0' }, productNumber[3] = { '\0' }, chemical[10] = { '\0' };
	unsigned int  numberOfOre = 0, i = 0, j = 0, k = 0, amountOfChemical = 0, spareProduct = 0, totalNumberOfChemicalsCounter = 1, numberOfDoneChemicals = 0, amount = 0;
	bool isTheChemicalFound = false;
	FILE* fp = fopen("ListOfReactions.txt", "r+");

	while (isTheChemicalFound != true)
	{
		buffer = '0';
		i = 0;
		memset(reaction, '\0', 80 * sizeof(char));

		while (buffer != '\n' && fscanf(fp, "%c", &buffer) == 1)
		{
			if (buffer != '#')
				reaction[i] = buffer;
			else
			{
				if(fscanf(fp, "%c", &buffer)==1)
					buffer = '\n';
			}

			i++;
		}

		if (strstr(reaction, chemicalName) != NULL && strstr(&reaction[i - 7], chemicalName) != NULL)
			isTheChemicalFound = true;
	}

	i = 0;
	while (reaction[i] != '\0')
	{
		if (reaction[i] == ',')
			totalNumberOfChemicalsCounter++;
		i++;
	}

	i = 0;
	while (reaction[i] != '\n' && reaction[i] != '>')
	{
		memset(number, '\0', 3 * sizeof(char));
		memset(chemical, '\0', 10 * sizeof(char));
		j = 0;

		while (reaction[i] != ' ' && isdigit(reaction[i]) != NULL) //get the number before the chemical
		{
			number[j] = reaction[i];
			i++;
			j++;
		}

		amountOfChemical = atoi(number);

		i++;
		j = 0;

		while (isdigit(reaction[i]) == NULL && reaction[i] != ' ' && reaction[i] != ',') //get the the requiered chemical name
		{
			chemical[j] = reaction[i];
			i++;
			j++;
		}
		i += 2;

		k = 0;
		while (reaction[k] != '>')
			k++;
		j = 0;
		k += 2;
		while (reaction[k] != ' ') //get the number before the chemical
		{
			productNumber[j] = reaction[k];
			k++;
			j++;
		}

		if (strcmp(chemical, "ORE") != NULL)
		{
			spareProduct = getOreFromSpareChemicals(chemicalName, spareChemicals);
			if (spareProduct >= quantityRequiered)
			{
				pushSpareChemicals(chemicalName, spareProduct - quantityRequiered, spareChemicals);
				reaction[i] = '\n';
			}
			else
			{
				numberOfOre += findChemical(amountOfChemical * ceil(float(quantityRequiered - spareProduct) / float(atoi(productNumber))), chemical, spareChemicals);
				numberOfDoneChemicals++;
				if (numberOfDoneChemicals == totalNumberOfChemicalsCounter)
				{
					amount = atoi(productNumber) + spareProduct;
					while (amount < quantityRequiered)
						amount += atoi(productNumber);
					pushSpareChemicals(chemicalName, amount - quantityRequiered, spareChemicals);
				}
			}
		}
		else
		{
			spareProduct = getOreFromSpareChemicals(chemicalName, spareChemicals);
			if (spareProduct >= quantityRequiered)
			{
				numberOfOre = 0;
				pushSpareChemicals(chemicalName, spareProduct - quantityRequiered, spareChemicals);
			}
			else
			{
				k = i + 2;
				j = 0;
				while (reaction[k] != ' ') //get the number before the chemical
				{
					productNumber[j] = reaction[k];
					k++;
					j++;
				}
				while (spareProduct < quantityRequiered)
				{
					spareProduct += atoi(productNumber);
					numberOfOre += amountOfChemical;
				}
				pushSpareChemicals(chemicalName, spareProduct - quantityRequiered, spareChemicals);
			}
		}
	}

	return numberOfOre;
}

Pos createNode()
{
	Pos q = (Pos)malloc(sizeof(struct list));
	if (q != NULL)
	{
		q->amount = 0;
		memset(q->name, '\0', 10 * sizeof(char));
		q->next = NULL;
	}

	return q;
}

unsigned int getOreFromSpareChemicals(char chemicalName[10], Pos spareChemicals)
{
	Pos p = spareChemicals->next;
	unsigned int amount = 0;
	while (p != NULL)
	{
		if (strcmp(chemicalName, p->name) == NULL)
		{
			amount = p->amount;
			p = NULL;
		}
		else
			p = p->next;
	}

	return amount;
}

void pushSpareChemicals(char chemicalName[10], unsigned int leftOverAmount, Pos spareChemicals)
{
	Pos p = spareChemicals->next;
	bool jobDone = false;

	while (p != NULL)
	{
		if (strcmp(chemicalName, p->name) == NULL)
		{
			p->amount = leftOverAmount;
			p = NULL;
			jobDone = true;
		}
		else
			p = p->next;
	}

	if (jobDone == false)
	{
		Pos q = createNode();
		q->amount = leftOverAmount;
		strcpy(q->name, chemicalName);
		q->next = spareChemicals->next;
		spareChemicals->next = q;
	}
}
