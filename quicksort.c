#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quicksort_num(int number[], int first, int last){
	int i, j, pivot, temp;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;

		while (i < j)
		{
			while (number[i] <= number[pivot] && i < last)
				i++;
			while (number[j] > number[pivot])
				j--;
			if (i < j)
			{
				temp = number[i];
				number[i] = number[j];
				number[j] = temp;
			}
		}
		if(i == j)return;
		
		temp = number[pivot];
		number[pivot] = number[j];
		number[j] = temp;
		quicksort_num(number, first, j - 1);
		quicksort_num(number, j + 1, last);
	}
}

void quicksort_string(char number[][101], int first, int last){
	int i, j, pivot;
	char temp[101];

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;

		while (i < j)
		{
			while (strcmp(number[pivot], number[i]) >= 0 && i < last)
				i++;
			while (strcmp(number[j] ,number[pivot]) > 0)
				j--;
			if (i < j)
			{
				strcpy(temp, number[i]);
				strcpy(number[i], number[j]);
				strcpy(number[j], temp);
			}
		}
		if(i == j)return;

		strcpy(temp, number[pivot]);
		strcpy(number[pivot], number[j]);
		strcpy(number[j], temp);
		quicksort_string(number, first, j - 1);
		quicksort_string(number, j + 1, last);
	}
}
