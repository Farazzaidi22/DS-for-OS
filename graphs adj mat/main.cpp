#include <iostream>
#include <stdlib.h>
using namespace std;


struct graph
{
    int vertex;
    int edge;
    int **mat; //pointer for 2d array
};

int Stack[100],top=-1;

int search_index(char vertices[],char x,int v)
{
    int i;
    for( i=0;i<v;i++)
    {
        if(vertices[i]==x)
        {
            break;
        }
    }
    return i;
}

bool visited(int index)
{
	for (int i = 0; i < 100; i++)
		if (Stack[i] == index)
        {
            return true;
        }
        else
        {
            return false;
        }
}

void outdegree(graph **arr,char vertices[],int v)
{
    int vertex=0,c=0;
    char x;
    cout << "Enter Vertex For OutDegree: " << endl;
    cin >> x;
    vertex = search_index(vertices,x,v);
    cout << vertex << endl;
    graph *temp = *arr;
    for (int i=0;i<v;i++)
    {
        if(temp->mat[vertex][i]==1)
        {
            c++;
        }
    }
    cout << "Outdegree Of " << x << " is " << c << endl;
}

bool path(char vertices[],graph **arr,int v)
{
    graph *temp = *arr;
    char s,d;
    cout << "Enter Source And Destination: " << endl;
    cin >> s;
    cin >> d;
    int a,b,flag=0;
    a= search_index(vertices,s,v);
    b = search_index(vertices,d,v);
    while(temp->mat[a][b]!=1 &&  flag < 30)
    {
        for(int i=0;i<v;i++)
        {
            if(temp->mat[a][i]== 1 && !visited(i))
            {
                top++;
                Stack[top]=i;
                visited(vertices[i]);
                a=i;
                break;
            }
        }
        flag++;
    }
    if(flag< 30)
    {
        return true;
    }
    else
    {
        return false;
    }


}

graph* adjmatrix(int v,int e)
{
    //int v,e;
    //graph G = (graph*)malloc(sizeof(graph));
    graph *G= new graph();
    //cout << "Enter NO. Of Vertices And Edges: " << endl;
    //cin >> v;
    //cin >> e;
    G->vertex= v;
    G->edge=e;
    //G->vertex = v;
    //G->mat=(int**)malloc(sizeof(int)*(v*v));
    //G->mat=malloc(sizeof(int)*(G->vertex*G->vertex));
    G->mat=(int**)malloc(v*sizeof(int*));
    for(int i=0;i<v;i++)
    {
        G->mat[i]=(int*)malloc(v*sizeof(int));
    }

    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            G->mat[i][j]=0;
        }
    }
    for(int k=0;k<e;k++)
    {
        int u,v;
        cout << "Enter Vertices that connect Edge no " << k << endl;
        cin >> u;
        cin >> v;
        G->mat[u][v]=1;
        //G->mat[v][u]=1;
    }
    return (G);
}

void printmat(graph **arr,char vertices[],int v)
{
    graph *a= *arr;
    cout << "Undirected Adjacency Matrix: "<< endl <<endl;

	for (int i = 0; i < v; i++)
    {
		cout <<  vertices[i] << "   ";
    }
	cout << endl;
    for(int i=0;i<a->vertex;i++)
    {
        for (int j=0;j<a->vertex;j++)
        {
            cout << a->mat[i][j] << "   ";
        }
        cout << endl;
    }
}

graph* add_edge(graph **arr,char x)
{
    char choice=x;
    graph *temp=*arr;
    int v1,v2;
    cout << "Enter Vertices in which You want to add an edge: " << endl;
    cin >> v1;
    cin >> v2;
    temp->mat[v1][v2];
    /*if(choice=='U' || choice=='u')
    {
    temp->mat[v1][v2]=1;
    temp->mat[v2][v1]=1;
    }
    else
    {
        temp->mat[v1][v2]=1;
    }*/
    return temp;
}

/*graph* add_vertex(graph **arr)
{
    graph *temp=*arr;

}
*/
int main()
{
    //char choice;
    //cout << "For Undirected Press U or u"<< endl;
    //cin >> choice;
    graph *a;
    cout << "Enter NO. Of Vertices And Edges: " << endl;
    int v,e;
    cin >> v;
    cin >> e;
    char Vertices[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M' };
    a = adjmatrix(v,e);
    printmat(&a,Vertices,v);
    //a = add_edge(&a,choice);
    //printmat(&a,Vertices,v);
    if(path(Vertices,&a,v)==true)
    {
        cout << "Path Exist" << endl;
    }
    else
    {
        cout << "No Path" << endl;
    }
    outdegree(&a,Vertices,v);
    outdegree(&a,Vertices,v);
    outdegree(&a,Vertices,v);
    outdegree(&a,Vertices,v);
}
