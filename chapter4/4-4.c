//stack ¥Îlinked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;


void push_stack(NODE **head, int data)
{
    printf("push\n");
    NODE *newnode = malloc(sizeof(NODE));
    NODE *cur;
    newnode->data = data;
    newnode->next = NULL;

    if(*head == NULL)
    {
        *head = newnode;
        (*head)->next = *head;
    }
    else
    {
        newnode->next = *head;
        cur = *head;

        while(cur->next != (*head))
        {
            cur = cur->next;
        }
        cur->next = newnode;

        *head = newnode;

    }
}

void pop_stack(NODE **head)
{
    printf("pop\n");

    NODE *cur, *tmp;

    if(*head == NULL)
    {
        printf("stack is empty.\n");
    }
    else
    {
        tmp = cur = *head;

        while(cur->next != (*head))
        {
            cur= cur->next;
        }
        cur->next = (*head)->next;
        *head = (*head)->next;

        free(tmp);
    }
}

void print_stack(NODE *head)
{
    printf("printf\n");
    NODE *cur;

    cur = head;

    while(cur->next != head)
    {
        printf("cur: %X, data: %d, next: %X\n", cur, cur->data, cur->next);
        cur= cur->next;
    }
    printf("cur: %X, data: %d, next: %X\n", cur, cur->data, cur->next);

}

int main()
{
    NODE *head = NULL;

    push_stack(&head, 0);
    print_stack(head);

    push_stack(&head, 1);
    push_stack(&head, 2);
    push_stack(&head, 3);
    print_stack(head);

    pop_stack(&head);
    print_stack(head);


    printf("\n");
    return 0;
}
