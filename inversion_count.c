#include <stdio.h>
#include <stdlib.h>

int inversionCount(int Arr[], int n)
{
    int i, j;
    int inversion_count = 0;       //the counting will begin 0

    for(i = 0; i < n-1; i++){
        for(j = i + 1; j < n; j++)
        {
            if(Arr[i] > Arr[j])
            {
                inversion_count++;
            }
        }
    }
    return inversion_count;
}

void printArray(int Arr[], int size)
{
	for (int k = 0; k < size; k++)
    printf("%d ", Arr[k]);
	printf("\n");
}

int main()
{
    //int Arr[] = {1,9,6,4,5};     //according to the given example,the inversion count of Arr is 5

    int Arr[20];
    int n = sizeof(Arr) / sizeof(Arr[0]);
    for(int i = 0; i < 20; i++)   //random array input
      {
          Arr[i] = rand()%500;
      }

    printf("Unsorted Array: \n");
    printArray(Arr, n);

    printf("The inversion count of Arr is %d \n", inversionCount(Arr, n));//we have to call the function in printstatement
    //inversionCount(Arr, n);

    return 0;
}
