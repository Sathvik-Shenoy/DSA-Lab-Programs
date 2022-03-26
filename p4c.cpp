#include<iostream>
#define max 20
using namespace std;
char s[max];
int top=-1;
string postfix="";
void push(char ele)
{
    if(top==max-1)
        cout<<"Overflow";
    else
        s[++top]=ele;
}
void pop()
{
    if(top==-1)
        cout<<"Underflow";
    else
        top--;
}
int priority(char ele)
{
    switch(ele)
    {
        case '^':return 4;
                 break;
        case '*':return 3;
                 break;
        case '/':return 3;
                 break;
        case '%':return 3;
                 break;
        case '+':return 2;
                 break;
        case '-':return 2;
                 break;
        default:return -1;
                break;     
    }
}
int main()
{
    int i=0;
    string infix;
    cout<<"Enter the infix expression:-";
    cin>>infix;
    while(infix[i]!='\0')
    {
        if(isalnum(infix[i]))
            postfix=postfix+infix[i];
        else
        {
            if(infix[i]=='(')
            {
                push(infix[i]);
            }
            else if(infix[i]==')')
            {
                while(s[top]!='(')
                {
                    postfix=postfix+s[top];
                    pop();
                }
                pop();
            }
            else
            {
                if(top!=-1){
                while(priority(infix[i])<=priority(s[top]))
                {
                    postfix=postfix+s[top];
                    pop();
                    if(top==-1)
                        break;
                }
                }
                push(infix[i]);
            }
        }
        i++;
    }
    while(top!=-1)
    {
        postfix=postfix+s[top];
        pop();
    }
    cout<<"Postfix expression is "<<postfix;
}