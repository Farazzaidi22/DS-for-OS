#include <iostream>
#include <stdlib.h>
#include <queue>

using namespace std;

struct node
{
    int val;
    node *child;
    node *sibling;
};

node *root= NULL;

void ins(int value)
{
    node *temp= new node();
    temp->val= value;
    temp->child= NULL;
    temp->sibling= NULL;

    if(root == NULL)
    {
        root= temp;
        cout<<"root made : " << temp->val << endl;
    }
    else
    {
        node *curr= root;
        if(curr->child==NULL)
        {
            curr->child=temp;
            curr->sibling=NULL;
            curr=curr->child;
            cout<<"roots child made : " << temp->val << endl;
        }
        else
        {
            char ch;
            ag:
            cout<<"Enter c for child and s for sibling: ";
            cin>>ch;

            if(ch== 'c')
            {
                while((curr->child) != NULL)
                {
                    curr=curr->child;
                }
                cout<<"child made " << temp->val << " of " << curr->val << endl;
                curr->child= temp;
            }

            else
            {
                if(ch== 's')
                {
                    while((curr->sibling) != NULL)
                    {
                        curr= curr->sibling;
                    }
                    cout<<"sibling made : " << temp->val << " of " << curr->val << endl;
                    curr->sibling= temp;
                }
                else

                {
                    cout<<"wrong input" << endl;
                    goto ag;
                }
            }
        }
    }
}

void print_BF()
{
    if(root== NULL)
    {
        return;
    }
    else
    {
        queue<node*> Q;
        Q.push(root);

        while(!Q.empty())
        {
            node *curr = Q.front();
            cout<<curr->val << " " << endl;

            if(curr->sibling != NULL)
            {
                Q.push(curr->sibling);
            }

            if(curr->child != NULL)
            {
                Q.push(curr->child);
            }

            Q.pop();
        }
    }
}


int main()
{
    ins(3);
    ins(6);
    ins(9);
    ins(12);
    ins(15);
    ins(18);
    ins(21);
    ins(24);
    ins(27);
    ins(30);

    print_BF();
}
