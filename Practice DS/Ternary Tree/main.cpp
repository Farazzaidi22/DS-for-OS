#include <iostream>
#include <stdlib.h>

using namespace std;

struct TST
{
    int val;
    TST *left;
    TST *center;
    TST *right;
};

TST *root= NULL;

int breaknum(int n,char ch)
{
    int dig;
    dig = n % 10;
    n = n / 10;

    if(ch== 's')
    {
        return n;
    }
    else
    {
        return dig;
    }
}


void insert_In_Tree(int value)
{
    TST *temp= new TST();
    temp->val= value;
    temp->left= NULL;
    temp->center= NULL;
    temp->right= NULL;

    if(root==NULL)
    {
        root= temp;
    }
    else
    {
        TST *curr= root, *t= NULL;
        int dig1,dig2, dig3, dig4;

        while(curr != NULL)
        {
            dig1= breaknum(root->val, 's');
            dig2= breaknum(temp->val, 's');
            dig3= breaknum(root->val, 'f');
            dig4= breaknum(temp->val, 'f');


            if(dig1 > dig2 ||  dig3 > dig4)
            {
                t= curr;
                curr= curr->left;
            }
            else
            {
                if(dig1 == dig2 && dig3 == dig4)
                {
                    t= curr;
                    curr= curr->center;
                }
                else
                {
                    t= curr;
                    curr= curr->right;
                }
            }
        }

        if(dig1 > dig2 ||  dig3 > dig4)
        {
            t->left= temp;
            cout<<"Value " << temp->val <<" on left of " << t->val <<endl;
        }
        else
        {
            if(dig1 == dig2 && dig3 == dig4)
            {
                t->center= temp;
                cout<<"Value " << temp->val <<" in center of " << t->val <<endl;
            }
            else
            {
                t->right= temp;
                cout<<"Value " << temp->val <<" on right of " << t->val <<endl;
            }
        }
    }
}

int main()
{
    /*int num;
    cout<<"Enter your two digit number: ";
    cin>>num;

    int temp1, temp2;
    temp1= breaknum(num);
    cout<<temp1 << endl;*/

    insert_In_Tree(12);
    insert_In_Tree(13);
    insert_In_Tree(11);
    insert_In_Tree(9);
    insert_In_Tree(10);
    insert_In_Tree(15);
    insert_In_Tree(12);
}
