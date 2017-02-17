#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * left;
    struct node * right;    
}node;

node * addNode(node *root, int value)
{
    if(root == NULL)
    {
        root = (node *)malloc(sizeof(node));
        root->data = value;
        root->left = NULL;
        root->right = NULL;
    }
    
    else
    {
        node * ptr = root;
        
        while(ptr!=NULL)
        {
            if(value < ptr->data)
            {
                if(ptr->left != NULL)
                    ptr = ptr->left;
                else
                {
                    ptr->left = (node *)malloc(sizeof(node));
                    ptr->left->data = value;
                    ptr->left->left = NULL;
                    ptr->left->right = NULL;
                    break;
                }
            }
            else if(value > ptr->data)
            {
                if(ptr->right != NULL)
                    ptr = ptr->right;
                    
                else
                {
                    ptr->right = (node *)malloc(sizeof(node));
                    ptr->right->data = value;
                    ptr->right->right = NULL;
                    ptr->right->left = NULL;
                    break;
                }
            }
        }
    }
        
    return root;
}

void printBSTpreOrder(node * root)
{
    printf("%d ",root->data);    
    
    if(root->left!=NULL)
        printBSTpreOrder(root->left);
           
    if(root->right!=NULL)
        printBSTpreOrder(root->right);
}

int main()
{
    int n;
    node * root = NULL;
    
	printf("Creating BST...Enter values, 0 to exit :\n");

    while(scanf("%d",&n) && n!=0)
    {
       // if(root != NULL)
            root=addNode(root,n);        
       
    }
    
    printBSTpreOrder(root);
    
	return 0;
}
