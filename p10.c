#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node * create()
{
    int d;
    struct node *newnode;
    newnode=(struct node *) malloc(sizeof(struct node));
    printf("Enter the data, -1 to stop:-");
    scanf("%d",&d);
    if(d==-1)
        return NULL;
    newnode->data=d;
    printf("Enter elements for left node:-");
    newnode->left=create();
    printf("Enter elements for right node:-");
    newnode->right=create();
    return newnode;
}
void in(struct node *root)
{
    if(root==NULL)
        return;
    in(root->left);
    printf("%d ",root->data);
    in(root->right);
}
void pre(struct node *root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    pre(root->left);
    pre(root->right);
}
void post(struct node *root)
{
    if(root==NULL)
        return;
    post(root->left);
    post(root->right);
    printf("%d ",root->data);
}
int search(struct node *root,int ele)
{
    if(root==NULL)
        return 0;
    if(root->data==ele)
    {   
        return 1;
    }
    return(search(root->right,ele) || search(root->left,ele));
}
void main()
{
    int b;
    struct node *root;
    int ch,ele;
    printf("Enter 1 to create, 2 for inorder, 3 for postorder, 4 for preorder, 5 to search, 6 to exit");
    while(1)
    {
        printf("\nEnter choice:-");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:root=create();
                   break;
            case 2:in(root); 
                   break;
            case 3:post(root);
                   break;
            case 4:pre(root);
                   break;
            case 5:printf("Enter element to search:-");
                   scanf("%d",&ele);
                   b=search(root,ele);
                   if(b==1)
                    printf("Found\n");
                   else
                    printf("Not found\n"); 
                   break;  
            case 6:exit(0);  
        }
    }
}