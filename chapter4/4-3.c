#include <stdlib.h>
#include <stdio.h>

#define L1  5

typedef struct node
{
    int data;
    struct node *rs;
    struct node *ls;
}NODE;


void createList(NODE **, int);
void freeList(NODE **);
void printList(NODE *);

void addnode(NODE **, int, int);
void deletenode(NODE **, int);

int main(int argc, char *argv[])
{
    int i, j;
    NODE *head = NULL;

    for(i = 0; i < L1; i++)
    {
        createList(&head, i);
    }


    printList(head);
    printf("\n");



    addnode(&head, 0, 9);
    printf("\n");

    printList(head);
    printf("\n");

    deletenode(&head, 0);
    printf("\n");

    printList(head);
    printf("\n");

    freeList(&head);


    return 0;
}

void createList(NODE **head, int data)
{
    NODE *cur, *newnode, *temp;
    newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = data;
    newnode->rs = newnode;
    newnode->ls = newnode;

    if(*head != NULL)
    {
       cur = *head;

       while(cur->rs != *head)
       {
           temp = cur;
           cur = cur->rs;
           cur->ls = temp;
       }

       cur->rs = newnode;
       newnode->ls = cur;
       newnode->rs = *head;
       (*head)->ls = newnode;
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
        while(cur->rs != *head)
        {
            tmp = cur;
            cur = cur->rs;
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
        while(cur->rs != head)
        {
            printf("ls: %X, address: %X, data: %d, rs:%X\n",cur->ls, cur, cur->data, cur->rs);
            cur = cur->rs;
        }
        printf("ls: %X, address: %X, data: %d, rs:%X\n",cur->ls, cur, cur->data, cur->rs);
    }
    else
    {
        printf("\n It's empty.\n");
    }


}


void addnode(NODE **head, int data, int newdata)
{
    printf("\n Add node\n");
    NODE *cur, *newnode, *temp;
    cur = *head;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->data = newdata;

    if(*head != NULL)
    {
        while(cur->rs != *head)
        {
            if(cur->data == data)
            {
                temp = cur->rs;
                cur->rs = newnode;
                newnode->ls = cur;
                newnode->rs = temp;
                temp->ls = newnode;
                break;
            }
            else
            {
                cur = cur->rs;
            }

        }
        if(cur->rs == *head)
        printf("\n Not found\n");
    }
    else
    {
        printf("\n It's empty.\n");
    }
}

void deletenode(NODE **head, int data)
{
    printf("\n Delete node\n");
    NODE *cur, *temp;
    cur = *head;
    if(*head != NULL)
    {
        while(cur->rs != *head)
        {
            if(cur->rs->data == data)
            {
                temp = cur->rs;
                cur->rs = temp->rs;
                temp->rs->ls =cur;
                break;
            }
            else
            {
                cur = cur->rs;
            }
        }
        if(cur->rs == *head)
        printf("\n Not found\n");
    }
    else
    {
        printf("\n It's empty.\n");
    }

}
