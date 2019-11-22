#include <iostream>
#include <stdlib.h>

using namespace std;

struct node
{
    int value;
    node *next;
};

/*node *start = NULL;
node *curr= start;*/


void insertt(int val, node **start)
{
    node *ptr;
    ptr=(struct node *) malloc(sizeof(node));

    ptr->value=val;
    ptr->next= NULL;

    //node *start = NULL;
    if(*start==NULL)
    {
        *start=ptr;
    }

    else
    {
        node *curr= *start;
        while(curr->next!= NULL)
        {
            curr= curr->next;
        }
        curr->next=ptr;
    }

    /*node *ptr;
    ptr = (node*) malloc(sizeof(node));
    ptr->value= val;
    ptr->next = NULL;
    cout<< "value is inserted: " ;
    cout<< ptr->value << endl;*/
}

void print(node **start)
{
    if(*start == NULL)
    {
        cout<<"there is no value in the list" << endl;
    }

    else
    {
        node *curr = *start;
        while(curr != NULL)
        {
            cout<< curr->value << endl;
            curr = curr-> next;
        }

        cout<< curr->value << endl;
    }
}

void del(int val, node **start)
{
    node *curr;
    curr = *start;
    if((*start) -> value== val)
    {
        (*start)= (*start) -> next;
        free(curr);
    }

    else
    {
        node *prev;

        curr = (*start)-> next;
        prev = (*start);
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


int main()
{
    node *start= NULL;
    //node *curr= start;

    insertt(22, &start);
    insertt(50, &start);

    del(50, &start);
    //insertt(12);

    print(&start);
}

