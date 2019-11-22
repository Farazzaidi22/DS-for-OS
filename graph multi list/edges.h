#include <iostream>
using namespace std;
class edges
{
  public:

  edges *link;
  char *data;

   void insert_edge(char *val , edges**start)
    {
        edges *ptr= new edges;
        ptr->data = val;
        ptr->link=NULL;

        if(*start==NULL)
        {
            *start = ptr;
        }
        else
        {
            edges* curr=*start;
            while(curr->link!=NULL)
            {
                curr=curr->link;
            }
                curr->link=ptr;
        }
  }

};
