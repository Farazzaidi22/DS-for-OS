#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node *next;
};

void insertt(Node **pointerTostart,int x)
{
    Node *temp = new Node();
    temp->value = x;
    temp->next = *pointerTostart;
    *pointerTostart = temp;
}

void print(Node **pointerTostart)
{
    Node *temp = *pointerTostart;

    cout<<"  The current list is";
    while(temp != NULL)
    {
        cout<<"\nThe value is: " << temp->value ;
        cout<<"\nThe address is: " << temp->next ;
        temp = temp-> next;
    }
    cout<<"\n" << endl;
}

int main()
{
    Node *start;
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

        insertt(&start,n);
        print(&start);
    }
}
