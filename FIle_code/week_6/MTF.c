#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
    char name[100];
    char sdt[100];
    char email[100];
    struct node* next;
} node;

node* create_node(char name[],char sdt[],char email[]){
    node* p = (node*)malloc(sizeof(node));
    strcpy(p->name,name);
    strcpy(p->sdt,sdt);
    strcpy(p->email,email);
    p->next = NULL;
    return p;
}

node* new_node(node* root,char name[],char sdt[],char email[]){
    node* p = create_node(name,sdt,email);
    if (root == NULL)
    {
        return p;
    }
    node* p_run = NULL;
    for (p_run = root;p_run->next != NULL; p_run = p_run->next);
    p_run->next = p;
    return root;
}
node* printll(node* root){
    node* p_run = root;
    for (p_run = root; p_run != NULL; p_run = p_run->next)
    {
        if (p_run->next == NULL)
        {
            printf("%s",p_run->name);
        }
        else
        {
            printf("%s ",p_run->name);

        }  
    }
    return root;
}
node* find(node* root,char name[], int *pIn){
    node* temp;
    int pos;
    node* pre1_node = NULL;
    node* pre2_node = NULL;
    int i = 0;
    for (node* p_run= root;p_run != NULL;p_run = p_run->next)
    {
        if (strcmp(p_run->name,name) == 0)
        {
            temp = p_run->next;
            pre2_node->next = p_run;
            p_run->next = pre1_node;
            pre1_node->next = p_run->next;
            pos = i;
            *pIn = pos;
            return root;            
        }
        pre2_node = pre1_node;
        pre1_node = p_run;
        i++;
    }
pos = -1;
*pIn = pos;
return root;    
}
int main(){
    char key[] = "D";
    node a[1000] ={ {"A", "1", "1@"},
                    {"B", "2", "2@"},
                    {"C", "3", "3@"},
                    {"D", "4", "4@"},
                    {"E", "5", "5@"}};
    node* root = NULL;
    for (int i = 0; i < 5; i++)
    {
        root = new_node(root,a[i].name,a[i].sdt,a[i].email);
    }
    int p_index = 0;
    root = find(root,key,&p_index);
  printf("Search of %s returns %d\n", key,p_index);
    root = find(root,key,&p_index);
  printf("Search of %s returns %d\n", key,p_index);
  return 0;
}