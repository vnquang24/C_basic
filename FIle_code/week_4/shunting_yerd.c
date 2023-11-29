#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* create_node(int x) {
    node* p = (node*)malloc(sizeof(node));
    p->data = x;
    p->next = NULL;
    return p;
}

node* push(node* top, int x) {
    node* p = create_node(x);
    if (top == NULL) {
        return p;
    }
    p->next = top;
    return p; 
}

node* pop(node* top) {
    if (top == NULL) {
        printf("Stack het phan tu");
        return NULL;
    }
    node* temp = top;
    top = top->next;
    free(temp);
    return top;
}

int top_show(node* top) {
    if (top == NULL) {
        printf("TOP NULL");
        return -1;
    }  
    return top->data;
}

void removeSpaces(char* str) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ') {
            str[count++] = str[i];
        }
    }
    str[count] = '\0';
}

int evaluateRPN(char* exp) {
    node* top = NULL;
    for (int i = 0; exp[i]; ++i) {
        if (exp[i] >= '0' && exp[i] <= '9') {
            top = push(top, exp[i] - '0');
        } else if (exp[i] == '+' || exp[i] == '*') {
            int val1 = top_show(top);
            top = pop(top);
            int val2 = top_show(top);
            top = pop(top);
            switch (exp[i]) {
                case '+': top = push(top, val2 + val1); break;
                case '*': top = push(top, val2 * val1); break;
            }
        }
    }
    return top_show(top);
}

int main() {
    char exp[1000];
    fgets(exp, 1000, stdin);
    removeSpaces(exp);
    printf("%d", evaluateRPN(exp));   
    return 0;
}