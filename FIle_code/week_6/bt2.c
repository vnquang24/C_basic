#include<stdio.h>
#include<string.h>
#define MAX_ELEMENT 100
typedef struct add
{
    char name[20];
    char sdt[10];
    char email[1000];
}add;

int search(add tel[],int siz,char key[]){
    int i;
    add tempr;
    for (i = 0;i<siz-1 && (strcmp(tel[i].name,key) != 0); i++);
    if (strcmp(tel[i].name,key) == 0)
    {
        if (i>0)
        {
        tempr = tel[i];
        tel[i] = tel[i-1];
        tel[i-1] = tempr;
        }
        return i++; 
    }
    else
    {
        return -1;
    }    
}

int main(){
    char key[] = "D";

 

   add a[MAX_ELEMENT] = { {"A", "1", "1@"},
                                 {"B", "2", "2@"},
                                 {"C", "3", "3@"},
                                 {"D", "4", "4@"},
                                 {"E", "5", "5@"}};

 

  printf("Search of %s returns %d\n", key, search(a, 5, "B"));
  printf("Search of %s returns %d\n", key, search(a, 5, "D"));
    printf("Search of %s returns %d\n", key, search(a, 5, "B"));

  for (int i = 0; i < 5; i++)
  {
    printf("%s\n",a[i].name);
  }
  
  return 0;
}
