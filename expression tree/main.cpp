#include<iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct StackNode
{
	char Operator;
	StackNode *Next;
};

struct TreeNode
{
	char Data;
	TreeNode* Left = NULL;
	TreeNode* Right = NULL;
};

void Push(StackNode **Top, char op)
{
	StackNode * NewStackNode;

	NewStackNode = new StackNode;
	NewStackNode->Operator = op;

	NewStackNode->Next = *Top;
	*Top = NewStackNode;
}

char Pop(StackNode **Top)
{
	if (Top != NULL)
	{
		char Pop = (*Top)->Operator;
		StackNode * OldTop = *Top;

		*Top = (*Top)->Next;

		delete OldTop;
		OldTop = NULL;
		return Pop;
	}
	else
	{
		cout << "Stack Is Empty : "; return NULL;
	}
}

char Peek(StackNode * Top)
{
	if (Top != NULL) return Top->Operator;
	else return 'E';
}

void Delete(StackNode **Top)
{
	if (*Top != NULL)
	{
		StackNode * OldTop = *Top;
		*Top = (*Top)->Next;

		delete OldTop;
		OldTop = NULL;
	}
}

void Find(StackNode * Current, char val)
{
	if (Current != NULL)
	{
		int Found = 0;
		while (Current != NULL)
		{
			if (Current->Operator == val) Found++;
		}
		(Found == 0) ? cout << "Not Found" << endl : cout << "Found " << Found << " Item" << endl;
	}
}

void Clear(StackNode **Top)
{
	StackNode * Current;
	while (*Top != NULL)
	{
		Current = *Top;
		*Top = (*Top)->Next;
		delete Current;
	}
}

bool IsEmpty(StackNode * Top)
{
	if (Top == NULL) return true;
	else return false;
}

void Show(StackNode*Current)
{
	cout << "Stack : ";
	while (Current != NULL)
	{
		cout << " " << Current->Operator;
		Current = Current->Next;
	}
	cout << endl;
}

int Priority(char x)
{
	if (x == '|')
		return 0;
	else if (x == '&')
		return 1;
	else if (x == '=' || x == '!')
		return 2;
	else if (x == '<' || x == '>')
		return 3;
	else if (x == '+' || x == '-')
		return 4;
	else if (x == '*' || x == '/' || x == '%')
		return 5;
	else
		return -1;

}

char* ToPostfix(char Infix[], StackNode** Top)
{
	int Length = strlen(Infix);

	char* Postfix = new char[Length]; int Pi = 0;

	for (int i = 0; i<Length; i++)
	{
		if ((Infix[i] >= 'a' && Infix[i] <= 'z') || (Infix[i] >= 'A' && Infix[i] <= 'Z'))
		{
			Postfix[Pi] = Infix[i];
			Pi++;
		}
		else if (Infix[i] == '(')
		{
			Push(Top, Infix[i]);
		}
		else if (Infix[i] == ')')
		{
			char Operators;
			while ((Operators = Pop(Top)) != '(')
			{
				Postfix[Pi] = Operators;
				Pi++;
			}
		}
		else
		{
			while ((Priority(Peek(*Top)) >= (Priority(Infix[i]))))
			{
				Postfix[Pi] = Pop(Top);
				Pi++;
			}
			Push(Top, Infix[i]);
		}
	}
	while (*Top != NULL)
	{
		Postfix[Pi] = Pop(Top);
		Pi++;
	}

	Postfix[Pi] = '\0';
	return Postfix;
}

void PreOrder(TreeNode* Root)
{
	if (Root != NULL)
	{
		cout << Root->Data << " ";
		PreOrder(Root->Left);
		PreOrder(Root->Right);
	}
}

void InOrder(TreeNode* Root)
{
	if (Root != NULL)
	{
		InOrder(Root->Left);
		cout << Root->Data << " ";
		InOrder(Root->Right);
	}
}

void PostOrder(TreeNode* Root)
{
	if (Root != NULL)
	{
		PostOrder(Root->Left);
		PostOrder(Root->Right);
		cout << Root->Data << " ";
	}
}

TreeNode* CreateTree(char* Postfix)
{
	int Length = strlen(Postfix);
	TreeNode** T = new  TreeNode*[Length]; int Ti = 0;
	TreeNode* NewNode;

	for (int i = 0; i<Length; i++)
	{
		if ((Postfix[i] >= 'a' && Postfix[i] <= 'z') || (Postfix[i] >= 'A' && Postfix[i] <= 'Z'))
		{
			NewNode = new TreeNode;
			NewNode->Data = Postfix[i];
			T[Ti] = NewNode;
			Ti++;
		}
		else
		{
			NewNode = new TreeNode;
			NewNode->Data = Postfix[i];
			NewNode->Right = T[Ti - 1];
			NewNode->Left = T[Ti - 2];
			Ti = Ti - 2;
			T[Ti] = NewNode;
			Ti++;
		}

	}

	TreeNode* ret = T[0];

		delete T; T = NULL;
	return ret;
}

int Evaluation()
{
	int a = 1, b = 2, c = 3, d = 0, e = 0, f = 0;
	char Postfix[] = { 'a','b','c','*','+' };
	int ans[5], index = 0;
	for (int i = 0; i<5; i++)
	{
		cout << Postfix[i];
		if ((Postfix[i] >= 'a' && Postfix[i] <= 'z') || (Postfix[i] >= 'A' && Postfix[i] <= 'Z'))
		{

			cout << "IF" << endl;
			switch (Postfix[i])
			{

			case 'a':
				ans[index] = a;
				index++;
				break;
			case 'b':
				ans[index] = b;
				index++;
				break;
			case 'c':
				ans[index] = c;
				index++;
				break;
			case 'd':
				ans[index] = d;
				index++;
				break;
			case 'e':
				ans[index] = e;
				index++;
				break;
			case 'f':
				ans[index] = f;
				index++;
				break;
			default:
				cout << "Unknown";
			}
			cout << ans[index - 1] << endl;
		}
		else
		{
			cout << "else" << endl;
			int a = ans[index - 2], b = ans[index - 1];
			cout << "a=" << a << " b=" << b << endl;
			switch (Postfix[i])
			{
			case '*':
				ans[index - 2] = a * b;
				index--;
				break;
			case '/':
				ans[index - 2] = a / b;
				index--;
				break;
			case '+':
				ans[index - 2] = a + b;
				index--;
				break;
			case '-':
				ans[index - 2] = a - b;
				index--;
				break;
			case '<':
				ans[index - 2] = a < b;
				index--;
				break;
			case '>':
				ans[index - 2] = a > b;
				index--;
				break;
			default:
				cout << "Unknown";
			}
		}
	}
	return ans[0];
}

char* ToPrefix(char Infix[], StackNode** Top)
{
	int Length = strlen(Infix);

	char* Postfix = new char[Length]; int
		Pi = 0;

	for (int i = 0; i<Length; i++)
	{
		if ((Infix[i] >= 'a' && Infix[i] <= 'z') || (Infix[i] >= 'A' && Infix[i] <= 'Z'))
		{
			Postfix[Pi] = Infix[i];
			Pi++;
		}
		else if (Infix[i] == '(')
		{
			Push(Top, Infix[i]);
		}
		else if (Infix[i] == ')')
		{
			char Operators;
			while ((Operators = Pop(Top)) != '(')
			{
				Postfix[Pi] = Operators;
				Pi++;
			}
		}
		else
		{
			while ((Priority(Peek(*Top)) >= (Priority(Infix[i]))))
			{
				Postfix[Pi] = Pop(Top);
				Pi++;
			}
			Push(Top, Infix[i]);
		}
	}
	while (*Top != NULL)
	{
		Postfix[Pi] = Pop(Top);
		Pi++;
	}

	Postfix[Pi] = '\0';
	return Postfix;
}

int main()
{
	StackNode *Top = NULL;

	char Infix[] = "(a+b*(b*c)/d-(a+b))<(x+y)&c!e+b";
	int Length = strlen(Infix);

	char *Postfix = ToPostfix(Infix, &Top);
	char *P = Postfix;

	cout << "Infix   : ";
	for (int i = 0; i < Length; i++)
		cout << Infix[i] << " ";

	cout << endl << "Postfix : ";
	while (*P != '\0')
	{
		cout << *P << " ";
		P++;
	}

	TreeNode* Root = CreateTree(Postfix);

	cout << endl << endl << "Pre Order Traversal  : ";
	PreOrder(Root);
	cout << endl << "In Order Traversal   : ";
	InOrder(Root);
	cout << endl << "Post Order Traversal : ";
	PostOrder(Root);

	free(Postfix); //Postfix = NULL;

	cout << endl;
}



/*#include <iostream>
#include <stdlib.h>
#include <stack>
using namespace std;

struct node
{
    char val;
    node *left;
    node *right;
};

node *root=NULL;

node* newnode(char value)
{
    node *temp= new node();
    temp->val=value;
    temp->left=NULL;
    temp->right=NULL;

    return temp;
}


char operatorr(char ch)
{
    return (ch == '/' || ch=='*' || ch=='+' || ch=='-');
}

char operand(char op)
{
    return ((op >= 'a' && op <= 'z') || (op >= 'A' && op <= 'Z') || (op >= 'A' && op <= 'Z'));
}


node*  expressiontree(char postfix[])
{
    stack<node*> n;

    node *temp, *temp1, *temp2;

    for(int i=0; i<=5; i++)
    {
        if(operand(i))
        {
            cout<<"amil";
            temp=newnode(postfix[i]);
            cout<<"amil";
            n.push(temp);
            cout<<"amil";
        }
        else
        {
            cout<<"amil";
            temp= newnode(postfix[i]);

            temp1= n.top();
            n.pop();

            cout<<"amil";

            temp2= n.top();
            n.pop();

            temp->right= temp2;
            temp->left= temp1;

            n.push(temp);

        }

    }

    temp= n.top();
    n.pop();
    cout<<"amil";

    return temp;
}


int main()
{
    char postfix[]= "ac*b+";

    node *t;
    t= expressiontree(postfix);
}*/
