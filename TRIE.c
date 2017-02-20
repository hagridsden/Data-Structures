
/*
Trie is an efficient information retrieval data structure. Use this data structure to store Strings and search strings.
Your task is to use TRIE data structure and search the given string A. If found print 1 else 0.

Input:
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. 
 * Each test case consists of three lines.
First line of each test case consist of a integer N, denoting the number of element in a Trie to be stored.
Second line of each test case consists of N space separated strings denoting the elements to be stored in the trie.
Third line of each test case consists of a String A to be searched in the stored elements.

Output:
Print the respective output in the respective line.

Constraints:
1<=T<=20
1<=N<=20

Example:
Input:
1
8
the a there answer any by bye their
the
Output:
1
 * 
 *  EXAMPLE
 *                    root
                    /   \    \
                    t   a     b
                    |   |     |
                    h   n     y
                    |   |  \  |
                    e   s  y  e
                 /  |   |
                 i  r   w
                 |  |   |
                 r  e   e
                        |
                        r
                         * 
                         * 
                         * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct trienode
{
    struct trienode *nodeArr[26];   //number of alphabets
    bool isleaf;
    
}trienode;


trienode * root = NULL;
  
typedef struct str
{
    char s;
    struct str *next;
    
}str;

trienode *getNode()
{    
    printf("\ninside getnode()");
    trienode * root = (trienode *)malloc(sizeof(trienode));
   
    for(int j=0 ; j<26 ; j++)
    {
        root->nodeArr[j] = NULL;
    }    
    root->isleaf = false;
    return root;
}

bool searchString(trienode *root, str *st)
{
    printf("\nNow Searching...");
    str *p = st;
    trienode *tree = root;
    trienode *lasttree = tree;
    
    while(p!=NULL)
    {
        if(!tree->nodeArr[(p->s)-65])   //==null
        {   
            printf("\nFound NULL FOR : %c",p->s);
            break;
        }   
        else
        {
            printf("\nFound in trie : %c",p->s);
        }
       
       lasttree = tree;
       tree = tree->nodeArr[(p->s)-65];
       p = p->next;
            
    }
    if(p==NULL && lasttree->isleaf == true)
        return true;
    else
        return false;
}

void insertString(trienode *root, str *st)
{
    printf("\nString to insert is : ");
    str *p = st;
    while(p!=NULL)
    {
        printf("%c",p->s);
        p=p->next;
    }
    
    p = st;
    trienode *tree = root;
    trienode *lasttree = tree;
    
    while(p!=NULL)
    {
        if(!tree->nodeArr[p->s - 'A']) //==NULL
        {
            tree->nodeArr[p->s - 'A'] = getNode();
        }
       
       lasttree = tree;
       tree = tree->nodeArr[(p->s)-'A'];
        
       p = p->next;
    }
    lasttree->isleaf = true;   

}


int main()
{
    int N;
    char c;
    bool result;
  
    str *s = NULL;
    str *p = NULL;
    
    printf("\nEnter the following :");
    printf("\n1.First line of each test case consist of a integer N, denoting the number of element in a Trie to be stored.");
    scanf("%d",&N);
    
    root = getNode();
    
    printf("\nSecond line of each test case consists of N space separated strings denoting the elements to be stored in the trie.");
    
    for(int i=0;i<N;i++)
    {     
        printf("\nEnter new string");
        s = (str *)malloc(sizeof(str));
        s->s = 'F';
        s->next = NULL;
        
       while(scanf("%*['\n'\t]%c",&c) && c!=' ')
        {
            p = s;
            while(p->next != NULL)
            {  
                p = p->next;
            }
            if(p->next==NULL && p->s!='F')
               {    p->next = (str *)malloc(sizeof(str));
                    p = p->next;
               }
            p->s = c;
            p->next = NULL;
        }
        
        str *p = s;
    
        while(p!=NULL)
        {
        printf("%c",p->s);
        p=p->next;
        }
        
       insertString(root,s);   //insert string in trie        
    }
    
     printf("\nThird line of each test case consists of a String A to be searched in the stored elements.");
     s->s = ' ';
     s->next = NULL;
        
     while(scanf("%*['\n'\t]%c",&c) && c!=' ')
              {
            p = s;
            while(p->next!=NULL)
                p = p->next;
            if(p->next==NULL && p->s!=' ')
               {    p->next = (str *)malloc(sizeof(str));
                    p = p->next;
               }
            p->s = c;
            p->next = NULL;
        }

    printf("\nString to Search is : ");
    p = s;
    while(p!=NULL)
    {
        printf("%c",p->s);
        p=p->next;
    }
    
    result = searchString(root,s);

    printf("\nResult : ");
    
    if(result == true)
        printf("\nString found!");
    else
        printf("\nString not found!");
    
    return 0;
}
