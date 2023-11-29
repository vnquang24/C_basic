#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int dt_t;
typedef struct node
{
    dt_t data;
    struct node* next;
}node;

typedef struct queue
{
    node *front,*rear;
}queue;

node* create_node(dt_t x){
    node* p = (node*)malloc(sizeof(node));
    p->data = x;
    p->next = NULL;
    return p;
}
queue* enqueue(queue* q,dt_t x){
    node* p = create_node(x);
    if (q->rear == NULL)
    {
        q->front = q->rear = p;
        return q;
    }
    q->rear->next = p;
    q->rear = p;
    return q;
}

queue* dequeue(queue* q){
    if (q->front == NULL)
    {
        return q;
    }
    node* temp = q->front;
    q->front=q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return q;
}

dt_t show_front(queue* q){
    return q->front->data;
}
dt_t show_rear(queue* q){
    return q->rear->data;
}
void display_qu(queue* q){
    for (node* p_run = q->front;p_run != NULL;p_run=p_run->next)
    {
        printf("%d ",p_run->data);
    }
    printf("\n");
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
        printf("Stack het phan tu");
        return;
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
        return -1; // BUG SEGMATION top->data // NULL
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

void i2pfix(node* top,queue* root){
    char s[100];
    scanf("%s",s);
    for (int i = 0; i < strlen(s); i++)
    {
        root = enqueue(root,s[i]);
    }
    for (node* p_run = root->front;p_run != NULL;p_run=p_run->next)
    {
        if (p_run->data > 47 && p_run->data < 58)
        {
            printf("%c ",show_front(root));
            dequeue(root);
        }
        else
        {
            if (top == NULL || top->data == '+'){
                top = push(top,p_run->data);
                dequeue(root);
            }
            else
            {
               for(node* p_run1 = top;p_run1 != NULL;p_run1=p_run1->next){
                  printf("%c ",p_run1->data);
                  top = pop(top);
               }
               top = push(top,p_run->data);
               dequeue(root);
            }

        }    
    }
    if (top_show(top) == '+' || top_show(top) == 'x')
    {
        for(node* p_run1 = top;p_run1 != NULL;p_run1=p_run1->next){
        printf("%c ",p_run1->data);
        top = pop(top);
    }
    }
    
    
}
int main(){
    node* top = NULL;
    queue* root = (queue*)malloc(sizeof(queue));
    root->front = NULL; root->rear = NULL;
    i2pfix(top,root);
    // int n;
    // scanf("%d",&n);
    // int temp;
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d",&temp);
    //     top = push(top,temp);
    //     root = enqueue(root,temp);
    // }
    // printf("Show stacks \n");
    // display_st(top);
    // printf("Show queue \n");
    // display_qu(root);
    // printf("Lay ra 2 phan tu \n");
    // top = pop(top);
    // top = pop(top);
    // root = dequeue(root);
    // root = dequeue(root);
    // printf("Show stacks \n");
    // display_st(top);
    // printf("Show queue \n");
    // display_qu(root);
    // int a = top_show(top);
    // int b = show_rear(root);
    // printf("Gia tri phan tu stack dau tien %d",a); 
    // printf("Gia tri phan tu queu cuoi %d",b); 
    return 0;
}
