#include <iostream>
#include <stdlib.h>
#include <queue>

using namespace std;

struct edge
{
  char data;
  edge *connect;
  void *vptr;
  int weight;
  bool inTreeE = false;
};

struct vertex
{
    char var;
    vertex *next;
    edge *beginn;
    bool inTreeV = false;
};


vertex *start= NULL;

void insert_vertex(char v)
{
    vertex *temp= new vertex();
    temp->var= v;
    temp->next= NULL;
    temp->beginn= NULL;
    temp->inTreeV= false;

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



void add_edge(char vS, char vD, int w)
{
    edge *temp = new edge();
    temp->weight=w;

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
		cout << "Vertex " << start->var << "- ";
		curr = start->beginn;

		while (curr != NULL)
		{
			cout << ((vertex*)curr->vptr)->var<< " ";
			cout << curr->weight << " ";
			curr = curr->connect;
		}
		cout << endl;
		start = start->next;
	}
}

void PrimAlgo()
{
        vertex *verptr= start;
        edge *t= NULL;
        verptr->inTreeV= true;
        cout<< verptr->var << endl;
        bool treeComp= false;

        while(treeComp== false)
        {
            treeComp= true;
            vertex *verptrchk = verptr;

            int minedge= 1000;
            edge *minedgeptr= NULL;

            while(verptrchk != NULL)
            {
                if(verptrchk->inTreeV== true)
                {
                    t= verptrchk->beginn;
                    while(t!= NULL)
                    {
                        if(((vertex*)t->vptr)->inTreeV == false)
                        {
                            treeComp= false;
                            if(t->weight < minedge)
                            {
                                minedge= t->weight;
                                minedgeptr= t;
                            }
                        }
                        t= t->connect;
                    }
                }
                verptrchk= verptrchk->next;
            }
            if(minedgeptr!= NULL)
            {
                minedgeptr->inTreeE= true;
                ((vertex*)(minedgeptr->vptr))->inTreeV= true;
            }
        }


        vertex *curr= start;
        edge *currE = NULL;

        while(curr!= NULL)
        {
            currE = curr->beginn;
            while(currE != NULL)
            {
                if(currE->inTreeE ==true)
                {
                    cout<< ((vertex*)(currE->vptr))->var << endl;
                }
                currE= currE->connect;
            }
            curr= curr->next;
        }

}

int main()
{
    insert_vertex('A');
    insert_vertex('B');
    insert_vertex('C');
    insert_vertex('D');
    insert_vertex('E');

    add_edge('A', 'B', 2);
    add_edge('B', 'C', 3);
    add_edge('C', 'D', 4);
    add_edge('D', 'E', 5);
    add_edge('E', 'B', 50);
    //print();
    PrimAlgo();
}
