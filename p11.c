#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *right;
    struct node *left;
};
struct node * create(struct node *root,int ele)
{
    if(root==NULL)
    {
        struct node *temp;
        temp=(struct node *) malloc(sizeof(struct node));
        temp->data=ele;
        temp->right=NULL;
        temp->left=NULL;
        return temp;
    }
    if(ele<=root->data)
        root->left=create(root->left,ele);
    else if(ele>=root->data)
        root->right=create(root->right,ele);
    return root;
}
int search(struct node *root,int ele)
{
    if(root==NULL)
        return 0;
    if(ele==root->data)
        return 1;
    return(search(root->left,ele) || search(root->right,ele));
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
struct node * del(struct node *root,int ele)
{
    if(root==NULL)
        return;
    if(root->data==ele)
    {
        free(root);
        root=NULL;
    }
    root->left=del(root->left,ele);
    root->right=del(root->right,ele);
    return root;
}
void main()
{
    struct node *root=NULL;
    int ch,ele,n,b;
    printf("Enter 1 to create, 2 for inorder, 3 for postorder, 4 for preorder, 5 to search, 6 to exit");
    while(1)
    {
        printf("\nEnter choice:-");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter number of terms:-");
                   scanf("%d",&n);
                   for(int i=0;i<n;i++)
                   {    
                        printf("Enter the element:-");
                        scanf("%d",&ele);
                        root=create(root,ele);
                   }
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
            case 7:root=del(root,3);
                   break;   
        }
    }
}