#include <iostream>
#include <stdlib.h>

using namespace std;

struct node
{
    int val;
    node *next;
};

node *frontt= NULL;
node *rear= NULL;


void Enqeueue(int val)
{
    node *temp= new node();
    temp->val= val;
    temp->next= NULL;

    if(frontt==NULL && rear== NULL)
    {
        frontt= temp;
        rear= temp;
        rear->next= NULL;
    }
    else
    {
        rear->next = temp;
        rear = rear->next;
        rear->next = NULL;
    }
}

void Dequeue()
{
    if(frontt==NULL && rear== NULL)
    {
        cout<<"\nQueue is empty" << endl;
    }
    else
    {
        node *temp= frontt;
        frontt= frontt->next;
        cout<<"Dequeued value is " << temp->val;
        if(frontt==rear)
        {
            rear->next= NULL;
        }
        free(temp);
    }
}

void print()
{
    node *temp = frontt;
    cout<<"The current list is";
    while(temp != NULL)
    {
        cout<<"\nThe value: " << temp->val ;
        temp = temp->next;
    }
    cout<<"\n" << endl;
}


int main()
{
    Enqeueue(3);
    Enqeueue(4);
    Enqeueue(5);
    Enqeueue(6);

    print();

    Dequeue();
    print();
}
