#include<stdio.h>
#include<stdlib.h>
struct node
{
    int sem;
    char USN[10],name[20],ph[10];
    struct node *next;
}*head=NULL,*newnode,*temp;
void create()
{
    int ch=1;
    while(ch==1)
    {
    newnode=(struct node *) malloc(sizeof(struct node));
    newnode->next=NULL;
    printf("Enter student USN,name,semester,ph:-");
    scanf("%s%s%d%s",newnode->USN,newnode->name,&newnode->sem,newnode->ph);
    if(head==NULL)
        head=temp=newnode;
    else
    {
        newnode->next=temp;
        head=newnode;
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
        printf("Student USN,name,semester,ph no is:-\n");
        while(temp!=NULL)
        {
            printf("%s %s %d %s\n",temp->USN,temp->name,temp->sem,temp->ph);
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
    printf("Enter student USN,name,semester,ph:-");
    scanf("%s%s%d%s",newnode->USN,newnode->name,&newnode->sem,newnode->ph);
    temp->next=newnode;
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
    printf("Enter student USN,name,semester,ph:-");
    scanf("%s%s%d%s",newnode->USN,newnode->name,&newnode->sem,newnode->ph);
    newnode->next=temp;
    head=newnode;
}
void delete_front()
{
    temp=head;
    head=head->next;
    free(temp);
    temp=NULL;
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