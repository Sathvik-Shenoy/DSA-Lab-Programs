#include<stdio.h>
#include<ctype.h>
int s[20],top=-1;
void push(char ele)
{
    int element;
    element=ele-'0';
    if(top==19)
        printf("Overflow");
    else
        s[++top]=element;
}
void toh(int n,char a,char b,char c)
{
    if(n>0)
    {
        toh(n-1,a,c,b);
        printf("Move from %c to %c\n",a,c);
        toh(n-1,b,a,c);
    }
}
void main()
{
    int i=0,t1,t2,res,n;
    char post[20];
    printf("Enter postfix expression:-");
    scanf("%s",post);
    while(post[i]!='\0')
    {
        if(isalnum(post[i]))
        {
            push(post[i]);
        }
        else
        {
            switch(post[i])
            {
                case '+':t1=s[top--];
                         t2=s[top--];
                         res=t1+t2;
                         s[++top]=res;
                         break;
                case '-':t1=s[top--];
                         t2=s[top--];
                         res=t2-t1;
                         s[++top]=res;
                         break;
                case '*':t1=s[top--];
                         t2=s[top--];
                         res=t1*t2;
                         s[++top]=res;
                         break;
                case '/':t1=s[top--];
                         t2=s[top--];
                         res=t2/t1;
                         s[++top]=res;
                         break;
            }
        }
        i++;
    }
    printf("Result is %d\n",res);
    //toh
    printf("Enter number of disks:-");
    scanf("%d",&n);
    toh(n,'a','b','c');
}