#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
    float data;
    int xexpo,yexpo,zexpo;
    struct node *next;
};
struct node * create()
{
    int ch=1;
    struct node *head,*newnode,*temp;
    head=(struct node *) malloc(sizeof(struct node));
    head->next=head;
    head->data=0;
    head->xexpo=-1;
    head->yexpo=-1;
    head->zexpo=-1;
    temp=head;
    while(ch==1)
    {
        newnode=(struct node *) malloc(sizeof(struct node));
        temp->next=newnode;
        printf("Enter the data, xexpo, yexpo, zexpo in decreasing order:-");
        scanf("%f%d%d%d",&newnode->data,&newnode->xexpo,&newnode->yexpo,&newnode->zexpo);
        temp=temp->next;
        head->data=head->data+1;
        printf("Enter 1 for more terms, 0 to finish:-");
        scanf("%d",&ch);
    }
    temp->next=head;
    return head;
}
void display(struct node *head)
{
    struct node *temp;
    temp=head->next;
    while(temp!=head)
    {
        printf("\n%.1fx^%dy^%dz^%d",temp->data,temp->xexpo,temp->yexpo,temp->zexpo);
        printf("+");
        temp=temp->next;
    }
}
struct node * add(struct node *head1, struct node *head2)
{
    struct node *head3,*temp1,*temp2,*temp3,*newnode;
    head3=(struct node *) malloc(sizeof(struct node));
    temp1=head1->next;
    temp2=head2->next;
    head3->data=0;
    head3->xexpo=-1;
    head3->yexpo=-1;
    head3->zexpo=-1;
    temp3=head3;
    while(temp1!=head1 && temp2!=head2)
    {
        if((temp1->xexpo+temp1->yexpo+temp1->zexpo)==(temp2->xexpo+temp2->yexpo+temp2->zexpo))
        {
            newnode=(struct node *) malloc (sizeof(struct node));
            temp3->next=newnode;
            newnode->data=temp1->data+temp2->data;
            newnode->xexpo=temp1->xexpo;
            newnode->yexpo=temp1->yexpo;
            newnode->zexpo=temp1->zexpo;
            temp3=temp3->next;
            temp1=temp1->next;
            temp2=temp2->next;
            head3->data=head3->data+1;
           // break;
        }
        else if((temp1->xexpo+temp1->yexpo+temp1->zexpo)>(temp2->xexpo+temp2->yexpo+temp2->zexpo))
        {
            newnode=(struct node *) malloc(sizeof(struct node));
            temp3->next=newnode;
            newnode->data=temp1->data;
            newnode->xexpo=temp1->xexpo;
            newnode->yexpo=temp1->yexpo;
            newnode->zexpo=temp1->zexpo;
            head3->data=head3->data+1;
            temp3=temp3->next;
            temp1=temp1->next;
        }
        else if((temp1->xexpo+temp1->yexpo+temp1->zexpo)<(temp2->xexpo+temp2->yexpo+temp2->zexpo))
        {   newnode=(struct node *) malloc(sizeof(struct node));
            temp3->next=newnode;
            newnode->data=temp2->data;
            newnode->xexpo=temp2->xexpo;
            newnode->yexpo=temp2->yexpo;
            newnode->zexpo=temp2->zexpo;
            head3->data=head3->data+1;
            temp3=temp3->next;
            temp2=temp2->next;
        }
    }
    if(temp1==head1)
    {
        while(temp2!=head2)
        {
            newnode=(struct node *) malloc(sizeof(struct node));
            newnode->next=NULL;
            newnode->data=temp2->data;
            newnode->xexpo=temp2->xexpo;
            newnode->yexpo=temp2->yexpo;
            newnode->zexpo=temp2->zexpo;
            head3->data=head3->data+1;
            temp3->next=newnode;
            temp3=newnode;
            temp2=temp2->next;
        }
    }
    else
    {
        while(temp1!=head1)
        {
            newnode=(struct node *) malloc(sizeof(struct node));
            newnode->next=NULL;
            newnode->data=temp1->data;
            newnode->xexpo=temp1->xexpo;
            newnode->yexpo=temp1->yexpo;
            newnode->zexpo=temp1->zexpo;
            head3->data=head3->data+1;
            temp3->next=newnode;
            temp3=newnode;
            temp1=temp1->next;
        }
    }
    temp3->next=head3;
    return head3;
}
void evaluate(struct node *head3)
{
    struct node *temp;
    temp=head3->next;
    float x,y,z,s=0;
    printf("Enter the values for x,y,z:-");
    scanf("%f%f%f",&x,&y,&z);
    while(temp!=head3)
    {    
        s=s+((temp->data)*pow(x,temp->xexpo)*pow(y,temp->yexpo)*pow(z,temp->zexpo));
         temp=temp->next;
    }
    printf("The result is %.1f",s);
}
void main()
{
    struct node *head0,*head1,*head2,*head3;
    int ch;
    while(1)
    {
        printf("Enter 1 to create poly 1, 2 to create poly 2, 3 to display poly 1, 4 to display poly 2, 5 to add poly 1 and poly 2, 6 to evaluate, 7 to display poly 3, 8 to exit:-\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:head1=create();
                   break; 
            case 2:head2=create();
                   break;
            case 3:display(head1);
                   break;
            case 4:display(head2);
                   break;  
            case 5:head3=add(head1,head2);
                   break;
            case 6:evaluate(head3); 
                   break; 
            case 7:display(head3);
                   break; 
            case 8:exit(0);
        }
    }
}