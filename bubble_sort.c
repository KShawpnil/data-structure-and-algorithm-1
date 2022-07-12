#include <stdio.h>
#include <stdlib.h>

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int Arr[], int n)
{
    int i, j, k;
    int is_swap=1;

    while(is_swap){
        is_swap =0;
        for(j = 0; j < n; j++){         //changed the condition into j < n, so the loop will run up to n times

            if(Arr[j] < Arr[j+1])      //changed the checking condition into Arr[j] < Arr[j+1], so that it compares in descending order
            {
                is_swap=1;
                swap(&Arr[j], &Arr[j+1]);
            }
        }
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

	printf("UnSorted array: \n");
	printArray(Arr, n);
	printf("\n");

	bubbleSort(Arr, n);

	printf("Sorted array: \n");
	printArray(Arr, n);

    return 0;
}
