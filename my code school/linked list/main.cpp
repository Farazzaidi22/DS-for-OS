#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    int value;
    Node *next;
};

Node *start;

void insertt(int x)
{
    Node *temp = new Node();
    temp->value = x;
    temp->next = NULL;

    if(start== NULL)
    {
        start= temp;
    }
    else
    {
        Node *curr = start;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next= temp;
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

void del(int val)
{
    Node *curr;
    curr = start;
    if(start -> value== val)
    {
        start= start-> next;
        free(curr);
    }

    else
    {
        Node *prev;

        curr = start-> next;
        prev = start;
        while(curr-> value != val)
        {
            curr = curr -> next;
            prev = prev -> next;
        }

        prev -> next = curr -> next;
        free(curr);

        cout<<"the element was deleted" << endl;
    }
}

void searchh(int val)
{
    Node *temp = start;
    if(temp->value == val)
    {
        cout<<"Number " << temp->value << " is present in the list" << endl;
    }

    else
    {
        temp = start->next;
        while(temp->value != val)
        {
            temp= temp->next;

            if(temp->value == val)
            {
                break;
                cout<<"Number " << temp->value << " is present in the list" << endl;
            }

            else
            {
                cout<<"Element is not present in the list" << endl;
            }
        }

        //cout<<"Number " << temp->value << " is present in the list" << endl;
    }

}

void reverselist()
{
    if(start== NULL)
    {
        cout<<"\nThe list is empty" << endl;
    }
    else
    {
        Node *curr= start, *prev= NULL, *next;

        while(curr!= NULL)
        {
            next= curr->next;
            curr->next = prev;
            prev= curr;
            curr = next;
        }
        start= prev;
    }
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

    int d;
    char ch;
    cout<<"\n\n do you want to delete an element?\n1 for deleting an element \n2 for searching a number in the list \n3 for Reversing the list \n4 for exiting program \nEnter: ";
    cin>>ch;

    switch(ch)
    {
    case '1':
        cout<<"\nEnter the element you want to delete: ";
        cin>>d;
        del(d);

        cout<<"\nNow the current list is\n";
        print();
        break;

    case '2':
        cout<<"\nEnter the element you want to search: ";
        cin>>d;
        searchh(d);
        break;

    case '3':
        cout<<"\nReversed List is" << endl;
        reverselist();
        print();

    default:
        cout<<"\n Thank you :)" << endl;
    }
}
