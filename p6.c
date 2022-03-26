#include<stdio.h>
#define max 3
char q[max];
int front=-1,rear=-1;
void enqueue()
{
    char ele;
    printf("Enter element:-");
    scanf("%s",&ele);
    if((rear+1)%max==front)
        printf("Overflow");
    else if(front==-1 && rear ==-1)
    {
        front=0;
        rear=0;
        q[front]=ele;
    }
    else
    {
        rear=(rear+1)%max;
        q[rear]=ele;
    }
}
void dequeue()
{
    char ele;
    if(front==rear)
    {
        front=-1;
        rear=-1;
        ele=q[front];
        printf("Deleted element is %c\n",ele);
    }
    if(front==-1 && rear==-1)
        printf("Underflow");
    else
    {
        ele=q[front];
        printf("Deleted element is %c\n",ele);
        front=(front+1)%max;
    }
}
void display()
{
    if(front==-1)
        printf("Undeflow");
    else
    {
        int i=front;
        while(i!=rear)
        {
            printf("%c ",q[i]);
            i=(i+1)%max;
        }
        printf("%c",q[rear]);
    }
}
void main()
{
    enqueue();
    enqueue();
    enqueue();
    dequeue();
    enqueue();
    display();
}