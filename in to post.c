#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define max 100
char stack[max];
char postfix[100]="";
int top=-1;
int priority(char a)
{
    if(a=='^')
        return 3;
    else if(a=='*'||a=='/')
        return 2;
    else if(a=='+'||a=='-')
        return 1;
    else
        return -1;
}
void push(char a)
{
    if(top==max-1)
        printf("Stack Overflow");
    else
    {
        top=top+1;
        stack[top]=a;
    }
}
void pop()
{
    if(top==-1)
        printf("Stack Underflow");
    else
    {
        top=top-1;
    }
}
void intopo(char infix[])
{
    char ch,ele;
    int i=0;
    //char postfix[100]="";
    while(infix[i]!='\0')
    {   
        if(isalnum(infix[i]))
        {
            ele=infix[i];
            strncat(postfix,&ele,1);
        }
        else if(infix[i]=='(')
            push(infix[i]);
        else if(infix[i]==')')
        {
            while(stack[top]!='(')
            {
                ele=stack[top];
                strncat(postfix,&ele,1);
                pop();
            }
            pop();
        }
        else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/')
        {
            if(top!=-1)
            {
                while(priority(infix[i])<=priority(stack[top]))
                {
                    ele=stack[top];
                    strncat(postfix,&ele,1);
                    pop();
                }
                if(top==-1)
                    break;
            }
            push(infix[i]);
        }
        i++;
    }
    while(top!=-1)
    {
        ele=stack[top];
        strncat(postfix,&ele,1);
        pop();
    }
}
void main()
{
    char infix[100];
    printf("Enter infix expression:-");
    scanf("%s",&infix);
    intopo(infix);
    printf("%s",postfix);
}