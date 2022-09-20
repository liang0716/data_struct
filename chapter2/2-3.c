#include <stdlib.h>
#include <stdio.h>


void sparse_mtx(int arr[][6], int list[][4]);
int main(int argc, char *argv[])
{
    int i, j;
    int a[6][6] = {
        { 0, 15,  0,  0, -8,  0},
        { 0,  0,  6,  0,  0,  0},
        { 0,  0,  0, -6,  0,  0},
        { 0,  0, 18,  0,  0,  0},
        { 0,  0,  0,  0,  0, 16},
        {72,  0,  0,  0, 20,  0}
    };

    int sm[7][4] = {0};
    sparse_mtx(a, sm);


    printf("index   x   y   val\n");
    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf(" %02d ", sm[i][j]);
        }
        printf("\n");
    }
    return 0;
}


void sparse_mtx(int arr[6][6], int list[8][4])
{
    int i, j;
    int cnt = 0;
    for(i = 0; i < 6; i++)
    {
        for(j = 0; j < 6; j++)
        {
            if(arr[i][j] != 0)
            {
                list[cnt][0] = cnt;
                list[cnt][1] = i;
                list[cnt][2] = j;
                list[cnt][3] = arr[i][j];
                cnt++;
            }

            /*
            if(*(*(arr + i) + j) != 0)
            {
                *(*(list + cnt) + 0) = cnt;
                *(*(list + cnt) + 1) = i;
                *(*(list + cnt) + 2) = j;
                *(*(list + cnt) + 3) = *(*(arr + i) + j);
                cnt++;
            }
            */
        }
    }
    //return list;
}
