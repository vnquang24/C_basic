#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

node* create_node(data){
    node* p = (node*)malloc(sizeof(node));
    p->data = data;
    p->next = NULL;
    return p;
}
node* ll_inserthead(node* root,int data){
    node* p = crate_node(data);
    if (root == NULL)
    {
        return p;
    }
    p->next = root;
    return p;
}
int main(){
    node* root = NULL;
    root = ll_inserthead(root,data);
    return 0;
}