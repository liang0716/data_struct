//������Ccycle queue�~��O�@�ӯu��queue�i�H�@���i�J�@�����X
//�o�Өƥ������񺡪���C�A�]�N�Omax��5����ڥu��s4�ӭȡAfront����m�|�O���L�Ū�
#include <stdio.h>
#include <stdlib.h>


#define max 5


int rear = max-1;
int front = max-1;

void CQ_enqueue(int *ar, int data)
{
    printf("En queue start~~\n");
    rear = (rear + 1) % max;
    if(rear == front)
    {
        printf("Queue is full.\n");
        //�o�̮ѤW������ӧP�_���O�]����0�ɷ|-1�ܦ��t��
        if(rear == 0)
        {
            rear = max - 1;
        }
        else
        {
            rear = rear - 1;
        }

    }
    else
    {
        *(ar + rear) = data;
        printf("add data = %d\n", *(ar + rear));
    }
    printf("\n");
}

void CQ_dequeue(int *ar)
{
    printf("De queue start~~\n");

    if(front == rear)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        front = (front + 1) % max;
        printf("data = %d\n", *(ar + front));
    }
    printf("\n");
}


void CQ_printqueue(int *ar)
{
    printf("print queue start~~\n");
    printf("rear: %d, front = %d\n", rear, front);
    int i, cnt;


    if(front == rear)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        if(rear > front)
        {
            printf("if\n");
            for(i = front + 1; i <= rear; i++)
            {
                printf("idx: %d, data = %d\n", i, *(ar + i));
            }
        }
        else
        {
            printf("else\n");
            i = (front + 1) % max;
            if(i == rear)
            {
                printf("idx: %d, data = %d\n", i, *(ar + i));
            }
            else
            {
                //while((i != front))//
                cnt = 1;
                while((i != front)&&(front + cnt <= rear+5))//�o�̫����Q
                {
                    printf("idx: %d, data = %d\n", i, *(ar + i));
                    i = (i + 1) % max;
                    if(cnt >= max)
                    {
                        break;
                    }
                    cnt++;
                }
            }

        }
    }

    printf("\n");
}

int main(int argc, char* argv[])
{
    int queue[max];

    CQ_printqueue(queue);

    CQ_enqueue(queue, 10);
    CQ_printqueue(queue);


    CQ_dequeue(queue);
    CQ_printqueue(queue);


    CQ_enqueue(queue, 5);
    CQ_enqueue(queue, 99);
    CQ_enqueue(queue, 33);
    CQ_enqueue(queue, 8);
    CQ_printqueue(queue);

    CQ_enqueue(queue, 49);
    CQ_printqueue(queue);

    CQ_dequeue(queue);
    CQ_printqueue(queue);

    CQ_enqueue(queue, 62);
    CQ_printqueue(queue);

    CQ_dequeue(queue);
    CQ_printqueue(queue);


    printf("\n");
    system("pause");
    return 0;
}

