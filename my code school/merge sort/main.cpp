#include <iostream>

using namespace std;

void inputarray(int a[],int s);
void printarray(int a[],int s);
void mergsort(int a[],int n);
void Merge(int l[],int nl, int r[],int nr, int a[],int na);


int main()
{

    int s;
    cout<<"Enter size of array: ";
    cin>>s;

    int a[s];
    inputarray(a,s);

    mergsort(a,s);
    printarray(a,s);
}

void inputarray(int a[],int s)
{
     for(int i=0; i<s; i++)
    {
        cout<<"\nEnter element: ";
        cin>>a[i];
    }
}

void printarray(int a[],int s)
{
    for(int i=0; i<s; i++)
    {
        cout<<"Array[" <<i <<"] : " <<a[i] << endl;
    }
}


void mergsort(int a[],int n)
{

    while(n < 2)
    {
        int mid;
        mid=n/2;

        int left[mid],right[n-mid];

        for(int i=0; i<mid-1; i++)
        {
            left[i]= a[i];
        }

        for(int j=mid; j<(n-1); j++)
        {
            right[j-mid]= a[j];
        }

        mergsort(left, mid);
        mergsort(right,(n-mid));

        int temp1= mid;
        int temp2= n-mid;

        Merge(left,temp1, right,temp2, a,n);
    }

}

void Merge(int l[],int nl, int r[],int nr, int a[],int na)
{
    int i, j, k; //for holding values of left, right and final array respectively

    while(i < nl && j < nr)
    {
        if(l[i] <= r[j])
        {
            a[k]=l[i];
            i++;
        }
        else
        {
            a[k]=r[j];
            j++;
        }

        k=k+1;
    }

    while(i<nl)
    {
        a[k]=l[i];
        i++;
        k++;
    }

     while(j<nr)
    {
        a[k]=r[j];
        j++;
        k++;
    }
}
