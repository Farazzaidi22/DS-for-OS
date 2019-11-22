#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodeLL
{
    int val;
    nodeLL *next= NULL;
};

struct Hash
{
    int value;
    nodeLL *head=NULL;
};

void insert_in_LL(int value, nodeLL **start)
{
    nodeLL *temp= new nodeLL();
    temp->val= value;
    temp->next= NULL;

    if(*start== NULL)
    {
        *start= temp;
    }
    else
    {
        nodeLL *curr= *start;
        while(curr->next != NULL)
        {
            curr= curr->next;
        }
        curr->next= temp;
    }
}

void printLL(nodeLL **start)
{
    nodeLL *temp = *start;
    while(temp != NULL)
    {
        cout<< temp->val ;
        temp = temp-> next;
    }
}

int reminder(int val, int sizee)
{
    int temp;
    temp= val%sizee;
    return temp;
}

void HInsert(Hash arr[], int s, int val)
{
    int index= reminder(val,s);
    int temp= index;

    if(arr[temp].value ==0)
    {
        arr[temp].value= val;
    }
    else
    {
        insert_in_LL(val, &(arr[temp].head));
    }
}

void print(Hash arr[], int s)
{
    for (int i = 0; i < s; i++)
    {
        cout << "Hash Table index: " << i << " has value: " << arr[i].value << endl << endl;
        cout << "Its List has following values: ";
        printLL(&(arr[i].head));
        cout << endl;
    }
}


int main()
{
    int s;
    cout<<"Enter size of your hash table: ";
    cin>>s;

    Hash arr[s];

    for(int i=0; i<s; i++)
    {
        arr[i].value= 0;
    }

    HInsert(arr, s, 10);
    HInsert(arr, s, 11);
    HInsert(arr, s, 12);
    HInsert(arr, s, 13);
    HInsert(arr, s, 14);
    HInsert(arr, s, 15);
    HInsert(arr, s, 16);

    print(arr, s);
}
