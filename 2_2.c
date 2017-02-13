//2.2  Implement an algorithm to find the kth to last element of a singly linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}node;

node * createFirstNode(int newdata)
{
    node * LL;
    LL = (node *)malloc(sizeof(node));
    LL->data=newdata;
    LL->next=NULL;     
    return LL;
}

void insertAtEnd(int newdata, node * LL)
{
    node * ptr;
    ptr = LL;
    while(ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = (node *)malloc(sizeof(node));
    ptr = ptr->next;
    ptr->data = newdata;
    ptr->next = NULL;   
}

void deletenextnode(node * delnxt)
{
    delnxt->next = delnxt->next->next;
    
}

int findKthtolast(node * LL, int k)
{
     int size = 0, i=0;
     node * ptr;
     //find number of elements in LL
     for(ptr = LL ; ptr!=NULL ; ptr=ptr->next)
     {
            size++;
     }
     
     for(ptr = LL, i =0; i<(size-k); ptr = ptr->next,i++);
     
     return ptr->data;
}

void printLL(node * LL)
{
    node * ptr=LL;
    
    while(ptr->next != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("%d ",ptr->data);    //printing last node
}

int main()
{
	printf("Enter elements of linked list(press 0 to stop)\n");
	int n,k;
    node * LL = NULL;
    
    while(scanf("%d",&n) && (n!=0))
    {
        if(LL == NULL)
            LL = createFirstNode(n);
            
        else
        {
            insertAtEnd(n,LL);
        }
    }
    
    printf("\nPrinting list : \n");
    printLL(LL);
    
    printf("\nEnter value of k :");
    scanf("%d",&k);
    printf("\n %dth last node is : %d",k,findKthtolast(LL,k));
    
    return 0;
}
