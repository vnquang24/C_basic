#include<stdio.h>
#include <stdlib.h>
typedef int dt_t;
typedef struct node
{
    dt_t data;
    struct node* next;
}node;

node* create_node(dt_t x){
    node* p = (node*)malloc(sizeof(node));
    p->data = x;
    p->next = NULL;
    return p;
}
node* push(node* top,dt_t x){
    node* p = create_node(x);
    if (top == NULL)
    {
        return p;
    }
    p->next = top;
    return p;   
}

node* pop(node* top){
    if (top == NULL)
    {
        printf("Khong con phan tu");
        return top;
    }
    node* temp = top;
    top = top->next;
    free(temp);
    return top;
}

dt_t top_show(node* top){
    if (top == NULL)
    {
        printf("TOP NULL");
        return -1;
    }  
    return top->data;
}

void display_st(node* top){
    for (node* p_run = top;p_run != NULL;p_run=p_run->next)
    {
        printf("%d ",p_run->data);
    }
    printf("\n");
}

int main(){
    node* top = NULL;
    int n;
    scanf("%d",&n);
    dt_t temp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&temp);
        top = push(top,temp);
    }
    display_st(top);
    printf("Lay 2 phan tu ra khoi ngan xep \n");
    top = pop(top);
    display_st(top);
    top = pop(top);
    display_st(top);
    printf("Hien thi phan tu top \n");
    printf("%d",top_show(top));
    return 0; 
}