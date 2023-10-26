#include<stdio.h>
#include<stdlib.h>

typedef struct key
{
    int vl;
    struct key* next;
} node;

node* create_node(int a) {
    node* p = (node*)malloc(sizeof(node));
    p->vl = a;
    p->next = NULL;
    return p;
}

node* insert_tail(node* root, int a) {
    node* p = create_node(a);
    if (root == NULL) {
        return p;
    }
    node* p_run = NULL;
    for (p_run = root; p_run->next != NULL; p_run = p_run->next)
        ;
    p_run->next = p;
    return root;
}

node* printll(node* root) {
    node* p_run = root; // Sửa ở đây để tránh mất đi con trỏ root gốc
    int i = 0;
    while (p_run != NULL) {
        printf("LL[%d] = %d \n", i, p_run->vl);
        ++i;
        p_run = p_run->next;
    }
    return root;
}

int main() {
    int n, temp;
    node* root = NULL;
    printf("Enter n: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("A[%d] = ", i);
        scanf("%d", &temp);
        root = insert_tail(root, temp); // Cập nhật giá trị của con trỏ root
    }
    printll(root);
    return 0;
}
