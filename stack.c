#include <stdio.h>
#include <stdlib.h>

#define max 5
int top = -1;

void push_stack(int *ar, int data)
{
    printf("\n~~~Push Stack~~~\n\n");
    if(top >= max-1)
    {
        printf("Stack is full!\n\n");
    }
    else
    {
        top++;
        *(ar + top) = data;
    }
}

void pop_stack(int *ar)
{
    printf("\n~~~Pop Stack~~~\n\n");
    if(top < 0)
    {
        printf("Stack is empty!\n\n");
    }
    else
    {
        printf("data is %d\n\n", *(ar + top));
        top--;
    }
}

void list_stack(int *ar)
{
    printf("\n~~~List Stack~~~\n\n");
    int i;
    if(top < 0)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        for(i = 0; i <= top; i++)
        {
            printf("num: %d, data:%d\n\n", i, *(ar + i));
        }
    }
}


int main(int argc, char *aggv[])
{
    int stack[max];

    list_stack(stack);
    printf("\n");

    push_stack(stack, 6);
    printf("\n");


    push_stack(stack, 0);
    printf("\n");


    list_stack(stack);
    printf("\n");

    pop_stack(stack);
    printf("\n");

    list_stack(stack);
    printf("\n");

    push_stack(stack, 9);
    printf("\n");

    push_stack(stack, 780);
    printf("\n");

    push_stack(stack, 55);
    printf("\n");

    push_stack(stack, 10);
    printf("\n");

    push_stack(stack, -30);
    printf("\n");

    list_stack(stack);
    printf("\n");

    pop_stack(stack);
    printf("\n");

    pop_stack(stack);
    printf("\n");

    pop_stack(stack);
    printf("\n");

    pop_stack(stack);
    printf("\n");

    pop_stack(stack);
    printf("\n");

    pop_stack(stack);
    printf("\n");

    list_stack(stack);
    printf("\n");

    printf("\n");
    return 0;
}
