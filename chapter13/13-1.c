#include <stdlib.h>
#include <stdio.h>



//®ðªw±Æ§Ç
void bubble(int a[], int idx)
{
    int i, j, k, tmp, cnt = 0, flag;
    printf("\n");
    for(i = 0; i < idx; i++)
    {
        flag = 0;
        printf("i = %d\n", i);
        for(j = 0; j < idx - i - 1; j++)
        {
            cnt++;
            printf("    j = %d\n", j);
            if(a[j] > a[j+1])
            {
                tmp = a[j+1];
                a[j+1] = a[j];
                a[j] = tmp;
                flag = 1;
            }

            for(k= 0; k < idx; k++)
            {
                printf("        %d", a[k]);
            }
            printf("\n");
        }
        if(flag == 0)
        {
            break;
        }
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

    bubble(a, idx);

    printf("After: ");
    for(i= 0; i < idx; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
    return 0;
}
