#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int val;
    node *prev;
    node *next;
};

void insertt(int value, node **start)
{
    node *temp= new node();
    temp->val= value;
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
        cout<<"\nThe value is: " << temp->val;
        temp = temp-> next;
    }
    cout<<"\n" << endl;
}

bool isPresent (node *head, int data)
{
	node *t = head;
	while (t != NULL)
	{
		if (t->val == data)
			return 1;
		t = t->next;
	}
	return 0;
}

node *getUnion(node *head1, node *head2)
{
    node *result = NULL;
    node *t1 = head1, *t2 = head2;

    while (t1 != NULL)
    {
        insertt(t1->val, &result);
        t1 = t1->next;
    }

    while (t2 != NULL)
    {
        if (!isPresent(result, t2->val))
            insertt(t2->val, &result);
        t2 = t2->next;
    }

    return result;
}

node *getIntersection(node *head1, node *head2)
{
	node *result = NULL;
	node *t1 = head1;

	while (t1 != NULL)
	{
		if (isPresent(head2, t1->val))
			insertt(t1->val,&result);
		t1 = t1->next;
	}

	return result;
}

node *getdiff(node *head1, node *head2)
{
	node *result = NULL;
	node *t1 = head1;

	while (t1 != NULL)
	{
		if (!isPresent(head2, t1->val))
			insertt(t1->val,&result);
		t1 = t1->next;
	}

	return result;
}


node* connect(node **first, node **second)
{
    node *temp1= *first;
    node *temp2= *second;

    while(temp1->next != NULL)
    {
        temp1= temp1->next;
    }
    temp1->next= temp2;

    return temp1;
}

void swapp(node *a, node *b)
{
	int temp = a->val;
	a->val = b->val;
	b->val = temp;
}


void bubbleSort(node *start)
{
	int swapped, i;
	node *ptr1;
	node *lptr = NULL;

	if (start == NULL)
		return;

	do
	{
		swapped = 0;
		ptr1 = start;

		while (ptr1->next != lptr)
		{
			if (ptr1->val > ptr1->next->val)
			{
				swapp(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
	while (swapped);
}

void costum_insertt(int value1,int value2 ,node *start);

int main()
{
    node *start1 =NULL, *start2= NULL;
    insertt(1, &start1);
    insertt(3, &start1);
    insertt(5, &start1);
    insertt(7, &start1);

    //print(&start1);

    insertt(2, &start2);
    insertt(4, &start2);
    insertt(1, &start2);
    insertt(8, &start2);

    //print(&start2);

    /*node *sortt = connect(&start1, &start2);
    print(&start1);

    bubbleSort(sortt);*/

    /*node *uni= NULL;
    uni= getUnion(start1,start2);
    print(&uni);

    node *intersection=  NULL;
    intersection = getIntersection(start1, start2);
    print(&intersection);*/

    node *diff= NULL;
    diff= getdiff(start1,start2);
    print(&diff);


    /*costum_insertt(2, 10 ,start1);
    print(&start1);*/
}


void costum_insertt(int value1,int value2 ,node *start)
{
    /*node *temp= new node();
    temp->val= value;
    temp->prev= NULL;
    temp->next= NULL;*/

    node *temp1= new node();
    temp1->val= value1;
    temp1->prev= NULL;
    temp1->next= NULL;

    node *temp2= new node();
    temp2->val= value1;
    temp2->prev= NULL;
    temp2->next= NULL;

    /*if(*start== NULL)
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
       temp->prev= curr;*/


       node *curr1= start->next->next;
       node *curr = start->next->next->next;
       while(curr->next != NULL)
       {
           curr= curr->next->next;
           insertt(temp1->val, &start->next);
           insertt(temp2->val, &start->next->next);
       }
       curr1->next= temp1;
       curr->next= temp2;
}

