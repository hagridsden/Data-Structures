#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node * createfistnode(int num)
{
    node * ptr = (node *)malloc(sizeof(node));
    ptr->data = num;
    ptr->next = NULL;
    
    return ptr;    
}

void insertatendLL(node * head, int num)
{
    node * ptr = head;
    
    while(ptr->next != NULL)
        ptr = ptr->next;
        
    ptr->next = (node *)malloc(sizeof(node));
    ptr = ptr->next;
    
    ptr->data = num;
    ptr->next = NULL;    
}

void printLL(node * head)
{
    node * ptr = head;
    
    while(ptr->next!=NULL)
    {
        printf("%d --> ",ptr->data);
        ptr = ptr->next;
    }
    
    printf("%d",ptr->data);
}

void splithalfLL(node * head, node ** a, node ** b)
{
    node * slow, * fast;
    slow = head;
    fast = head;
    
    while(fast->next!=NULL)
    {
        fast = fast->next;
        
        if(fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }    
   
    *a = head;
    *b = slow->next;   
    slow->next = NULL;
    
}


node * merge(node * a, node * b)
{
    node * result;
    
    if(b == NULL)
        return a;
        
    else if(a == NULL)
        return b;
    
    if(a->data < b->data)
    {
         result = a;
         result->next = merge(a->next,b);
    }
    else
    {
        result = b;
        result->next = merge(b->next,a);
    }
    return result;
}

void MergeSort(node ** head)
{
    node * a, * b;
    a = NULL;
    b = NULL;
 
    //base cases
        
    if(head == NULL || (*head)->next == NULL)  // 0 or 1 elements in LL
        return;
     
    splithalfLL(*head, &a, &b);
    MergeSort(&a);
    MergeSort(&b);
    *head = merge(a,b);
}

int main()
{
	node * head = NULL;
    node * a, * b;
    a = NULL;
    b = NULL;
    int n;
        
    printf("Enter Data for LL (0 to stop)");
    
    while(scanf("%d",&n) && (n!=0))
    {
        if(head == NULL)
        {
            head = createfistnode(n);
        }
        
        else
            insertatendLL(head,n);
    }
    
    printf("\nPrinting the Linked List : \t");
    printLL(head);
    
    MergeSort(&head);
    printf("\nSorted linked list is : \n");
    printLL(head);
    
	return 0;
}
