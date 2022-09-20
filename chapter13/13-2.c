#include <stdlib.h>
#include <stdio.h>



////¿ï¾Ü±Æ§Ç
void select(int a[], int idx)
{
    int i, j, k, tmp, min, cnt = 0;
    printf("\n");

    for(i = 0; i < idx-1; i++)
    {
        printf("i = %d\n", i);
        tmp = a[i];
        min = i;

        for(j = i + 1; j < idx; j++)
        {
            cnt++;
            if(tmp > a[j])
            {
                tmp = a[j];
                min = j;
            }
        }
        a[min] = a[i];
        a[i] = tmp;

        for(k= 0; k < idx; k++)
        {
            printf("        %d", a[k]);
        }
            printf("\n");
    }

    printf("cnt = %d\n", cnt);
}



int main()
{
    int i;
    int a[10] = {5,2,3,6,0,4,7,8,1,9};
    int idx = sizeof(a)/sizeof(int);

    printf("Before: ");
    for(i= 0; i < idx; i++)
    {
        printf("%d ", a[i]);
    }

    select(a, idx);

    printf("After: ");
    for(i= 0; i < idx; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
    return 0;
}
