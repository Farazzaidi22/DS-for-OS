#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <queue>
#include <stack>

using namespace std;

struct edge
{
  char data;
  edge *connect;
  void *vptr;
};

struct vertex
{
    char var;
    vertex *next;
    edge *beginn;
    bool status = false;
};


vertex *start= NULL;

void insert_vertex(char v)
{
    vertex *temp= new vertex();
    temp->var= v;
    temp->next= NULL;
    temp->beginn= NULL;
    temp->status= false;

    if(start== NULL)
    {
        start= temp;
    }
    else
    {
        vertex *curr= start;
        while(curr->next!= NULL)
        {
            curr = curr->next;
        }
        curr->next= temp;
    }
}


vertex* searchh(char v)
{
    vertex *temp = start;
    while(temp->var!= v)
    {
        temp= temp->next;
    }
    return temp;
}



void add_edge(char vS, char vD)
{
    edge *temp = new edge();

    vertex *source= searchh(vS);
    //cout<<"source " << source->var;

    temp->vptr= searchh(vD);
    //cout<<" temp->vptr " << temp->vptr;

    temp->connect= NULL;


    if(source->beginn== NULL)
    {
        source->beginn = temp;
    }
    else
    {
        edge *curr = source->beginn;
        while(curr->connect != NULL)
        {
            curr= curr->connect;
        }
        curr->connect= temp;
    }
}

void print()
{
	edge *curr;
	while (start != NULL)
	{
		cout << "Vertex " << start->var << "-->";
		curr = start->beginn;

		while (curr != NULL)
		{
			cout << ((vertex*)curr->vptr)->var<< " ";
			curr = curr->connect;
		}
		cout << endl;
		start = start->next;
	}
}

void BFS()
{
    vertex *ver= start;
    if(ver== NULL)
    {
        return;
    }
    else
    {
        queue<vertex*> Q;
        Q.push(ver);
        ver->status= true;

        while(!Q.empty())
        {
            ver = Q.front();
            cout<< ver->var << " ";
            Q.pop();

            edge *temp= ver->beginn;
            while(temp!= NULL)
            {
                if((((vertex*)(temp->vptr))->status == false))
                {
                    Q.push((vertex*)(temp->vptr));
                    ((vertex*)(temp->vptr))->status= true;
                }
                temp= temp->connect;
            }
        }
    }
}


void DFS()
{
    vertex *ver= start;
    if(ver== NULL)
    {
        return;
    }
    else
    {
        stack<vertex*> S;
        S.push(ver);
        ver->status= true;

        while(!S.empty())
        {
            ver = S.top();
            cout<< ver->var << " ";
            S.pop();

            edge *temp= ver->beginn;
            while(temp!= NULL)
            {
                if((((vertex*)(temp->vptr))->status == false))
                {
                    S.push((vertex*)(temp->vptr));
                    ((vertex*)(temp->vptr))->status= true;
                }
                temp= temp->connect;
            }
        }
    }
}

int outdegree(char v)
{
    if(searchh(v)!= NULL)
    {
        edge *temp= searchh(v)->beginn;
        int deg=0;
        while(temp!= NULL)
        {
            deg++;
            temp= temp->connect;
        }
        return deg;
    }
    else
    {
        cout<<"\nOut degree of is zero";
    }
}

int Indegree(char v)
{
    if(searchh(v)!= NULL)
    {
        edge *temp;
        int deg=0;

        while(start!= NULL)
        {
            temp= start->beginn;
            while(temp!= NULL)
            {
                if(((vertex*)(temp->vptr))->var== v)
                {
                    deg++;
                }
                temp= temp->connect;
            }
            start= start->next;
        }
        return deg;
    }
}


void Path(char S, char D)
{
    vertex *s= searchh(S);
    vertex *d= searchh(D);

	s->status = true;
	if (s == d)
	{
        cout << " Exists ";
		cout << endl;
	}
	else
	{
		edge* CurrentEdge = s->beginn;
		while (CurrentEdge != NULL)
		{
			if (((vertex*)CurrentEdge->vptr)->status == false)
			{
			    cout<<((vertex*)CurrentEdge->vptr)->var << " ";
				Path(((vertex*)CurrentEdge->vptr)->var, d->var);
			}
			CurrentEdge = CurrentEdge->connect;
		}
	}
}

int main()
{
    /*insert_vertex('A');
    insert_vertex('B');
    insert_vertex('C');
    insert_vertex('D');
    insert_vertex('E');
    insert_vertex('F');
    insert_vertex('G');
    insert_vertex('H');
    insert_vertex('I');
    insert_vertex('J');
    insert_vertex('K');
    insert_vertex('L');
    insert_vertex('M');
    insert_vertex('N');



    add_edge('A', 'B');
    add_edge('A', 'C');
    add_edge('A', 'E');
    add_edge('B', 'H');
    add_edge('B', 'I');
    add_edge('C', 'D');
    add_edge('C', 'A');
    add_edge('D', 'E');
    add_edge('D', 'C');
    add_edge('E', 'A');
    add_edge('E', 'D');
    add_edge('E', 'F');
    add_edge('F', 'E');
    add_edge('F', 'G');
    add_edge('G', 'F');
    add_edge('G', 'H');
    add_edge('H', 'B');
    add_edge('H', 'G');
    add_edge('I', 'B');
    add_edge('I', 'J');
    add_edge('J', 'I');
    add_edge('J', 'K');
    add_edge('K', 'J');
    add_edge('K', 'M');
    add_edge('K', 'L');
    add_edge('K', 'N');
    add_edge('M', 'K');
    add_edge('L', 'K');
    add_edge('L', 'N');
    add_edge('N', 'L');*/



    insert_vertex('A');
    insert_vertex('B');
    insert_vertex('C');
    insert_vertex('D');
    insert_vertex('E');
    insert_vertex('F');
    insert_vertex('G');
    insert_vertex('H');

    add_edge('A','B');
    add_edge('A','C');
    add_edge('A','D');

    add_edge('B','C');
    add_edge('B','E');

    add_edge('C','E');

    add_edge('D','C');
    add_edge('D','F');

    add_edge('E','A');

    add_edge('F','C');

    add_edge('G','D');
    add_edge('G','F');
    add_edge('G','H');

    add_edge('H','C');

    //print();

    //BFS();
    /*int d;
    d=outdegree('A');
    cout<<"\nOut degree is " << d;

    int din;
    din=Indegree('A');
    cout<<"\nIn degree is " << din;*/

    cout<< endl;
    DFS();

    //Path('A', 'G');


}
