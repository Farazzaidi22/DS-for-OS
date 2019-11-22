#include <iostream>

using namespace std;

int index(int s, int val);
void linearinsertt(int arr[], int s, int val, int index);

int main()
{
    int s;
    cout<<"\nEnter size of your array: ";
    cin>>s;

    int a[s];

    for(int i=0; i<s; i++)
    {
        a[i]= 0;
    }

    int value=1,temp;
    while(value != 0)
    {
        cout<<"Enter value: ";
        cin>>value;

        if(value== 0)
        {
            break;
        }

        temp=index(s, value);
        linearinsertt(a, s, value, temp);
    }

    for(int j=0; j<s; j++)
    {
        cout<<"\nIndex: " << j <<" Value at index: " <<a[j] << endl;
    }
}

int index(int s, int val)
{
    int rem;
    rem= val%s;
    return rem;
}


void linearinsertt(int arr[], int s, int val, int index)
{
    int temp=index;
    if(arr[temp]== 0)
    {
        arr[temp]= val;
        return;
    }

    else
        if(arr[temp] != 0)
    {
        temp++;
        if(temp >= s)
        {
            temp=0;
            linearinsertt(arr, s, temp, index);
            return;
        }
        linearinsertt(arr, s, temp, index);
        return;
    }
}
