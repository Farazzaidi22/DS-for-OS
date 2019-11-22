#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
    int value;
    Node *prev;
};

Node *top= NULL;


void push(int val)
{
    Node *temp = new Node();
    temp->value= val;
    temp->prev= top;
    top= temp;
}

void pop()
{
    Node *temp;
    if(top==NULL)
    {
        cout<<"\nStack is empty" << endl;
    }
    else
    {
        temp=top;
        top= temp->prev;
        free(temp);
    }
}

void print()
{
    Node *temp = top;
    cout<<"The current list is";
    while(temp != NULL)
    {
        cout<<"\nThe value: " << temp->value ;
        temp = temp->prev;
    }
    cout<<"\n" << endl;
}

int main()
{
    push(3);
    push(4);
    push(5);
    push(6);

    print();

    pop();

    print();
}
