#include <iostream>

using namespace std;

void inputarray(int a[],int s);
void printarray(int a[],int s);
void swaparray(int *a,int *arr);
void selectionsort(int a[],int s);
void binarysearch(int a[], int start, int endd, int val);

int main()
{
    int s;
    cout<<"Enter size of array: ";
    cin>>s;

    int a[s];
    inputarray(a,s);

    selectionsort(a,s);
    printarray(a,s);

    int value, start=0, endd=(s-1);
    cout<<"\nEnter a value to search: ";
    cin>>value;

    binarysearch(a, start, endd, value);
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

void swaparray(int *a,int *arr)
{
    int temp;
    temp = *a;
    *a = *arr;
    *arr = temp;
}


void selectionsort(int a[],int n)
{
    int minn,i,j;
    for(i=0; i< n-1; i++)
    {
        minn=i;
        for(j=i+1; j<n; j++)
        {
            if(a[j] < a[minn])
            {
                minn=j;
            }
        }
        swaparray(&a[minn], &a[i]);
    }
}

void binarysearch(int a[], int start, int endd, int val)
{
    int mid;

    if(start <= endd)
    {
        mid= (start + endd)/2;

        if(a[mid] == val)
        {
            cout<<"\nValue " << val <<" is present at index a[" <<mid <<"]";
        }
        else
        {
            if(a[mid] > val)
            {
                binarysearch(a, start, mid-1, val);
            }

            else
            {
                if(a[mid] < val)
                {
                    binarysearch(a, mid+1, endd, val);
                }

                else
                {
                    cout<<"\nValue is not present in the given array :)" << endl;
                }
            }
        }
    }
}
