#include<stdio.h>
#include<stdlib.h>
struct node
{
    float sal;
    char SSN[10],name[20],ph[10],dept[10],des[10];
    struct node *next;
    struct node *prev;
}*head=NULL,*newnode,*temp;
void create()
{
    int ch=1;
    while(ch==1)
    {
    newnode=(struct node *) malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->prev=NULL;
    printf("Enter student SSN,name,ph,dept,designation,salary:-");
    scanf("%s%s%s%s%s%f",newnode->SSN,newnode->name,newnode->ph,newnode->dept,newnode->des,&newnode->sal);
    if(head==NULL)
        head=temp=newnode;
    else
    {
        temp->next=newnode;
        temp=temp->next;
    }
    printf("Enter 1 to continue, 0 to exit:-");
    scanf("%d",&ch);
    }
}
void display()
{
    int c=0;
    if(head==NULL)
        printf("Underflow");
    else
    {
        temp=head;
        printf("Student SSN,name,ph,dept,designation,salary is:-\n");
        while(temp!=NULL)
        {
            printf("%s %s %s %s %s %f\n",newnode->SSN,newnode->name,newnode->ph,newnode->dept,newnode->des,newnode->sal);
            temp=temp->next;
            c++;
        }
        printf("Number of nodes is %d",c);
    }
}
void insert_end()
{
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    newnode=(struct node *) malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->prev=NULL;
    printf("Enter student USN,name,semester,ph:-");
    scanf("%s%s%s%s%s%f",newnode->SSN,newnode->name,newnode->ph,newnode->dept,newnode->des,&newnode->sal);
    temp->next=newnode;
    newnode->prev=temp;
}
void delete_end()
{
    struct node *prev_node;
    temp=head;
    while(temp->next!=NULL)
    {
        prev_node=temp;
        temp=temp->next;
    }
    prev_node->next=NULL;
    free(temp);
}
void insert_front()
{
    temp=head;
    newnode=(struct node *) malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->prev=NULL;
    printf("Enter student USN,name,semester,ph:-");
    scanf("%s%s%s%s%s%f",newnode->SSN,newnode->name,newnode->ph,newnode->dept,newnode->des,&newnode->sal);
    newnode->next=temp;
    temp->prev=newnode;
    head=newnode;
}
void delete_front()
{
    temp=head;
    head=head->next;
    free(temp);
}
void main()
{
    int ch;
    while(1)
    {
        printf("Enter 1 to create, 2 to display, 3 to insert at end, 4 to delete at end, 5 to insert at beginning, 6 to delete at beginning, 7 to exit:-\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:create();
                   break; 
            case 2:display();
                   break;
            case 3:insert_end();
                   break;
            case 4:delete_end();
                   break;  
            case 5:insert_front();
                   break;
            case 6:delete_front(); 
                   break; 
            case 7:exit(0);
            default:printf("Invalid choice");
                    break;
        }
    }
}