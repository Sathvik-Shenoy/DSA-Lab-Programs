#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *right;
    struct node *left;
}*newnode,*temp,*head=NULL;
void create()
{
    int ch=1;
    while(ch==1)
    {
        printf("Enter data:-");
        newnode=(struct node *) malloc(sizeof(struct node));
        newnode->right=NULL;
        newnode->left=NULL;
        scanf("%d",&newnode->data);
        if(head==NULL)
            head=temp=newnode;
        else
        {
            temp->right=newnode;
            newnode->left=temp;
            temp=temp->right;
        }
        printf("Enter 1 to continue, 0 to stop");
        scanf("%d",&ch);
    }
}
void ins_front()
{
    printf("Enter data:-");
    newnode=(struct node *) malloc(sizeof(struct node));
    newnode->right=NULL;
    newnode->left=NULL;
    scanf("%d",&newnode->data);
    temp=head;
    temp->left=newnode;
    newnode->right=temp;
    head=newnode;
}
void del_front()
{
    temp=head;
    head=head->right;
    head->left=NULL;
    free(temp);
}
void ins_end()
{
    temp=head;
    while(temp->right!=NULL)
        temp=temp->right;
    printf("Enter data:-");
    newnode=(struct node *) malloc(sizeof(struct node));
    newnode->right=NULL;
    newnode->left=NULL;
    scanf("%d",&newnode->data);
    temp->right=newnode;
    newnode->left=temp;
}
void del_end()
{
    temp=head;
     while(temp->right!=NULL)
        temp=temp->right;
    temp->left->right=NULL;
    free(temp);
}
void display()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->right;
    }
}
void main()
{
    create();
    display();
    ins_front();
    display();
    del_front();
    display();
    ins_end();
    display();
    del_end();
    display();
}