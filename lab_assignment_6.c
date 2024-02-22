#include <stdio.h>
#include <stdlib.h>

int search(int numbers[], int low, int high, int value) 
{
	int mid = (low + high) / 2; //Mid is the midpoint of the low and high values

	if (low >= high) //If low is ever the same as or higher than higher
	{
		return -1;
	}

	if (value == numbers[mid]) //If the value is at the mid id, return it
	{
		return mid;
	}
	else if (value > numbers[mid]) //If the value is higher than mid, make low the current mid
	{
		mid = search(numbers, mid+1, high, value); //Store the mid from the call
	}
	else if (value < numbers[mid]) //If the value is lower than mid, make high the current mid
	{
		mid = search(numbers, low, mid-1, value); //Store the mid from the call
	}
	return mid; //Mid will be -1 if all searches return -1, otherwise it will return the index it found
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}