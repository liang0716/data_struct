//2-6魔術矩陣(該位置的十字路縣所有元素相加會跟其他位置相同)
#include <stdlib.h>
#include <stdio.h>


int main()
{
    int g[5][5] = {0};
    int i = 0, j = 2, cnt = 2;
    int p, q;
    g[0][2] = 1;
    while(cnt <= 25)
    {
        p = (i-1);
        q = (j-1);

        if(p < 0)
        {
            p = 5-1;
        }

        if(q < 0)
        {
            q = 5-1;
        }

        if(g[p][q] != 0)
        {
            i = (i + 1);
        }
        else
        {
            i = p;
            j = q;
        }
        g[i][j] = cnt;
        cnt++;
    }


    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            printf("%02d ", g[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    return 0;
}
