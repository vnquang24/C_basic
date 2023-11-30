#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    char time[50];
    char bien[50];
    struct node* next;
}node;

node* create_node(char time[],char bien[]){
     node* p = (node*)malloc(sizeof(node));
     strcpy(p->time,time);
     strcpy(p->bien,bien);
     p->next = NULL;
     return p;
}

node* llInsertTail(node* root,char time[],char bien[]) {
  node* pNewNode = create_node(time,bien);
  if (root == NULL) return (node*)pNewNode;
  node* p = root;
  for (p = root; p->next != NULL; p = p->next)
    ;
  p->next = pNewNode;
  return root;
}

void list(node* root){
    node* p_run = root;
    for (p_run = root;p_run != NULL;p_run = p_run->next)
    {
        printf("%s\n",p_run->bien);
    }
}

node* llDeleteAfter(node* root, char mau[]) {
    node* temp = root, *prev;

    if (temp != NULL && strcmp(temp->bien, mau) == 0) {
        root = temp->next;
        free(temp);
        return root;
    }

    while (temp != NULL && strcmp(temp->bien, mau) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return root;

    prev->next = temp->next;
    free(temp);

    return root;
}
int check(node* root,char mau[]){
    node* p_run = root;
    int check = 0;
    for (p_run = root;p_run != NULL;p_run = p_run->next)
    {
        if (strcmp(mau,p_run->bien) == 0)
        {
            check = 1;
            return check;
        }
    }
    return check;
}
int find(node* root,char mau[]){
    if (check(root,mau) == 0)
    {
        return -1;
    }
    int tt = 0;
    for (node* p_run = root;p_run != NULL;p_run= p_run->next)
    {
        
        if (strcmp(p_run->bien,mau)== 0)
        {
            
            break;
        }
      //  printf("%s_find",p_run->bien);
        tt++;
    }
    return tt;
}
int cout(node* root){
    int cou = 0;
    for (node* p_run = root;p_run != NULL;p_run= p_run->next)
    {
        if (p_run->bien[0] == 'x')
        {
            cou++;
        }
    }
    return cou;
}
int check_out(node* root, node* root2, char mau[]){
    if (check(root2, mau) == 1 && check(root, mau) == 0) {
        return 1;
    }
    return -1;
}
void printll(node* root){
  //  node* p_run = root;
    for (node* p_run = root;p_run != NULL;p_run = p_run->next)
    {
        printf("%s %s\n",p_run->time,p_run->bien);
    }
}
int main(){
    node* root = NULL;
    node* root2 = NULL;
    char time[50];
    char bien[50];
    char checkEnd[50];
    do {
        scanf("%s", checkEnd); 
        if(strcmp(checkEnd, "*") == 0) break; 
        strcpy(time,checkEnd); 
        scanf("%s",bien);
        root = llInsertTail(root,time,bien);
    } while(1);
    fflush(stdin);
    char temp[100];
    char temp_bien[100];
    char temp_time[100];
    do {
       scanf("%s",temp);
       if (strcmp(temp,"***") == 0)
       {
          break;
       }
       if (strcmp(temp,"list") == 0){
          list(root);
       }
       else if (strcmp(temp,"in") == 0){
          scanf("%s",temp_time);
          scanf("%s",temp_bien);
          root2 = llInsertTail(root2,temp_bien,temp_time);
      //    printf("%s_in",temp_time);
      //  printf("%s_in",temp_bien);
          if (check(root,temp_bien) == 0)
          {
              root = llInsertTail(root,temp_time,temp_bien);
              printf("1\n");
          }
          else
          {
             printf("0\n");
          }
          
       }
       else if (strcmp(temp,"out") == 0)
       {
          scanf("%s",temp_time);
          scanf("%s",temp_bien);
          if (check(root,temp_bien) == 1)
          {
              root = llDeleteAfter(root,temp_bien);
              printf("1\n");
          }
          else
          {
              printf("0\n");
          }   
       }
       else if (strcmp(temp,"find") == 0){
         // printf("%s",temp);
          scanf("%s",temp_bien);
        //  printf("%s",temp_bien);
        int f = find(root,temp_bien);
          printf("%d\n",f);
       }
       else if (strcmp(temp,"cnt-bicycle") == 0){
          printf("%d\n",cout(root));
       }
       else if (strcmp(temp,"has-checkout") == 0){
          scanf("%s",temp_bien);
          printf("%d\n",check_out(root, root2, temp_bien));
       }
   //    printf("-------\n");
    } while(1);
   // printll(root);
    return 0;
}
