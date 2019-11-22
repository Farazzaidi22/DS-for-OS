#include <iostream>
#include <stdlib.h>
#include <queue>

using namespace std;

struct BTreeNode
{
    int *keys;
    int degree;
    BTreeNode **childptrs;
    int n;
    bool leaf;
};

struct BTree
{
    BTreeNode *root;
    int degree;
};

BTreeNode* CreateNewNode(int d, bool l)
{
    BTreeNode *temp= new BTreeNode();
    temp->degree=d;
    temp->leaf=l;
    temp->keys= new int[d-1];
    temp->childptrs= new BTreeNode *[d];
    temp->n= 0;
    return temp;
}

BTree* CreateNewTree(int deg)
{
    BTree *temp= new BTree();
    temp->root= NULL;
    temp->degree= deg;
    return temp;
}

BTreeNode* SplitChild(int i, BTreeNode *y, BTreeNode *x)
{
    BTreeNode *temp= CreateNewNode(y->degree, y->leaf); //yahn se leaf true ja raha ha
    temp->n= (x->degree)-1;

    for(int j=0; j<(x->degree)-1; j++)
    {
        temp->keys[j]= y->keys[j+ x->degree];
    }
    if(y->leaf== false)
    {
        for(int j=0; j<x->degree; j++)
        {
            temp->childptrs[j]= y->childptrs[j+ x->degree];
        }
    }
    y->n= (x->degree)-1;

    for(int j=x->n; j>= i+1; j--)
    {
        x->childptrs[j+1]= x->childptrs[j];
    }
    x->childptrs[i+1]= temp;

    for(int j= (x->n)-1; j >= i; j--)
    {
        x->keys[j+1]= x->keys[j];
    }
    x->keys[i]= y->keys[(x->degree)-1];
    x->n = (x->n)+1;

    return x;
}

BTreeNode* InsertNonFull(BTreeNode *ptr, int val)
{
    int i= (ptr->n)-1;
    if(ptr->leaf== true)
    {
        while(i > 0 && ptr->keys[i] > val)
        {
            ptr->keys[i+1] = ptr->keys[i];
            i--;
        }
        ptr->keys[i+1]= val;
        ptr->n= (ptr->n)+1;
    }
    else
    {
        while(i >0 && ptr->keys[i] > val)
        {
            i--;
        }
        if(ptr->childptrs[i+1]->n == (ptr->degree)-1)
        {
            BTreeNode *temo;
            temo=SplitChild(i+1, ptr->childptrs[i+1], ptr->childptrs[i]);
            if(temo->keys[i+1] < val)
            {
                i++;
            }
        }
        InsertNonFull(ptr->childptrs[i+1], val);
    }

    return ptr;
}


void BTreeInsert(BTree *tree, int value)
{
    if(tree->root== NULL)
    {
        tree->root= CreateNewNode(tree->degree, true);
        tree->root->keys[0]= value;
        tree->root->n=1;

        //cout<< " " << tree->root->keys[0];
    }
    else
    {
        if(tree->root->n == (tree->degree)-1)
        {
            BTreeNode *temp= CreateNewNode(tree->degree, false);
            temp->childptrs[0]= tree->root;
            //cout<<" " << tree->root->keys[1];


            BTreeNode *temo, *temp1;
            temo=SplitChild(0, tree->root, temp);

            int i=0;
            if(temo->keys[0] < value)
            {
                i++;
            }
            temp1=InsertNonFull(temo->childptrs[i], value);
            tree->root= temp1;
        }

        else
        {
            InsertNonFull(tree->root, value);
        }
    }
}


void NodePrint(BTreeNode *root)
{
    if (root != NULL)
    {
        NodePrint(root);
    }
}

void print(BTree *t)
{
    int i;
    BTreeNode *temp= t->root;
    for(i=0; i < temp->n; i++)
    {
        if(temp->leaf ==false)
        {
            NodePrint(temp->childptrs[i]);
        }
        cout<< " " << temp->keys[i];
    }
    if(temp->leaf== false)
    {
        NodePrint(temp->childptrs[i]);
    }
}



void searchh(BTree *t, int val)
{
    int i;
    BTreeNode *temp= t->root;
    for(i=0; i < temp->n; i++)
    {
        if(temp->keys[i]==val)
        {
            //NodePrint(temp->childptrs[i]);
            cout<< "\n" << temp->keys[i] << " is present in the tree";
            return;
            break;
        }
    }
    cout <<"\nNumber " << val << " is not present";
}

/*void searchh(BTreeNode *root, int val)
{
    int i=0;
    while(i < root->n && val > root->keys[i])
    {
        i++;
    }
    if(root->keys[i] == val)
    {
        cout<< "\n" << val << " is present in the tree " << endl;
    }
    if(root->leaf == true)
    {
        cout<< "\n" << val << " is not present in the tree " << endl;
    }

    searchh(root->childptrs[i], val);
}*/


int findkey(int val, BTreeNode *root)
{
    int idx=0;
    while(idx < root->n && root->keys[idx] < val)
    {
        ++idx;
    }
    return idx;
}

BTreeNode* RemoveFromLeaf(int val, BTreeNode *root)
{
    for(int i=0; i<root->n; ++i)
    {
        root->keys[i-1] = root->keys[i];
        break;
    }

    (root->n)--;
    return root;
}

int Remove(int val, BTreeNode *root)
{
    int idx= findkey(val, root);
    if(/*idx < root->n &&*/ root->keys[idx]== val)
    {
        if(root->leaf== true)
        {
            BTreeNode* temp;
            temp=RemoveFromLeaf(val, root);
            free(temp);
            cout<<"\nvalue has been deleted";
        }
    }
}

int main()
{
    BTree *tree= CreateNewTree(3);

    BTreeInsert(tree, 10);
    BTreeInsert(tree, 20);
    BTreeInsert(tree, 5);
    BTreeInsert(tree, 6);
    BTreeInsert(tree, 12);
    BTreeInsert(tree, 30);
    BTreeInsert(tree, 7);
    BTreeInsert(tree, 17);

    print(tree);

    searchh(tree, 6);
    searchh(tree, 33);

    /*Remove(17, tree->root);
    cout<< endl;

    print(tree);*/
}
