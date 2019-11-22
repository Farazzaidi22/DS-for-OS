#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

struct node
{
    int val;
    int exp;
    node *prev;
    node *next;
};

void insertt(int value,int expo, node **start)
{
    node *temp= new node();
    temp->val= value;
    temp->exp= expo;
    temp->prev= NULL;
    temp->next= NULL;

    if(*start== NULL)
    {
        *start= temp;
    }
    else
    {
       node *curr= *start;
       while(curr->next!= NULL)
       {
           curr= curr->next;
       }
       curr->next= temp;
       temp->prev= curr;
    }
}

void print(node **start)
{
    node *temp = *start;
    cout<<"The current list is";
    while(temp != NULL)
    {
        cout<<"\nThe value is: " << temp->val << "^" << temp->exp;
        temp = temp-> next;
    }
    cout<<"\n" << endl;
}

void connect(node **first, node **second)
{
    node *temp1= *first;
    node *temp2= *second;

    while(temp1->next != NULL)
    {
        temp1= temp1->next;
    }
    temp1->next= temp2;
}

void add(node **start)
{
    node *curr= *start;
    while(curr->next!= NULL)
    {

        node *temp= curr->next;
        while(temp->next!= NULL)
        {
            if(curr->exp== temp->exp)
            {
                curr->val= curr->val + temp->val;
            }
            temp= temp->next;
        }
        curr= curr->next;
    }

}

int main()
{
    node *start1 =NULL, *start2= NULL;
    insertt(1, 1,&start1);
    insertt(3, 2,&start1);
    insertt(5, 3,&start1);
    insertt(7, 4,&start1);

    print(&start1);

    insertt(2,1, &start2);
    insertt(4,2, &start2);
    insertt(6,3, &start2);
    insertt(8,4, &start2);

    print(&start2);

    connect(&start1, &start2);
    print(&start1);

    add(&start1);
    print(&start1);
}
