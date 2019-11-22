#include<iostream>
using namespace std;
#include "edges.h"
class
    vertex{
        public:
            char data;
            vertex *next;
            edges *start;

        void insert_vertex(char val,vertex **start)
        {
            vertex *ptr=new vertex;
            ptr->data=val;
            ptr->next=NULL;
            ptr->start=NULL;

            if(*start==NULL)
            {
                *start=ptr;
            }
            else
            {
                vertex *temp=*start;
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                    temp->next=ptr;
            }
        }

        vertex* search(char val,vertex *start)
        {
            vertex* temp=start;
            while(temp->data!=val)
            {
                temp=temp->next;
            }
            return temp;
        }

        void insert_edge(char ver , char edge  ,vertex *start)
        {
            vertex  *node = search(ver,start);
            vertex* curr=start;
            while(curr->data!=edge)
            {
                curr=curr->next;
            }
            edges a;
            a.insert_edge(&curr->data ,&(node->start));
        }

        void print(vertex *v)
        {
            if(v!=NULL)
            {
                edges *temp=v->start;
                cout<<  endl;
                cout<<"Vertex : "<<v->data<<endl ;

                while(temp!=NULL)
                {
                    cout<<"Is connected to: "<<*temp->data << " ";
                    temp=temp->link;
                }
                cout<<endl;
                print(v->next);

            }
        }

};
