//這個事要完全填滿的佇列，也就是max有5且實際也要能塞滿5個值，除非初始化時或有pop時不然該會是滿5個值的
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
        //這裡書上分成兩個判斷式是因為當0時會-1變成負的

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
        if(front == rear)//這怪怪的我拉來前面這才會消掉fulltag，書是寫在後面
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
                while((i != front)&&(front + cnt <= rear+5))//這裡很難想
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

