#include<stdio.h>
#include<string.h>
#define MAX_ELEMENT 100
typedef struct add
{ 
    char name[20];
    char sdt[10];
    char email[1000];
}add;

int search(add tel[],int siz,char check[]){
    int k = 0;
    strcpy(tel[siz].name,check);
  //  printf("%d",strcmp(tel[0].name,check));
    while (strcmp(tel[k].name,check) != 0)
    {
        k++;
    }
    if (k == siz){
       return -1;    
    }
    return k++;
}
int main(){
   char key[] = "D";
  add a[MAX_ELEMENT] = {{"A", "1", "1@"},
                                {"B", "2", "2@"},
                                {"C", "3", "3@"},
                                {"E", "5", "5@"}};
  printf("Search of %s returns %d\n", key, search(a, 4, key));

  return 0;
}