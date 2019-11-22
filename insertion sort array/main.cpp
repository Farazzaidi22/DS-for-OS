#include <iostream>
#include <stdlib.h>
using namespace std;

void insertionsort(int arr[],int n)
{
    int hold,j;
    for(int i=1; i<n; i++)
    {
        hold=arr[i];
        j=i;

        while(hold < arr[j-1])
        {
            arr[j] = arr[j-1];
            j--;

            if((j-1) < 0)
            {
                break;
            }
        }

        arr[j]= hold;
    }

    for(int k=0; k< n; k++)
    {
        cout<<"sorted at " << k << ": " << arr[k] << endl;
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

    insertionsort(arr,n);
}
