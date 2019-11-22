#include<iostream>
using namespace std;
#include"vertex.h"
int main()
{
  vertex *start=NULL;
  vertex v;

    v.insert_vertex('A',&start);
    v.insert_vertex('B',&start);
    v.insert_vertex('C',&start);
    v.insert_vertex('D',&start);
    v.insert_vertex('E',&start);
    v.insert_vertex('F',&start);

  v.insert_edge('A' , 'B' , start);
  v.insert_edge('B' , 'C' , start);

  v.insert_edge('C' , 'D' , start);
  v.insert_edge('D' , 'E' , start);
  v.insert_edge('E' , 'F' , start);
  v.insert_edge('F' , 'F' , start);


  v.print(start);
}
