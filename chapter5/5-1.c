#include <stdlib.h>
#include <stdio.h>

/*
int gcd(int a, int b)//res
{
    if(a>b)
    {
        if(a%b == 0)
        {
            return b;
        }
        return gcd(b, a%b);
    }
    else
    {
        if(b%a == 0)
        {
            return a;
        }
        return gcd(a, b%a);
    }
}
*/
int gcd(int a, int b)//not res
{
    int tmp;
    if(a > b)
    {
        while(a%b != 0)
        {
            tmp = b;
            b = a%b;
            a = tmp;
        }
        return b;
    }
    else
    {
        while(b%a != 0)
        {
            tmp = a;
            a = b%a;
            b = tmp;
        }
        return a;
    }
}

int main()
{
    printf("%d \n", gcd(128,17));

    return 0;
}
