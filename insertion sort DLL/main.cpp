#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    int value;
    Node *next;
    Node *prev;
};

Node *start;

void insertt(int val)
{
    Node *temp = new Node();
    temp->value = val;
    temp->next = start;

    if(start == NULL)
    {
        start = temp;
    }

    else
    {
        start->prev = temp;
        temp->next = start;
        start = temp;
    }
}

void print()
{
    Node *temp = start;
    cout<<"The current list is";
    while(temp != NULL)
    {
        cout<<"\nThe value is: " << temp->value ;
        temp = temp-> next;
    }
    cout<<"\n" << endl;
}

int main()
{
    start =  NULL;
    int no,n;
    cout<< "Enter number of elements you want in the list: ";
    cin>>no;
    cout<<"\n" << endl;

    for(int i =0; i< no; i++)
    {
        cout<<"Enter your number: ";
        cin>>n;
        cout<< endl ;

        insertt(n);
        print();
    }
}
