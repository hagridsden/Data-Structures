#include <stdio.h>
#include <stdlib.h>

typedef struct EdgeTag
{
        char name;
        struct EdgeTag * connectsTo;
}EdgeTag;

typedef struct VertexTag
{
    char Vname;
    int num_members;
    EdgeTag * head;
}VertexTag;

typedef struct Graph
{
        int v;
        VertexTag * array;
}Graph;

void GraphCreate(Graph *G, int vert)
{
    G->v = vert;
    G->array = (VertexTag *)malloc(vert*sizeof(VertexTag));
    for(int i =0;i<vert;i++)
        G->array[i].head=NULL;
}

void GraphAddVertex(Graph * G)
{
    G->array = realloc(G->array, G->v+sizeof(VertexTag));
}

void GraphAddEdge(Graph * G,char c, char dst)
{    
    int src = c-65;
    
    if(G->array[src].head==NULL)   //first edge
      {
            G->array[src].Vname = c;
            G->array[src].num_members = 1;
            G->array[src].head = (EdgeTag *) malloc(sizeof(EdgeTag));
            G->array[src].head->name = dst;
            G->array[src].head->connectsTo = NULL;
      }
        
    else    //insert at head
      { 
            EdgeTag * ptr = (EdgeTag *) malloc(sizeof(EdgeTag));
            ptr->connectsTo = G->array[src].head;
            ptr->name = dst;
            G->array[src].head = ptr;            
            ptr = NULL;
            G->array[src].num_members++;
      //      printf("%d ",G->array[src].num_members);
      }        
}

void GraphPrint(Graph * G)
{
        printf("%d",G->v);

        EdgeTag * ptr2;
        int i, j;
        for(i =0; i< (int) (G->v);i++)
        {
            printf("\n%c : ",G->array[i].Vname);
           for(j=0, ptr2 = G->array[i].head ; j< (int) G->array[i].num_members ; ptr2 = ptr2->connectsTo,j++)
            {
                    printf("%c ",ptr2->name);
            }
        }
}

int main()
{
    int v;
	printf("Enter number of Vertices v");
    scanf("%d",&v);
    
    Graph * G = (Graph *)malloc(sizeof(Graph));
   
    GraphCreate(G,v);
    
    GraphAddEdge(G,'A','B');
//   GraphAddEdge(G,'A','C');
    GraphAddEdge(G,'A','D');
    
//    GraphAddEdge(G,'B','A');    
//    GraphAddEdge(G,'B','B');
    
//    GraphAddEdge(G,'C','A');
    GraphAddEdge(G,'C','B');

    GraphAddEdge(G,'D','B');
    GraphAddEdge(G,'D','C');

    GraphPrint(G);
	return 0;
}
