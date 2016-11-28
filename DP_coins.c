#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Program to find number of ways in which N can be made from M coins

int main() 
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    

    int N, M;
    
    printf("Enter N and M : ");
    scanf("%d%d",&N,&M);
    
    int coins[M];
    printf("Enter %d coins:", M);
    for(int i=0;i<M;i++)
        scanf("%d",&coins[i]);
    
    int arr[M+1][N+1];
    
     for(int i=0;i<M+1;i++)
    {
        arr[i][0] = 0; 
    }
    
    for(int i=0;i<N+1;i++)
    {
        arr[0][i] = 0; 
    }
    
    for(int i=1;i<M+1;i++)
    {
        for(int j=1;j<N+1;j++)
        {
            if(j<coins[i-1])
                arr[i][j] = arr[i-1][j];
    
            else if(j==coins[i-1])
                 arr[i][j] = arr[i-1][j]+1;
            
            else if(j>coins[i-1])
                 arr[i][j] = arr[i][j-coins[i-1]]+arr[i-1][j];
            
         }        
    }
    
    printf("NUmber of ways are : %d",arr[M][N]);
    return 0;
}
