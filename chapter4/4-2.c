#include <stdlib.h>
#include <stdio.h>
#define L1 5
#define L2 4
typedef struct node
{
    int data;
    struct node *next;
}NODE;


void createList(NODE **, int);
void freeList(NODE **);
void printList(NODE *);
void mergeList(NODE **, NODE**);

int main(int argc, char *argv[])
{
    int i, j;
    NODE *head_1 = NULL, *head_2 = NULL;

    for(i = 0; i < L1; i++)
    {
        createList(&head_1, i);
    }

    for(j = 0; j < L2; j++)
    {
        createList(&head_2, 9 - j);
    }

    printList(head_1);
    printf("\n");

    printList(head_2);
    printf("\n");

    mergeList(&head_1, &head_2);
    printf("\n");

    printList(head_1);
    printf("\n");

    freeList(&head_1);
    //freeList(&head_2);

    return 0;
}

void createList(NODE **head, int data)
{
    NODE *cur, *newnode;
    newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = data;
    newnode->next = newnode;

    if(*head != NULL)
    {
       cur = *head;
       while(cur->next != *head)
       {
           cur = cur->next;
       }
       cur->next = newnode;
       newnode->next = *head;
    }
    else
    {
        *head = newnode;
    }
}


void freeList(NODE **head)
{
    NODE *cur, *tmp;
    cur = *head;
    if(*head != NULL)
    {
        while(cur->next != *head)
        {
            tmp = cur;
            cur = cur->next;
            free(tmp);
        }
        free(cur);
        *head = NULL;
    }
    else
    {
        printf("\n It's empty.\n");
    }

}
void printList(NODE *head)
{
    NODE *cur;
    cur = head;

    if(head != NULL)
    {
        while(cur->next != head)
        {
            printf("address: %X, data: %d, next:%X\n", cur, cur->data, cur->next);
            cur = cur->next;
        }
        printf("address: %X, data: %d, next:%X\n", cur, cur->data, cur->next);
    }
    else
    {
        printf("\n It's empty.\n");
    }


}

void mergeList(NODE **head_1, NODE **head_2)
{
    NODE *cur_1, *cur_2;
    cur_1 = *head_1;
    cur_2 = *head_2;

    while(cur_1->next != *head_1)
    {
        cur_1 = cur_1->next;
    }

    cur_1->next = cur_2;

    while(cur_2->next != *head_2)
    {
        cur_2 = cur_2->next;
    }
    cur_2->next = *head_1;

}
