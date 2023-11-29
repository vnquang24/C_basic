#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    char name[50];
    char tele[50];
    char add[50];
}node;

int liner_search(node A[],int n,char x[]){
    int k = 0;
    
    while (strcmp(A[k].name,x) != 0 && k < n)
    {
        k++;
    }
    if (k<n)
    {
        return k;
    }
    return -1;
}
int main(){
    char key[100];
    scanf("%s",key);
    node a[5] = {{"A", "1", "1@"},
                 {"B", "2", "2@"},
                                 {"C", "3", "3@"},
                                 {"D", "4", "4@"},
                                 {"E", "5", "5@"}};
printf("%d",liner_search(a, 5, key));
return 0;
}