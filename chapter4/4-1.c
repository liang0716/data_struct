#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;

}NODE;

void createList(NODE **, int);
void freeList(NODE **);
void kill_last(NODE **);
void printfList(NODE *);

int main(int argc, char *argv[])
{
    int i, num, data;
    NODE *head = NULL;

    printf("Please key in list length: ");
    scanf("%d", &num);

    for(i = 0; i < num; i++)
    {
        printf("%d's data: ", i+1);
        scanf("%d", &data);
        createList(&head, data);
    }

    printfList(head);

    kill_last(&head);
    printfList(head);

    freeList(&head);

    printfList(head);
    return 0;
}

void createList(NODE **head, int data)
{
    NODE *cur, *newnode;

    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->data = data;
    newnode->next = NULL;


    if((*head) != NULL)
    {
        cur = *head;
        while(cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = newnode;
    }
    else
    {
        *head = newnode;
    }
}

void freeList(NODE **head)
{   printf("freeList\n");
    NODE *cur, *temp;

    cur = *head;
    while(cur->next != NULL)
    {
        temp = cur;
        cur = cur->next;
        free(temp);
    }
    free(cur);
    *head = NULL;
}


void printfList(NODE *head)
{
    printf("printfList\n");
    NODE *cur;
    cur = head;
    if(head != NULL)
    {
        while(cur->next != NULL)
        {
            printf("address: %X, data: %d, next: %X\n", cur, cur->data, cur->next);
            cur = cur->next;
        }
        printf("address: %X, data: %d, next: %X\n", cur, cur->data, cur->next);
    }
    else
    {
        printf("It's empty.\n");
    }

}


void kill_last(NODE **head)
{
    printf("killLast\n");
    NODE *cur, *temp;
    cur = *head;

    while(cur->next->next != NULL)
    {
        cur = cur->next;
    }

    temp = cur->next;
    cur->next = NULL;
    free(temp);
}
