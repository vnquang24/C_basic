#include<stdio.h>
#include<stdlib.h>

int check(int A[][],int n){
    for (int i = 0; i < n; i++)
    {
    int S = 0;
       for (int j = 1; i < n; i++)
       {
           S = S + A[i][j];
       }
       if (S > 1)
       {
          return 1;
       }
    }
    for (int j = 0; j < n; j++)
    {
        int S = 0;
       for (int i = 1; i < n; i++)
       {
           S = S + A[i][j];
       }
       if (S > 1)
       {
          return 1;
       }
    }
    
}
int main(){
    int n;
    int x;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&x);
        int A[x][x];
        for (int j = 0; j < x; j++)
        {
            for (int k = 0; k < x; k++)
            {
                A[j][k] = x;
            }
            
        }
        
    }
    
}