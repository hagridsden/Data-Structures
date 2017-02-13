//2.1 Write code to remove duplicates from an unsorted linked list.
//FOLLOW UP
//How would you solve this problem if a temporary buffer is not allowed?

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

void removeduplicates(node * LL)
{
    for(node * ptr = LL;ptr!=NULL;ptr=ptr->next)
    {
        for(node * ptr2 = ptr;ptr2!=NULL;ptr2=ptr2->next)
        {
            if((ptr2->next != NULL) && (ptr2->next->data == ptr->data))
            {
                deletenextnode(ptr2);
            }
        }
    }
    
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
	printf("Enter marks of subjects (press 0 to stop)\n");
	int n;
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
    
    printf("\nRemoving Duplicates in process ..... \n");
    removeduplicates(LL);
    
    printf("\nPrinting after removing duplicates :\n");
    
    printLL(LL);    
    
    return 0;
}
