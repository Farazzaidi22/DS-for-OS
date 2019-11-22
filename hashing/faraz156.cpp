#include <iostream>
#include <stdlib.h>

using namespace std;

int ret_index(int value, int sizee)
{
    int cal;
    cal = value % sizee;
    return cal;
}


void insertt(int a[], int index, int value, int s)
{
    if(a[index]==0)
    {
        a[index] = value;
    }

    /*if(a[index]==-1)
    {
        cout<<"Array is empty" << endl;
    }

    else
    {
        while(a[index]!=-1)
        {
            index++;
            if(index==s)
            {
                index=0;
            }
        }
    }*/
}


/*void linearsearchh(int a[], )
{
    if(a[index]==-1)
    {
        cout<<"Array is empty" << endl;
    }

    else
    {
        while(a[index]!=-1)
        {
            index++;
            if(index==s)
            {
                index=0;
            }
        }
    }
}*/


int main()
{
    int n,val,index;
    cout<<"Enter size of your array: ";
    cin>>n;

    int arr[n];

    for(int j=0; j<n; j++)
    {
        arr[j]= NULL;
    }

    while(val != 0)
    {
        cout<<"Enter number: ";
        cin>>val;
        index = ret_index(val,n);
        insertt(arr, index, val, n);
    }



    for(int i=0; i<n; i++)
    {
        cout<<"\nIndex: " << i <<" Value at index: " <<arr[i] << endl;
    }

    int v;
    cout<<"Enter an element to search: ";
    cin>>v;

    //linearsearchh(v);
}
