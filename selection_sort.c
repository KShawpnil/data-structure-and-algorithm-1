//n-hour challenge - Problem No.3

#include <stdio.h>
#include <stdlib.h>

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSortAscending(int Arr[], int n)
{
	int i, j, min_index;

	for (i = 0; i < n - 1; i++)
	{
		min_index = i;

		for (j = i + 1; j < n; j++)

		if (Arr[j] < Arr[min_index])

			min_index = j;

		swap(&Arr[min_index], &Arr[i]);
	}
}

void selectionSortDescending(int Arr[], int n)
{
	int i, j, min_index;

	for (i = 0; i < n - 1; i++)
	{
		min_index = i;

		for (j = i+1; j < n; j++)

		if (Arr[j] > Arr[min_index])

			min_index = j;

		swap(&Arr[min_index], &Arr[i]);
	}
}

void printArray(int Arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
	printf("%d ", Arr[i]);
	printf("\n");
}

int main()
{
    int Arr[20];
    int n = sizeof(Arr) / sizeof(Arr[0]);
    for(int i = 0; i < 20; i++)   //random array input
      {
          Arr[i] = rand()%500;
      }

    printf("Unsorted Array: \n");
    printArray(Arr, n);

	printf("\n");

	selectionSortAscending(Arr, n);
	printf("Sorted Ascending order Array: \n");
	printArray(Arr, n);

    printf("\n");

    selectionSortDescending(Arr, n);
	printf("Sorted Descending Array: \n");
	printArray(Arr, n);

	return 0;
}
