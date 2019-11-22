#include <iostream>
#include <stdlib.h>
using namespace std;


struct Employee
{
    string name;
    int id;
    float salary;
    Employee *next, *prev;
};

Employee *start= NULL;

void insertt(string n, int ID, float sal)
{
    Employee *temp= new Employee();
    temp->name= n;
    temp->id= ID;
    temp->salary= sal;
    temp->next= NULL;
    temp->prev= NULL;

    if(start== NULL)
    {
        start= temp;
        start->prev= NULL;
    }
    else
    {
        Employee *curr = start;
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
    Employee *curr;
    curr = start;
    if(start->id== val)
    {
        start= start-> next;
        start->prev= NULL;
        free(curr);
    }

    else
    {
        Employee *prev;

        curr = start-> next;
        prev = start;
        while(curr->id != val)
        {
            curr = curr -> next;
            prev = prev -> next;
        }

        prev -> next = curr -> next;
        free(curr);

        cout<<"the element was deleted" << endl;
    }
}

void searchh(string n)
{
    Employee *temp = start;
    if(temp->name == n)
    {
        cout<< temp->name << " is present in the list" << endl;
    }

    else
    {
        temp = start->next;
        while(temp->name != n)
        {
            temp= temp->next;

            if(temp->name == n)
            {
                break;
                cout<<"Employee " << temp->name << " is present in the list" << endl;
            }

            else
            {
                cout<<"Employee is not present in the list" << endl;
            }
        }

        //cout<<"Number " << temp->value << " is present in the list" << endl;
    }

}

void print()
{
    Employee *temp = start;
    cout<<"The current employee list is";
    while(temp != NULL)
    {
        cout<<"\nThe name is: " << temp->name;
        cout<<"\nThe id is: " << temp->id;
        cout<<"\nThe salary is: " << temp->salary << endl; //<< " " << (temp->prev) << " " << (temp->next) ;
        temp = temp-> next;
    }
    cout<<"\n" << endl;
}

int main()
{

   insertt("muaz", 05, 1000);
   insertt("faraz", 22, 1200);
   insertt("mujtaba", 31, 1400);
   insertt("rafay", 21, 1600);
   insertt("amil", 11, 1800);


   char ch;
   do{
   cout<<"Enter \n1. for inserting a new employee \n2. for deleting an employee (enter employee ID) \n3. for searching an employee (with name) \n4. for displaying list \n5.for quiting program \nEnter your choice: ";
   cin>> ch;

   switch(ch)
   {
   case '1':
    {  string n;
       int id;
       float sal;
    cout<<"Enter employee name: ";
    cin>>n;
    cout<<"Enter employee id: ";
    cin>>id;
    cout<<"Enter employee salary: ";
    cin>>sal;
    insertt(n, id, sal);
    break;
    }

   case '2':
    {int idx;
    cout<<"Enter employee id to delete his/her info: ";
    cin>>idx;
    del(idx);
    break;
    }

   case '3':
    {string naam;
    cout<<"Enter employee name to be searched in the list: ";
    cin>>naam;
    searchh(naam);
    break;}

   case '4':
    {print();
    break;}
   }


   } while(ch != 5);
}
