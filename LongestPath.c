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
        
    stack[i] = c;    
}


int sizeofStack(char * stack,Graph *G)
{
    int i=0;
    while((stack[i]!=' ')&&(i<G->v))
        i++;
        
    return i;    
}

void longestPath_func(Graph *G, char * stack, char * longestPath, VertexTag * u)
{
   // PUSH(stack,u->Vname);
    u->visited = -1;
    int size = 0,longest = 0;
    EdgeTag * v;
    for(v = u->head; v!=NULL; v = v->connectsTo)
    {
        if(G->array[v->name-65].visited==0)
        {
            PUSH(stack,v->name);
            G->array[v->name-65].pre = u;
            longestPath_func(G, stack,longestPath, &G->array[v->name-65]);
        }
    }
    u->visited = 1;
    
     size = sizeofStack(stack,G);
     longest = sizeofStack(longestPath,G);
    
 //   printf("size = %d, Longest = %d",size,longest);
    
     if(size >= longest)
        {
            int j=0;
            while(j<size)
            {
              // printf("%c * ",stack[j]);
               longestPath[j] = stack[j];
               
               j++;                
            }
        }
        
     POP(stack,size-1);
    
}

void longestPath(Graph *G)
{
    char stack[G->v];
    char longestPath[G->v];
    int longest = 0;
    for(int i=0;i<G->v;i++)
    {
        G->array[i].visited=0;
        G->array[i].pre = NULL;
        
        stack[i]=' ';
        longestPath[i]=' ';
    }
    
    for(int i=0;i<G->v;i++)
    {
        if(G->array[i].visited == 0)
        {
            PUSH(stack,G->array[i].Vname);
            longestPath_func(G,stack,longestPath,&G->array[i]);
        }
       
    }
    
    longest = sizeofStack(longestPath,G);
    printf("\nSize : %d",longest);
    
    printf("\n%c",longestPath[0]);
    for(int i=1;i<sizeofStack(longestPath,G);i++)
        printf(" --> %c",longestPath[i]);
    
}

int main()
{
    int v;
	printf("Enter number of Vertices v : ");
    scanf("%d",&v);
    
    Graph * G = (Graph *)malloc(sizeof(Graph));
   
    GraphCreate(G,v);
    
      // 7 nodes
      //  A--->B
      //     / |
      //    /  |
      //  \/   v
//G<--F<--D    C--->E   
    
    GraphAddEdge(G,'A','B');   
    GraphAddEdge(G,'B','C');
    GraphAddEdge(G,'B','D');
    
    GraphAddEdge(G,'D','F');
    GraphAddEdge(G,'F','G');
    
    GraphAddEdge(G,'C','E');
    GraphAddEdge(G,'E','D');
    
    printf("\nPrinting Graph :\n");
    GraphPrint(G);
    
    printf("\n\nLongest Path is : ");
    longestPath(G);
    
	return 0;
}