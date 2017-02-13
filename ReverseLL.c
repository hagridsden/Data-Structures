// Program to Reverse a linked list.

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

node * lastnode(node * LL)
{
    node * ptr;
    ptr = LL;
    while(ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    return ptr;
}

void LLReverse(node * LL, node * first, node * second)
{
    if(second->next!=NULL)
        LLReverse(LL,second, second->next);
        
    second->next = first;    
    if(first==LL)
        first->next = NULL;
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
    
    printf("\nReversing Linked List ...\n");
    node * LLRevHead = lastnode(LL);
    LLReverse(LL,LL, LL->next);
    
    printf("Reversed Linked list :\n");
    printLL(LLRevHead);
    return 0;
}
