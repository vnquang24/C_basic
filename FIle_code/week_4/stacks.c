#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char dt;
typedef struct stacks
{
    dt ele;
    struct stacks* next;
}stack_t;

stack_t* create_node(dt u){
      stack_t* p = (stack_t*)malloc(sizeof(stack_t));
      p->next = NULL;
      p->ele = u;
      return p;
}

stack_t* push(stack_t* root,dt u){
    stack_t* p = create_node(u);
    if (root == NULL)
    {
        return p;
    }
    stack_t* p_run = NULL;
    for (p_run = root; p_run->next != NULL; p_run = p_run->next)
    ;
    p_run->next = p;
    return root;
}

stack_t* pop(stack_t* root){
    if (root == NULL) return NULL;
    if (root->next == NULL)
    stack_t* p_run = NULL;
    for (p_run = root; p_run->next->next != NULL; p_run = p_run->next)
    ;
    free(p_run->next);
    p_run->next = NULL;
    return root;
}

dt top(stack_t* root){
    stack_t* p_run;
    for (p_run = root; p_run->next != NULL; p_run = p_run->next)
    ;
    return p_run->ele;
}

int empty(stack_t* root){
    if (root == NULL)
    {
        return 0;
    }
    else return 1;
}

int isFull(stack_t* root,int cap){
    stack_t* p_run;
    int temp = 0;
    for (p_run = root; p_run->next != NULL; p_run = p_run->next){
         temp++;
    }
    if (temp == cap) {
        return 1;
    }
    else return 0;
}

void print(stack_t* root){
    stack_t* p_run;
    for (p_run = root; p_run != NULL; p_run = p_run->next){
         printf("%c ",p_run->ele);
    }
}

int sopt(stack_t* root){
    stack_t* p_run;
    int temp = 0;
    for (p_run = root; p_run != NULL; p_run = p_run->next){
         temp++;
    }
    return temp;
}
int main(){
    stack_t* root1 = NULL;    
    stack_t* root2 = NULL;
    stack_t* root3 = NULL;
    char num1[1000];
    char num2[1000];
    fflush(stdin);
    fgets(num1,1000,stdin);
    num1[strlen(num1)-1] = '\0';
    fflush(stdin);
    fgets(num2,1000,stdin);
    num2[strlen(num2)-1] = '\0';
    if (strlen(num1) > strlen(num2))
    {
        for (int i = 0; i < (strlen(num1)-strlen(num2)); i++)
        {
            root2 = push(root2,'0');
        }
    }
    if (strlen(num2) > strlen(num1))
    {
        for (int i = 0; i < (strlen(num2)-strlen(num1)); i++)
        {
            root1 = push(root1,'0');
        }
    }
    for (int i = 0; i < strlen(num1); i++)
    {
        root1 = push(root1,num1[i]);
    }
    for (int i = 0; i < strlen(num2); i++)
    {
        root2 = push(root2,num2[i]);
    }
    int n = sopt(root1);
    int du = 0;
    int rs[n+1];
    int a;
    for (int i = 0; i < 3; i++)
    {
        char temp1 = top(root1);
        char temp2 = top(root2);
        a = temp1 - '0' + temp2 - '0' + du;
        du = a/10; 
        a = a%10;
        printf("%d",a);
        rs[i] = a;        
        root1 = pop(root1);
        root2 = pop(root2); 
        printf(".");
    }
    printf("hello");
    rs[n] = du;
    for (int i = n+1; i > 0; i--)
    {
        printf("%d",rs[i]);
    }
    
    // print(root1); 
    // print(root2);
    return 0;
}

