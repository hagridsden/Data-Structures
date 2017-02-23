
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node * left;
    struct node * right;
}node;

typedef struct queue
{
    node *n;
    struct queue * next;
    
}queue;

queue * enQueuefirst(node * num)
{
      queue * q;
      q = (queue *)malloc(sizeof(queue));
      q->n = num;
      q->next = NULL;
      
      return q;
}

void enQueue(queue *q, node * num)
{
    queue *ptr = q;
   
    ptr = q;
    while(ptr->next!=NULL)
        ptr = ptr->next;
        
    if(ptr->next == NULL)
        {               
            ptr->next = (queue *)malloc(sizeof(queue));
            ptr->next->n = num;
            ptr->next->next = NULL;
        }        
}

queue * deQueue(queue *q)
{
    queue * ret = q->next;
    node * ptr = (q->n);
    printf("%d ",ptr->val);
    free(q);
     
    return ret;
}

void levelOrderTraverse(node * root)       // BFS
{
    node * ptr = root;
    queue * q = NULL;
    q = enQueuefirst(ptr);
    
    ptr = (q->n);
    
    while(q)
    {
        ptr = (q->n);
        
        if(ptr->left)
          {  enQueue(q, ptr->left);
 
          } 
        if(ptr->right)
          {  enQueue(q, ptr->right);
          } 
        q = deQueue(q);
    }    
}

node * createroot(int v)
{
    node * ptr = (node *)malloc(sizeof(node));
    ptr->val = v;
    ptr->left = NULL;
    ptr->right = NULL;
    
    return ptr;
}

node * insertBST(node * root, int n)
{
    if(root == NULL)
        return createroot(n);
    
    else if(n < root->val)
    {
        root->left = insertBST(root->left,n);
    }
    
    else
    {
        root->right = insertBST(root->right,n);
    }
    return root;
}

//        DFS

void preOrder(node * root)
{
    printf("%d ",root->val);
    
    if(root->left)
        preOrder(root->left);
        
    if(root->right)
        preOrder(root->right);
}

void Inorder(node * root)
{
    if(root->left)
        Inorder(root->left);
    
    printf("%d ",root->val);
         
    if(root->right)
        Inorder(root->right);
}

void postOrder(node * root)
{
    if(root->left)
        postOrder(root->left);
        
    if(root->right)
        postOrder(root->right);
        
    printf("%d ",root->val);
}

int main()
{
    node * root = NULL;
    int n;
    
	printf("Enter nodes of the Tree (0 to stop) :\n");
    
    while(scanf("%d",&n) && n!=0)
    {
        if(root == NULL)
            root = createroot(n);
            
        else
           root = insertBST(root,n); // or just write insertBST(root,n), no need to update root
    }
    
    printf("\nPrinting Tree in PreOrder : \n");
    preOrder(root);
    
    printf("\nPrinting Tree in Inorder : \n");
    Inorder(root);
   
    printf("\nPrinting Tree in PostOrder : \n");
    postOrder(root);
    
    printf("\nPrinting Tree in levelOrder : \n");
    levelOrderTraverse(root);
    
   
	return 0;
}
