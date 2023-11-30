#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    char day[50];
    char hour[50];
    char mssv[50];
    char quiz[50];
    struct node* next;
}node;

typedef struct node2
{
    char day[50];
    int cou;
    struct node2* next;
}node2;

node2* create_node_2(int x,char y[]){
    node2* p = (node2*)malloc(sizeof(node2));
    p->cou = x;
    strcpy(p->day,y);
    p->next = NULL;
    return p;   
}

node2* push_2(node2* root,int x,char y[]){
    node2* p = create_node_2(x,y);
    if (root == NULL)
    {
        return p;
    }
    node2* p_run = root;
    p_run->next = p;
  //  printf("HELOOOOOOOOOOO PUSHHHHHH2");
    return root;
}
node* create_node(char x[], char y[], char z[], char t[]){
    node* p = (node*)malloc(sizeof(node));
    strcpy(p->day,x);
    strcpy(p->hour,y);
    strcpy(p->mssv,z);
    strcpy(p->quiz,t);
    p->next = NULL;
    return p;   
}

node* push(node* root,char x[],char y[],char z[],char t[]){
    node* p = create_node(x,y,z,t);
    if (root == NULL)
    {
        return p;
    }
    p->next = root;
    return p;
}


void print_ll(node* root){
    for (node* p_run = root;p_run != NULL;p_run = p_run->next){
        printf("%s %s %s %s\n",p_run->day,p_run->hour,p_run->mssv,p_run->quiz);
    };
}

void free_list(node* root){
    node* tmp;

    while (root != NULL)
    {
       tmp = root;
       root = root->next;
       free(tmp);
    }
}
node2* check(node2* root,char day[]){
    for (node2* p_run = root;p_run != NULL;p_run = p_run->next){
        if (strcmp(p_run->day,day) == 0)
        {
            return p_run;
        }  
    };
    return NULL;
}
node2* merge(node* root){
    node2* m_root = NULL;
    for (node* i = root; i != NULL; i=i->next)
    {

        node2* temp = check(m_root,i->day);
        if (temp == NULL)
        {
            m_root = push_2(m_root,1,i->day);
        }
        else
        {
            temp->cou++;
        }
    }
    return m_root;
}
void print_ll_2(node2* root){
    for (node2* p_run = root;p_run != NULL;p_run = p_run->next){
        printf("%s %d\n",p_run->day,p_run->cou);
    };
}
int main(){
    node* root = NULL;
    node2* m_root = NULL;
    int n;
    char day[50];
    char hour[50];
    char mssv[50];
    char quiz[50];
    char line[200];
    while (fgets(line, sizeof(line), stdin)) {
        if (sscanf(line, "%s %s %s %s", day, hour, mssv, quiz) == 4) {
            root = push(root,day,hour,mssv,quiz);
            n++;
        } else if (strcmp(day,"*") == 0) {
            break;
        }
    }
   // print_ll(root);
    m_root = merge(root);
    print_ll_2(m_root);
    return 0;
}