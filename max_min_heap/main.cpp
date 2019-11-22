#include <iostream>
#include <stdlib.h>

using namespace std;

void swaap(int *x, int *y)
{
    int temp;
    temp= *x;
    *x=*y;
    *y=temp;
}

void maxheap(int a[], int s, int i)
{
    int root=i;
    int l= (2*i+1), r=(2*i+2);

    if(l < s && a[root] < a[l])
    {
        root=l;
    }

    if(r < s && a[root] < a[r])
    {
        root=r;
    }

    if(root!=i)
    {
        swaap(&a[i], &a[root]);
        maxheap(a, s, root);
    }
}

void minheap(int a[], int s, int i)
{
    int root=i;
    int l= (2*i+1), r=(2*i+2);

    if(l < s && a[root] > a[l])
    {
        root=l;
    }
    if(r < s && a[root] > a[r])
    {
        root=r;
    }

    if(root!=i)
    {
        swaap(&a[i], &a[root]);
        minheap(a, s, root);
    }
}

void heapsort(int a[], int s)
{
    for (int i = s / 2 - 1; i >= 0; i--)
        maxheap(a, s, i);

}

void print(int a[],int s)
{
    cout<< endl << endl;
    for(int j=0; j<s; j++)
    {
        cout<<"Element: " << a[j] << " at index: " << j << endl;
    }
}


void del(int Arr[],int s, int val)
{
    int temp;
    temp=Arr[0];
	Arr[0]=Arr[s-1];
	Arr[s-1]=temp;

	s=s-1;
	heapsort(Arr, s);
	cout<<"\nArray After deletion";
	print(Arr,s);

}


int main()
{
    int arr[6];
    for(int i=0; i<6; i++)
    {
        cout<<"Enter element: ";
        cin>>arr[i];
        cout<< "Element: " << arr[i] << " inserted at index: " << i << endl;
    }

    heapsort(arr, 6);

    print(arr,6);
    //del(arr,6, 8);
}
