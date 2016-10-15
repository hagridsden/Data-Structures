#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct date
{
    int month;
    int day;    
};

struct NODE
{
    struct date * dptr;
    struct NODE * next;
    struct NODE * prev;
};

struct schedule
{
    struct NODE * first;
    struct NODE * last;
};

void monthName(char name[], int m)
{
    switch(m)
    {
            case 1 :strcpy(name,"Jan.");
                    break;
            case 2 :strcpy(name,"Feb.");
                    break;
            case 3 :strcpy(name,"Mar.");
                    break;
            case 4 :strcpy(name,"Apr.");
                    break;
            case 5 :strcpy(name,"May.");
                    break;
            case 6 :strcpy(name,"Jun.");
                    break;
            case 7 :strcpy(name,"Jul.");
                    break;
            case 8 :strcpy(name,"Aug.");
                    break;
            case 9 :strcpy(name,"Sep.");
                    break;
            case 10 :strcpy(name,"Oct.");
                    break;
            case 11 :strcpy(name,"Nov.");
                    break;
            case 12 :strcpy(name,"Dec.");
                    break;
            default : strcpy(name,"Error.");
    }
}

void printBucketLL(struct schedule * s)
{
     printf("\nPrinting all LL :\n");
     
    for(int i=0;i<12;i++)
    {
        if(s[i].first!=NULL)
     {
            printf("\n");
       //   printf("\nStart : %d, End : %d\n",s[i].first->dptr->day,s[i].last->dptr->day);
            
     }      
  for(struct NODE * ptr = s[i].first; ptr!=NULL;ptr = ptr->next)
     {
            printf("%d %d, ",ptr->dptr->month,ptr->dptr->day);
     }
    }
}

void addNodeBucketLL(struct schedule * s,  FILE * fin) // s is an array of size 12
{
    struct date *object2=malloc(sizeof(struct date));
     
    struct NODE * nptr, *n;
    if (fin != NULL) 
    {
        //reading the file into doubly LL
        
        while(!feof(fin))
        {
                fscanf(fin,"%d %d",&object2->month,&object2->day);
                n = malloc(sizeof(struct NODE));
                n->dptr = malloc(sizeof(struct date));
                n->dptr->month = object2->month;
                n->dptr->day = object2->day;
                
                if((s[(object2->month)-1].first==NULL)&&(s[(object2->month)-1].last==NULL))    //adding first node of that month's LL
                {
                        n->prev=NULL;
                        n->next=NULL;
                        s[(object2->month)-1].first=n;
                }
                else
                {
                        nptr->next=n;
                        n->prev=nptr;
                        n->next=NULL;                    
                }
                
                s[(object2->month)-1].last=n; 
                nptr=n; //pointer to last node
        }
     }
     else
     {
            printf("file was null");
    }
     fclose(fin);  
}

struct NODE * middleNode(struct NODE * start, struct NODE * end)
{
    if(start == NULL)
        return NULL;
    
    struct NODE * slow, * fast;
    
    for(slow = start, fast = start ; fast != end ; slow = slow->next, fast = fast->next)     // where M = N/12, at M/2 iteration, slow reaches mid point of LL    
    {
        if(fast->next != end)
                fast = fast->next;
    }
    return slow;
}

void searchBucketLLDate(struct schedule * s, struct date * d)
{
    int flag = 0;
    char monthN[4];
    struct NODE * middle, * head, * tail;
    head = s[d->month-1].first;
    tail = s[d->month-1].last;
    
    do
    { 
        middle = middleNode(head,tail);
       
        if(middle == NULL)
        {
            break;    // flag = 0;
        }
         
        else if(d->day == middle->dptr->day || d->day == head->dptr->day)
        {
            monthName(monthN,d->month);
            printf("%s %d found in schedule.", monthN, d->day);
            flag = 1;
            break;    
        }
        
        else if (middle == head || middle == tail)
            break;
            
        else if(d->day < middle->dptr->day)
        {
            tail = middle;
        }
        else
        {
            head = middle;
        }
    }while(tail==NULL || tail->next != head); // chk wen both become same
        
    if(flag==0)
    {   
        monthName(monthN,d->month);
        printf("%s %d not found in schedule.",monthN, d->day);
    }
}

int main(int argc, char *argv[] )
{
    FILE *fin = fopen(argv[1], "r");
    
    if(fin != NULL)
    {
    struct schedule * s = (struct schedule * )calloc(12, sizeof(struct schedule));   // 1 LL for each month
    
    addNodeBucketLL(s, fin);
   // printBucketLL(s);     // to print LL
    
    struct date * dsearch = malloc(sizeof(struct date));
   // printf("Enter a date to search :");
    scanf("%d%d",&(dsearch->month),&(dsearch->day));
    
    searchBucketLLDate(s,dsearch);
    }
	return 0;
}
