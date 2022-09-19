//�o�Өƭn�����񺡪���C�A�]�N�Omax��5�B��ڤ]�n��뺡5�ӭȡA���D��l�ƮɩΦ�pop�ɤ��M�ӷ|�O��5�ӭȪ�
#include <stdio.h>
#include <stdlib.h>


#define max 5


int rear = max-1;
int front = max-1;
int full_tag = 0;


void CQ_enqueue(int *ar, int data)
{
    printf("En queue start~~\n");

    if((rear == front) && (full_tag == 1))
    {
        printf("Queue is full.\n");
        //�o�̮ѤW������ӧP�_���O�]����0�ɷ|-1�ܦ��t��

    }
    else
    {
        rear = (rear + 1) % max;
        *(ar + rear) = data;
        printf("add data = %d\n", *(ar + rear));
        if(front == rear)
        {
            full_tag = 1;
        }
    }
    printf("\n");
}

void CQ_dequeue(int *ar)
{
    printf("De queue start~~\n");

    if((rear == front) && (full_tag == 0))
    {
        printf("Queue is empty.\n");
    }
    else
    {
        if(front == rear)//�o�ǩǪ��کԨӫe���o�~�|����fulltag�A�ѬO�g�b�᭱
        {
            full_tag = 0;
        }
        front = (front + 1) % max;
        printf("data = %d\n", *(ar + front));

    }
    printf("\n");
}




void CQ_printqueue(int *ar)
{
    printf("Print queue start~~\n");
    printf("rear: %d, front = %d, full = %d\n", rear, front, full_tag);
    int i, cnt;


    if((rear == front) && (full_tag == 0))
    {
        printf("Queue is empty.\n");
    }
    else
    {
        i = (front + 1)%max;


        if((rear == front) && (full_tag == 1))
        {

            printf("Queue is full.\n");
            cnt = 0;
            do
            {
                printf("idx: %d, data = %d\n", i, *(ar + i));
                i = (i + 1)%max;
                cnt++;
            }
            while(cnt < 5);
        }
        else if(rear > front)
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

    CQ_enqueue(queue, 6);
    CQ_enqueue(queue, 99);
    CQ_printqueue(queue);

    CQ_enqueue(queue, 53);
    CQ_enqueue(queue, 74);
    CQ_printqueue(queue);


    CQ_enqueue(queue, 22);
    CQ_printqueue(queue);


    CQ_dequeue(queue);
    CQ_printqueue(queue);

    CQ_enqueue(queue, 48);
    CQ_printqueue(queue);

    CQ_enqueue(queue, 2);
    CQ_printqueue(queue);

    printf("\n");
    //system("pause");
    return 0;
}

