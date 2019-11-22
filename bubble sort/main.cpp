#include <iostream>
#include<stdlib.h>

using namespace std;

void swaap(int *x, int *y)
{
    int temp;
    temp= *x;
    *x=*y;
    *y=temp;
}

void bubblesort(int a[], int n)
{
    for(int i=0; i <n-1; i++)
    {
        for(int j=0; j< (n-i-1); j++)
        {
            if(a[j] > a[j+1])
            {
                swaap(&a[j], &a[j+1]);
            }
        }
    }


    cout<< "sorted array " << endl;
    for(int k=0; k<n; k++)
    {
        cout<< "element at " << k << ": " << a[k] << endl;
    }
}


int main()
{
    int n;
    cout<<"Enter number of elements you want in your array: " ;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++)
    {
        cout<<"Enter number: ";
        cin>>arr[i];
    }

    //int *ptr = arr[n];
    bubblesort(arr, n);
}
