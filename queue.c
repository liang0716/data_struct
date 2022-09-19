//線性queue front只會一直增加，若沒減少會沒辦法再填值
#include <stdlib.h>
#include <stdio.h>

#define max 5


int rear = -1;
int front = 0;

void enqueue(int *ar, int data)
{
    printf("En queue start~~\n");
    if(rear == max-1)
    {
        printf("Queue is full.\n");
    }
    else
    {
        rear++;
        *(ar + rear) = data;
    }
    printf("\n");
}

void dequeue(int *ar)
{
    printf("De queue start~~\n");
    if(front > rear)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("data = %d\n", *(ar + front));
        front++;
    }
    printf("\n");
}


void printqueue(int *ar)
{
    printf("print queue start~~\n");
    int i;

    if(front > rear)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        for(i = front; i <= rear; i++)
        {
            printf("num: %d, data = %d\n", i, *(ar + i));

        }
    }
    printf("\n");
}

int main(int argc, char* argv[])
{
    int queue[max];

    printqueue(queue);
    enqueue(queue, 10);
    printqueue(queue);


    dequeue(queue);
    printqueue(queue);


    enqueue(queue, 5);
    enqueue(queue, 99);
    enqueue(queue, 33);
    enqueue(queue, 8);
    printqueue(queue);

    enqueue(queue, 49);
    printqueue(queue);

    enqueue(queue, 10);
    printqueue(queue);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    printqueue(queue);

    printf("\n");
    system("pause");
    return 0;
}
