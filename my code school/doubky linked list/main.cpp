
#include <iostream>
#include <stdlib.h>
using namespace std;


struct Node
{
    int val;
    Node *next, *prev;
};

Node *start= NULL;

void insertt(int value)
{
    Node *temp= new Node();
    temp->val= value;
    temp->next= NULL;
    temp->prev= NULL;

    if(start== NULL)
    {
        start= temp;
        start->prev= NULL;
    }
    else
    {
        Node *curr = start;
        while(curr->next!= NULL)
        {
            curr = curr->next;
        }
        curr->next= temp;
        temp->prev= curr;
    }
}


void del(int val)
{
    Node *curr;
    curr = start;
    if(start -> val== val)
    {
        start= start-> next;
        start->prev= NULL;
        free(curr);
    }

    else
    {
        Node *prev;

        curr = start-> next;
        prev = start;
        while(curr-> val != val)
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
    if(temp->val == val)
    {
        cout<<"Number " << temp->val << " is present in the list" << endl;
    }

    else
    {
        temp = start->next;
        while(temp->val != val)
        {
            temp= temp->next;

            if(temp->val == val)
            {
                break;
                cout<<"Number " << temp->val << " is present in the list" << endl;
            }

            else
            {
                cout<<"Element is not present in the list" << endl;
            }
        }

        //cout<<"Number " << temp->value << " is present in the list" << endl;
    }

}

void print()
{
    Node *temp = start;
    cout<<"The current list is";
    while(temp != NULL)
    {
        cout<<"\nThe value is: " << temp->val; //<< " " << (temp->prev) << " " << (temp->next) ;
        temp = temp-> next;
    }
    cout<<"\n" << endl;
}

int main()
{
   insertt(2);
   insertt(4);
   insertt(6);
   insertt(8);

   print();

   del(6);
   print();

   searchh(2);
   searchh(7);
}
