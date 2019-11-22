#include <iostream>
#include <stdlib.h>
using namespace std;

struct BSTNode
{
    int val;
    BSTNode *left;
    BSTNode *right;
};

void ins(int value, BSTNode **root)
{
    BSTNode *temp= new BSTNode();
    temp->val=value;
    temp->left=NULL;
    temp->right=NULL;

    if(*root == NULL)
    {
        *root=temp;
    }
    else
    {
        BSTNode *curr=*root;
        BSTNode *parent= NULL;

        while(curr!=NULL)
        {
            if(curr->val >= temp->val)
            {
                parent=curr;
                curr= curr->left;
            }
            else
                if(curr->val < temp->val)
                {
                    parent=curr;
                    curr= curr->right;
                }
        }

        if(parent->val >= temp->val)
        {
            parent->left= temp;
            cout<<"Value " << temp->val <<" on left of " << parent->val <<endl;
        }

         if(parent->val < temp->val)
        {
            parent->right= temp;
            cout<<"Value " << temp->val <<" on right of " << parent->val << endl;
        }
    }
}

BSTNode* minValue(BSTNode *root)
{
    while(root->left != NULL)
    {
        root = root->left;
        return root;
    }
}


BSTNode* Del(int val, BSTNode *root)
{
    if(root== NULL)
    {
        return 0;
    }
    else
    {
        if(val < root->val)
        {
            root->left= Del(val, root->left);
        }
        else
        {
            if(val > root->val)
            {
                root->right= Del(val, root->right);
            }
            else
            {
                if(root->left== NULL)
                {
                    BSTNode *temp= root->right;
                    free(root);
                    return temp;
                }
                else
                {
                    if(root->right== NULL)
                    {
                        BSTNode *temp= root->left;
                        free(root);
                        return temp;
                    }
                    BSTNode *temp= minValue(root->right);
                    root->val= temp->val;
                    root->right= Del(temp->val, root->right);
                }
            }
        }
    }
}

void Inorder(BSTNode *root)
{
	if(root == NULL) return;

	Inorder(root->left);       //Visit left subtree
	cout<<root->val; //Print data
	Inorder(root->right);      // Visit right subtree
}

int main()
{
    BSTNode *root= NULL;
    ins(3,&root);
    ins(2,&root);
    ins(4,&root);
    ins(5,&root);
    ins(1,&root);

    Inorder(root);

    Del(2, root);
    cout<< endl;
    Inorder(root);
}
