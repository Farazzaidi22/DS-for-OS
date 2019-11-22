#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;

struct BST
{
    int val;
    BST *left;
    BST *right;
};

void insert_BST(int value, BST **root)
{
    BST *temp = new BST();
    temp->val= value;
    temp->left= NULL;
    temp->right= NULL;

    if(*root== NULL)
    {
        *root= temp;
    }
    else
    {
       BST *curr =*root, *parent= NULL;
       while(curr != NULL)
       {
           if(curr->val >= temp->val)
           {
               parent= curr;
               curr= curr->left;
               //cout<<"amil";
           }
           else
           {
               if(curr->val < temp->val)
               {
                   parent= curr;
                   curr= curr->right;
                   //cout<<"amil";
               }
           }
       }

       if(parent->val >= temp->val)
       {
           parent->left= temp;
           //cout<<"amil";
       }
       else
       {
           if(parent->val < temp->val)
           {
               parent->right= temp;
               //cout<<"amil";
           }
       }
    }
}

void print_inorder(BST *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        print_inorder(root->left);       //Visit left subtree
        cout<< root->val << " ";         //Print data
        print_inorder(root->right);      // Visit right subtree
    }
}


struct node
{
    int value;
    node *next;
};


void insertt(int x, node **start)
{
    node *temp = new node();
    temp->value = x;
    temp->next = NULL;

    if(*start== NULL)
    {
        *start= temp;
    }
    else
    {
        node *curr = *start;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next= temp;
    }
}

void print(node *start)
{
    node *temp = start;
    cout<<"The current list is";
    while(temp != NULL)
    {
        cout<<"\nThe value is: " << temp->value ;
        temp = temp-> next;
    }
    cout<<"\n" << endl;
}

void flatten(BST *root, node **start)
{
    if(root==NULL)
    {
        return;
    }
    flatten(root->left, *&start);
    insertt(root->val, *&start);
    flatten(root->right, *&start);
}

int main()
{
    BST *root= NULL;
    insert_BST(4,&root);
    insert_BST(5,&root);
    insert_BST(1,&root);
    insert_BST(2,&root);
    insert_BST(3,&root);
    insert_BST(6,&root);

    print_inorder(root);

    node *start= NULL;

    flatten(root, &start);
    print(start);
}
