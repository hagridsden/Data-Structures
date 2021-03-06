#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct EdgeTag
{
        char name;
        struct EdgeTag * connectsTo;
}EdgeTag;

typedef struct VertexTag
{
    char Vname;
    int visited;
    int num_members;
 //   int children;
    struct VertexTag * pre;
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
    {
        G->array[i].head=NULL;
        G->array[i].num_members = 0;
        G->array[i].visited = 0;
        G->array[i].Vname = 65+i;
    }
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
            //G->array[src].Vname = c;
            G->array[src].num_members = 1;
            G->array[src].visited = 0;
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
            G->array[src].visited = 0;  //default 0
      }        
}

void GraphPrint(Graph * G)
{
        printf("%d",G->v);

        EdgeTag * ptr2;
        int i;
        for(i =0; i< (int) (G->v);i++)
        {
            printf("\n%c : ",G->array[i].Vname);
            for(ptr2 = G->array[i].head ; ptr2!=NULL ; ptr2 = ptr2->connectsTo)
            {
                    printf("%c ",ptr2->name);
            }
        }
}


void POP(char * stack,int tail)
{
  //  char c = stack[tail];
    
    stack[tail]=' ';
    
}

void PUSH(char * stack, char c)
{
    int i=0;
    while(stack[i]!=' ')
        i++;
        
  //  printf("\n%c,PUSHING : ",c);
    stack[i] = c;    
}


int sizeofStack(char * stack,Graph *G)
{
    int i=0;
    while((stack[i]!=' ')&&(i<G->v))
        i++;
        
    return i;    
}

void DFS_visit(Graph *G, char * stack, VertexTag * u)
{
    u->visited = -1;
    EdgeTag * v;
    for(v = u->head; v!=NULL; v = v->connectsTo)
    {
        if(G->array[v->name-65].visited==0)
        {
            G->array[v->name-65].pre = u;
            DFS_visit(G, stack, &G->array[v->name-65]);
        }
    }
    
    u->visited = 1;
    
    PUSH(stack,u->Vname);
}


void topologicalSort(Graph *G)
{
    char stack[G->v];
    int size;
    
    for(int i=0;i<G->v;i++)
    {
        G->array[i].visited=0;
        G->array[i].pre = NULL;
        
        stack[i]=' ';
    }
    
    for(int i=0;i<G->v;i++)
    {
        if(G->array[i].visited == 0)
        {
            DFS_visit(G,stack,&G->array[i]);
        }
    }  
    
    size = sizeofStack(stack,G);
    
    printf("\nTopological ordering is : \n");
    printf("%c",stack[size-1]);
    for(int i=size-2;i>=0;i--)
        printf(" --> %c",stack[i]);
    
}


int main()
{
    int v;
	printf("Enter number of Vertices v : ");
    scanf("%d",&v);
    
    Graph * G = (Graph *)malloc(sizeof(Graph));
   
    GraphCreate(G,v);
    
    //  A--->B
    //     / |
    //    /  |
    //  \/   v
    //  D    C--->E   
    
    //adding edges both ways
    
    GraphAddEdge(G,'A','B');   
    GraphAddEdge(G,'B','C');
    GraphAddEdge(G,'B','D');
    
    GraphAddEdge(G,'D','F');
    GraphAddEdge(G,'F','G');
   
    GraphAddEdge(G,'C','E');
    GraphAddEdge(G,'E','D');
    
    printf("\nPrinting Graph :\n");
    GraphPrint(G);
   
    topologicalSort(G);
    
    
	return 0;
}