#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int top=-1;
char stackk[10];

int isempty(char stackk[])
{
    if(stackk[top]== -1)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

char isfull(char stackk[])
{
    if(top==9)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

char peek(char stackk[])
{
    if(stackk[top]==-1)
    {

        return '0';
    }
    else{
    return stackk[top];
    }
}

void push(char stackk[],char val)
{
    if(!isfull(stackk))
    {
        top++;
        stackk[top]= val;
        cout<<"PUSHED"<<endl;
    }
    else
    {
        cout<<"\nStack is full";
    }
}

char pop(char stackk[])
{
    if(!isempty(stackk))
    {
        char temp= stackk[top];
        top--;
        cout<<"POP"<<endl;
        return temp;
    }
    else
    {
        cout<<"\nStack is empty" << endl;
    }
}

int Prec(char);
char operand(char);
void converter(char infix[],int);

int main()
{
    char infix[]="a+b*c";

    /*for(int i=0; i<5; i++)
    {
        cin>>infix[i];
    }*/

    converter(infix,5);
}

int Prec(char ch)
{
    switch (ch)
    {

    case '|':
        return 1;

    case '&':
        return 2;

    case '<':
    case '>':
    case '=':
    case '~':
        return 3;

    case '+':
    case '-':
        return 4;

    case '*':
    case '/':
        return 5;
    }
    return -1;
}

char operand(char op)
{
    return ((op >= 'a' && op <= 'z') || (op >= 'A' && op <= 'Z') || (op >= 'A' && op <= 'Z'));
}
void converter(char infix[],int s)
{

    char postfix[5];
    int j=0,pr=0,prec2,i;

    for(i=0; i<s ; i++)
    {
        pr=Prec(infix[i]);
        if(pr==-1)
        {
        postfix[j]=pop(stackk);
        j++;
        }
        else{
           char peak=peek(stackk);
            if(peak=='0')
            {

                push(stackk,infix[i]);
            }
            else{
                prec2=Prec(peek(stackk));
                if(prec2>=pr)
                {

                    while(Prec(peek(stackk))>=pr)
                    {
                        postfix[j]=pop(stackk);
                        j++;
                    }
                }
                push(stackk,infix[i]);
            }
        }

    }
    while(j<i)
    {
        postfix[j]=pop(stackk);
    }
        /*if(operand(infix[i]))
            postfix[j] = infix[i        {
];
            j++;
        }
        else
        {
            while ((Prec(infix[i]) <= Prec(peek(stackk))))
            {
                postfix[j] = pop(stackk);
                j++;
            }
            push(stackk,infix[i]);
        }
    }

        while (!isempty(stackk))
        {
            postfix[j] = pop(stackk);
            j++;
        }
*/
        for(int f=0; f<5; f++)
        {
            cout<<"\nPostfix expression is: "<<postfix[f];
        }
}
