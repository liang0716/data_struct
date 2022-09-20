//
#include <stdio.h>
#include <stdlib.h>
void insertionSort(int[], int);

int main()
{
	//int a[10] = {5,1,4,9,7,3,2,0,6,8};
	int a[8] = {15,8,20,7,66,54,18,26};
	int size = sizeof(a)/sizeof(int);
	int i;

	insertionSort(a, size);


	for(i = 0; i < size; i++)
    {
        printf("%d\n", a[i]);
    }

	printf("\n");
	return 0;
}

void insertionSort(int a[], int size)
{
	int i, j, k, tmp;

	for(i = 1; i <= size; i++)
    {

        tmp = a[i];
        j = i-1;
        while((j >= 0) && (tmp < a[j]))
        {
            printf("j = %d, i = %d, tmp = %d, a[j+1] = %d, a[j] = %d\n", j, i, tmp, a[j+1], a[j]);
           a[j + 1] = a[j];
           j--;
        }
        a[j+1]=tmp;

        printf("\n");
        for(k = 0; k < size; k++)
        {
            printf("%d ", a[k]);
        }
        printf("\n");
    }


}

