#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;
#define max 100
char stack[max];
string postfix="";
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
    int i=0;
    //char postfix[100]="";
    while(infix[i]!='\0')
    {   
        if(isalnum(infix[i]))
            postfix=postfix+infix[i];
        else if(infix[i]=='(')
            push(infix[i]);
        else if(infix[i]==')')
        {
            while(stack[top]!='(')
            {
                postfix=postfix+stack[top];
                pop();
            }
            pop();
        }
        else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='^')
        {
            if(top!=-1)
            {
                while(priority(infix[i])<=priority(stack[top]))
                {
                    postfix=postfix+stack[top];
                    pop();
                    if(top==-1)
                        break;
                }
            }
            push(infix[i]);
        }
        i++;
    }
    while(top!=-1)
    {
        postfix=postfix+stack[top];
        pop();
    }
}
int main()
{
    char infix[100];
    cout<<"Enter infix expression:-";
    cin>>infix;
    intopo(infix);
    cout<<postfix;
    return 0;
}