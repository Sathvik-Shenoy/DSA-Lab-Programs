#include<stdio.h>
#include<string.h>
void insertion(char str[])
{
    char t;
    int l;
    l=strlen(str);
    for(int i=1;i<l;i++)
        for(int j=i;j>0;j--)
            if(str[j]<str[j-1])
            {
                t=str[j];
                str[j]=str[j-1];
                str[j-1]=t;
            }
    printf("String after performing insertion sort is\n");
        printf("%s",str);
}
void selection(char str[])
{
    char t;
    int min,i,j;
    int l=strlen(str);
    for(i=0;i<l-1;i++)
    {
        min=i;
        for(j=i+1;j<l;j++)
            if(str[j]<str[min])
                min=j;
        if(min!=i)
        {
            t=str[i];
            str[i]=str[min];
            str[min]=t;
        }
    }
    printf("String after performing selection sort is\n");
        printf("%s",str);
}
void main()
{
    int ch;
    char str[100];
    printf("Enter the string:-");
    scanf("%s",str);
    printf("Enter 1 to insertion, 2 to selection:-");
    while(1){
    printf("Enter the choice:-");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:insertion(str);
               break;
        case 2:selection(str);
               break;  
    }
    }
}