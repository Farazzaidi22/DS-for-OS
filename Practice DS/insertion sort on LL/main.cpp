// C++ implementation for insertion Sort
// on a doubly linked list
#include <bits/stdc++.h>

using namespace std;

// Node of a doubly linked list
struct Node {
	int data;
	struct Node* prev, *next;
};

// function to create and return a new node
// of a doubly linked list
struct Node* getNode(int data)
{
	// allocate node
	struct Node* newNode =
		(struct Node*)malloc(sizeof(struct Node));

	// put in the data
	newNode->data = data;
	newNode->prev = newNode->next = NULL;
	return newNode;
}

// function to insert a new node in sorted way in
// a sorted doubly linked list
void sortedInsert(struct Node** head_ref, struct Node* newNode)
{
	struct Node* current;

	// if list is empty
	if (*head_ref == NULL)
		*head_ref = newNode;

	// if the node is to be inserted at the beginning
	// of the doubly linked list
	else if ((*head_ref)->data >= newNode->data) {
		newNode->next = *head_ref;
		newNode->next->prev = newNode;
		*head_ref = newNode;
	}

	else {
		current = *head_ref;

		// locate the node after which the new node
		// is to be inserted
		while (current->next != NULL &&
			current->next->data < newNode->data)
			current = current->next;

		/*Make the appropriate links */

		newNode->next = current->next;

		// if the new node is not inserted
		// at the end of the list
		if (current->next != NULL)
			newNode->next->prev = newNode;

		current->next = newNode;
		newNode->prev = current;
	}
}

// function to sort a doubly linked list using insertion sort
void insertionSort(struct Node** head_ref)
{
	// Initialize 'sorted' - a sorted doubly linked list
	struct Node* sorted = NULL;

	// Traverse the given doubly linked list and
	// insert every node to 'sorted'
	struct Node* current = *head_ref;
	while (current != NULL) {

		// Store next for next iteration
		struct Node* next = current->next;

		// removing all the links so as to create 'current'
		// as a new node for insertion
		current->prev = current->next = NULL;

		// insert current in 'sorted' doubly linked list
		sortedInsert(&sorted, current);

		// Update current
		current = next;
	}

	// Update head_ref to point to sorted doubly linked list
	*head_ref = sorted;
}

// function to print the doubly linked list
void printList(struct Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

// function to insert a node at the beginning of
// the doubly linked list
void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node =
		(struct Node*)malloc(sizeof(struct Node));

	/* put in the data */
	new_node->data = new_data;

	/* Make next of new node as head and previous as NULL */
	new_node->next = (*head_ref);
	new_node->prev = NULL;

	/* change prev of head node to new node */
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

// Driver program to test above
int main()
{
	/* start with the empty doubly linked list */
	struct Node* head = NULL;

	// insert the following data
	push(&head, 9);
	push(&head, 3);
	push(&head, 5);
	push(&head, 10);
	push(&head, 12);
	push(&head, 8);

	cout << "Doubly Linked List Before Sortingn";
	printList(head);

	insertionSort(&head);

	cout << "nDoubly Linked List After Sortingn";
	printList(head);

	return 0;
}





/*#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    int value;
    Node *next;
};

Node *start;


void swapp(Node *a, Node *b)
{
    Node *temp;
    temp->value=a->value;
    a->value=b->value;
    b->value=temp->value;
}

void insertt(int x)
{
    Node *temp = new Node();
    temp->value = x;
    temp->next = NULL;

    if(start== NULL)
    {
        start= temp;
    }
    else
    {
        Node *curr = start;
        while(curr->next!=NULL && curr->value > curr->next->value)
        {
            swapp(curr, curr->next);
            curr=curr->next;
        }
        curr->next= temp;
    }
}

void print()
{
    Node *temp = start;
    cout<<"The current list is";
    while(temp != NULL)
    {
        cout<<"\nThe value is: " << temp->value ;
        temp = temp-> next;
    }
    cout<<"\n" << endl;
}


int main()
{
    int num, sizee;
    cout<<"Enter number of elements you want in the list: ";
    cin>>sizee;

    for(int i=0; i<sizee; i++)
    {
        cout<<"\nEnter number: ";
        cin>>num;
        insertt(num);
    }

    print();
}*/
