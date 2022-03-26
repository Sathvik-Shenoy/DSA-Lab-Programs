#include<stdio.h>
int arr[20],n;
void insert()
{
    int pos;
    printf("Enter the position:-");
    scanf("%d",&pos);
    for(int i=n-1;i>=pos-1;i--)
        arr[i+1]=arr[i];
    n++;
}
void delete()
{
    int pos;
    printf("Enter the position:-");
    scanf("%d",&pos);
    for(int i=pos-1;i<n-1;i++)
        arr[i]=arr[i+1];
    n--;
}
void display()
{
    printf("Elements are:-");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
}
void main()
{
    int ch;
    printf("Enter number of elements:-");
    scanf("%d",&n);
    printf("Enter elements of array:-");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter 1 to insert, 2 to delete, 3 to display:-");
    while(1){
    printf("Enter the choice:-");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:insert();
               break;
        case 2:delete();
               break;  
        case 3:display();
               break; 
    }
    }
}